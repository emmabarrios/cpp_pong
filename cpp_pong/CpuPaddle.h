#pragma once
#include "Paddle.h"

class CpuPaddle : public Paddle {
public:

	CpuPaddle(float pos_x, float pos_y, float width, float height);
	void Update(int ball_y);
};

