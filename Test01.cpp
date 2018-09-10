#include "..\..\..\..\Desktop\PlaneBall\planeBall\plane.h"
#include "..\..\..\..\Desktop\PlaneBall\planeBall\plane.h"
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>


#include "Constant.h"
#include "screen.h"
#include "plane2.0.h"
#include "ball.h"


#define DELTA_TIME 1

Ball ball[LEN];


void startup() {
	
	screen_init();
	plane_init();

	ball_init();
	for (int i = 0; i < LEN; i++) {
		initBall(ball, i);

	}
	BeginBatchDraw();
}



void updateWithoutInput(int dt) {
	ball_update(ball,dt);
}

void updateWithInput() {
	plane_update();

}

void show() {

	screen_render();
	plane_render();

	ball_render(ball);


	FlushBatchDraw();

	Sleep(50);

}



void gameOver() {

	
}
int main() {
	srand((unsigned)time(NULL));
	startup();
	while (1)
	{
		show();  // ��ʾ����
		updateWithoutInput(DELTA_TIME);  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
	gameOver();     // ��Ϸ��������������
	return 0;

}

