#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>

#include "Constant.h"
#include "ball.h"

//Ball ball[LEN];

void ball_init() {
	

	setlinecolor(YELLOW);
	setfillcolor(RED);
	
	
	

}
void initBall(Ball ball[], int i) {
	

	ball[i].x = 20;
	ball[i].y = 20;
	ball[i].V_x = 1 + rand() % 5;
	ball[i].V_y = 2 + rand() % 8;
	
	
}


void ball_update(Ball ball[],int dt) {
	for (int i = 0; i < LEN; i++) {
		ball[i].x += ball[i].V_x;
		ball[i].y += ball[i].V_y;

	if (ball[i].x + R >= 500 || ball[i].x < R) ball[i].V_x = -ball[i].V_x;

	if( ball[i].y + R >= 500 || ball[i].y < R) ball[i].V_y = -ball[i].V_y;

	}
	
	

}

void ball_render(Ball ball[]) {

	setlinecolor(YELLOW);
	setfillcolor(RED);
	Sleep(20);
	for (int i = 0; i < LEN; i++)
	{
		
		fillcircle(ball[i].x, ball[i].y, R);
		

	}
	
}



