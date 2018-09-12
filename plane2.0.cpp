#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>

#include "plane2.0.h"
#include "Constant.h"
#include "status.h"


IMAGE  plane, plane_mask;
int plane_x;
int plane_y;




void plane_init() {

	//初始化 飞机图片
	loadimage(&plane, _T("plane.jpg"));
	loadimage(&plane_mask, _T("plane_mask.jpg"));

	


}

void plane_enter() {
	//初始化飞机的坐标
	plane_x = WINDOW_WIDTH / 2 - PLANE_WIDTH / 2;
	plane_y = WINDOW_HEIGHT / 2 - PLANE_HEIGHT / 2;

}
void plane_update(int dt) {
	//用键盘控制飞机移动
	controlByKeyboard();
}
void plane_render() {

	//画飞机
	putimage(plane_x, plane_y, &plane_mask, NOTSRCERASE);
	putimage(plane_x, plane_y, &plane, SRCERASE);
}
void controlByKeyboard() {
	// w s a d  控制飞机上下左右移动 q（Q）重新开始
	if (_kbhit())
	{
		int c = _getch();
		switch (c)
		{
		case 'w':
			plane_y -= PLANE_SPEED;
			break;
		case 'a':
			plane_x -= PLANE_SPEED;
			break;
		case 's':
			plane_y += PLANE_SPEED;
			break;
		case 'd':
			plane_x += PLANE_SPEED;
			break;
		case 'q':
			statusChange(EndStatus);
			break;
		case 'Q':
			statusChange(EndStatus);
			break;
		default:
			break;
		}

		//飞机与墙壁的碰撞检测
		if (plane_x >= 500 - PLANE_WIDTH) plane_x = 500 - PLANE_WIDTH;
		if (plane_x < 0) plane_x = 0;

		if (plane_y >= 500 - PLANE_HEIGHT) plane_y = 500 - PLANE_HEIGHT;
		if (plane_y < 0) plane_y = 0;

		
	}

}
//飞机与小球 碰撞检测
int isCollides(int x, int y) {
	if ((plane_x + 2) + (PLANE_WIDTH - 4) >= x && (plane_x + 2) <= x + R)
		if ((plane_y + 2) + (PLANE_HEIGHT - 4) >= y && (plane_y + 2) <= y + R)
			return 1;
	return 0;
}


int plane_collide(Ball ball[],int i) {
	
	return isCollides(ball[i].x, ball[i].y);

}

