#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>

#include "Constant.h"
#include "screen.h"
#include "status.h"

IMAGE background;
int score;

void screen_init() {
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&background, _T("background.jpg"));

	play_init();
	

	statusChange(TitleStatus);


	BeginBatchDraw();

}

void screen_render() {

	putimage(0, 0, &background);
}