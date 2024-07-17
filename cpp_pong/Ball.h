#pragma once
#include "raylib.h"

class Ball {
public:
	float x;
	float y;
	int speed_x;
	int speed_y;
	int radius;

	Ball(int pos_x, int pos_y, int radius);
	
	void Draw();
	void Update();

};

