#include "CpuPaddle.h"

CpuPaddle::CpuPaddle(float pos_x, float pos_y, float width, float height): Paddle(pos_x, pos_y, width, height) {
	this->x = pos_x;
	this->y = pos_y;
	this->width = width;
	this->height = height;
}

void CpuPaddle::Update(int ball_y) {
	if (y + height/2 > ball_y) {
		y -= speed;
	}
	if (y + height / 2 <= ball_y) {
		y += speed;
	}

	LimitMovement();
}
