#include "Ball.h"

Ball::Ball(int pos_x, int pos_y, int radius) {
	this-> x = pos_x;
	this-> y = pos_y;
	this-> radius = radius;
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
	}
}
