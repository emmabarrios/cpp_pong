#include "raylib.h"
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"



int main() {
	const int screen_width = 1200;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "CPP PONG");
	SetTargetFPS(60);

	GameManager gm;

	Ball ball(screen_width/2,(screen_height/2), 20, &gm);
	ball.speed_x = 6;
	ball.speed_y = 6;

	Paddle player_paddle(screen_width - 35, (screen_height / 2) - 60, 25, 120);
	player_paddle.speed = 6;

	CpuPaddle cpu_paddle(10, (screen_height / 2) - 60, 25, 120);
	cpu_paddle.speed = 6;

	while (WindowShouldClose() == false){
		BeginDrawing();

		// Update calls
		ball.Update();
		player_paddle.Update();
		cpu_paddle.Update(ball.y);

		// Check for collisions
		if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player_paddle.x, player_paddle.y, player_paddle.width, player_paddle.height})) {

			// Ball edges
			float ballRight = ball.x + ball.radius;
			float ballTop = ball.y - ball.radius;
			float ballBottom = ball.y + ball.radius;

			// Paddle edges
			float paddleLeft = player_paddle.x;
			float paddleTop = player_paddle.y;
			float paddleBottom = player_paddle.y + player_paddle.height;

			if (ballBottom >= paddleTop && ballTop < paddleTop) {
				ball.speed_y *= -1;
				ball.y = paddleTop - ball.radius;
			}
			else if (ballTop <= paddleBottom && ballBottom > paddleBottom) {
				ball.speed_y *= -1;
				ball.y = paddleBottom + ball.radius;
			}
			else if (ballRight >= paddleLeft) {
				ball.speed_x *= -1;
				ball.x = paddleLeft - ball.radius;
			}

		}
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{cpu_paddle.x, cpu_paddle.y, cpu_paddle.width, cpu_paddle.height })) {
			
			// Ball edges
			float ballLeft = ball.x - ball.radius;
			float ballRight = ball.x + ball.radius;
			float ballTop = ball.y - ball.radius;
			float ballBottom = ball.y + ball.radius;

			// Paddle edges
			float paddleLeft = cpu_paddle.x;
			float paddleRight = cpu_paddle.x + cpu_paddle.width;
			float paddleTop = cpu_paddle.y;
			float paddleBottom = cpu_paddle.y + cpu_paddle.height;

			if (ballBottom >= paddleTop && ballTop < paddleTop) {
				ball.speed_y *= -1;
				ball.y = paddleTop - ball.radius;
			}
			else if (ballTop <= paddleBottom && ballBottom > paddleBottom) {
				ball.speed_y *= -1;
				ball.y = paddleBottom + ball.radius;
			}
			else if (ballLeft <= paddleRight) {
				ball.speed_x *= -1;
				ball.x = paddleRight + ball.radius;
			}
		}

		// Draw calls
		ClearBackground(BLACK);
		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		ball.Draw();
		player_paddle.Draw();
		cpu_paddle.Draw();
		DrawText(TextFormat("%i",gm.cpu_score), screen_width/4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i",gm.player_score), 3 * screen_width/4 - 20, 20, 80, WHITE);


		EndDrawing();
	}

	CloseWindow();
	return 0;
}