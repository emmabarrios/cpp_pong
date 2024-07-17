#pragma once
#include "raylib.h"
#include "GameManager.h"


class Ball {
public:
	float x;
	float y;
	int speed_x;
	int speed_y;
	int radius;
	int diameter;
	GameManager* gm;

	Ball(int pos_x, int pos_y, int radius, GameManager* gm);
	
	void Draw();
	void Update();
	void ResetBall();

};

