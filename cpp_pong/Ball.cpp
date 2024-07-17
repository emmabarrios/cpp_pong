#include "Ball.h"

Ball::Ball(int pos_x, int pos_y, int radius, GameManager* gm) {
	this-> x = pos_x;
	this-> y = pos_y;
	this-> radius = radius;
	this-> diameter = radius * 2;
	this-> gm = gm;
}

void Ball::Draw(){
	DrawCircle(x, y, radius, WHITE);
}

void Ball::Update() {
	x += speed_x;
	y += speed_y;

	bool isBallAtEdge_y = (y + radius >= GetScreenHeight() || y - radius <= 0);
	bool isBallAtEdge_x = (x + radius >= GetScreenWidth() || x - radius <= 0);

	if (isBallAtEdge_y) {
		speed_y *= -1; // Reverse the speed
	}

	if (isBallAtEdge_x) {
		speed_x *= -1; // Reverse the speed

		if (x + radius >= GetScreenWidth()) {
			gm->cpu_score ++;
			//ResetBall();
		}

		if (x - radius <= 0) {
			gm->player_score++;
			//ResetBall();
		}
	}
}

void Ball::ResetBall() {
	x = GetScreenWidth()/2;
	y = GetScreenHeight()/2;

	int speed_shoices[2] = {-1, 1};
	speed_x *= speed_shoices[GetRandomValue(0,1)];
	speed_y *= speed_shoices[GetRandomValue(0,1)];
}
