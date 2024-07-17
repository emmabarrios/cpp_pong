#include "raylib.h"
#include <iostream>
#include "Ball.h"
#include "Paddle.h"



int main() {
	const int screen_width = 1200;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "CPP PONG");
	SetTargetFPS(60);

	Ball ball(screen_width/2,(screen_height/2), 20);
	ball.speed_x = 7;
	ball.speed_y = 7;

	Paddle player_paddle(screen_width - 35, (screen_height / 2) - 60, 25, 120);
	player_paddle.speed = 6;

	while (WindowShouldClose() == false){
		BeginDrawing();

		// Update calls
		ball.Update();
		player_paddle.Update();

		ClearBackground(BLACK);

		// Draw calls
		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		
		ball.Draw();
		player_paddle.Draw();

		DrawRectangle(10, (screen_height / 2) - 60 , 25, 120, WHITE);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}