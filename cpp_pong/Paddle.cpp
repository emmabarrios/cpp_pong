#include "Paddle.h"

Paddle::Paddle(float pos_x, float pos_y, float width, float height) {
	this->x = pos_x;
	this->y = pos_y;
	this->width = width;
	this->height = height;
}

void Paddle::Draw() {
	DrawRectangle(x, y,width, height, WHITE);
}

void Paddle::Update() {
	if (IsKeyDown(KEY_UP)) {
		y -= speed;
	}
	if (IsKeyDown(KEY_DOWN)) {
		y += speed;
	}

	if (y <= 0) {
		y = 0;
	}

	if (y + height >=  GetScreenHeight()) {
		y = GetScreenHeight() - height;
	}
}
