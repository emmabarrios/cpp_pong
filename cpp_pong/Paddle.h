#pragma once
#include "raylib.h"

class Paddle {
public:
	float x;
	float y;
	float speed;
	float width;
	float height;

	Paddle(float pos_x, float pos_y, float width, float height);
	void Draw();
	void Update();
};

