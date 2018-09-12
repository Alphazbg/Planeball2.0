#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>

#include "Constant.h"
#include "ball.h"
#include "plane2.0.h"
#include "status.h"

Ball ball[LEN];
void ball_init() {
	
	//圆的黄线和 红色填充
	setlinecolor(YELLOW);
	setfillcolor(RED);
	
	
	

}
//初始化小球
void ball_enter() {
	for (int i = 0; i < LEN; i++) {
		initBall(ball, i);

	}

}
//初始化小球的坐标 速度
void initBall(Ball ball[], int i) {
	

	ball[i].x = 20 + i * 50;
	ball[i].y = 20;
	ball[i].V_x = 1 + rand() % 5;
	ball[i].V_y = 2 + rand() % 8;
	
	
}

//小球 的无规则运动
void ball_update(Ball ball[],int dt) {
	for (int i = 0; i < LEN; i++) {
		ball[i].x += ball[i].V_x;
		ball[i].y += ball[i].V_y;

		//碰撞检测 碰到墙壁反弹
	if (ball[i].x + R >= 500 || ball[i].x < R) ball[i].V_x = -ball[i].V_x;

	if( ball[i].y + R >= 500 || ball[i].y < R) ball[i].V_y = -ball[i].V_y;
		score++;
	}
	for (int i = 0; i < LEN; i++) {
		if (plane_collide(ball, i)) {
			
			statusChange(ScoreStatus);
		}
	}
	
	

}

void ball_render(Ball ball[]) {
	//画小球
	setlinecolor(YELLOW);
	setfillcolor(RED);
	Sleep(20);
	for (int i = 0; i < LEN; i++)
	{
		//小球
		fillcircle(ball[i].x, ball[i].y, R);
		

	}
	
}



