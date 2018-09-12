#pragma once
#include "Constant.h"

struct Ball {
	int x;
	int y;
	int V_x;
	int V_y;
};



void initBall(Ball ball[],int i);

void ball_init();
void ball_enter();
void ball_update(Ball ball[], int dt);
void ball_render(Ball ball[]);
