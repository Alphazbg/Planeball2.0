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
#include "status.h"


#define DELTA_TIME 1

#pragma comment(lib,"winmm.lib")

void a_sleep(DWORD ms);


void startup()
{
	
	screen_init();
	score_enter(DELTA_TIME);
}

void updateWithoutInput(int dt)
{

	switch (currentStatus()) {
	case TitleStatus:
		title_update(dt);
		
		break;

	case CountStatus:
		count_update(dt);
		break;
	case PlayStatus:
		

		play_update(dt);
		

		break;
	case ScoreStatus:
		
		score_update(dt);
		//score++;
		break;
	case EndStatus:
		screen_init();
		statusChange(TitleStatus);
		break;
	}


}
void updateWithInput()
{
	
}

void show()
{
	screen_render();

	switch (currentStatus()) {
	case 0:
		title_render();
		break;
	case 1:
		count_render();
		break;
	case 2:
		play_render();
		break;

	case 3:
		score_render();
		break;
	}
	FlushBatchDraw();

	a_sleep(60);

}

void gameover()
{
	EndBatchDraw();
}

void a_sleep(DWORD ms)
{
	static clock_t oldclock = clock();		// 静态变量，记录上一次 tick

	oldclock += ms * CLOCKS_PER_SEC / 1000;	// 更新 tick

	if (clock() > oldclock)					// 如果已经超时，无需延时
		oldclock = clock();
	else
		while (clock() < oldclock)			// 延时
			Sleep(1);						// 释放 CPU 控制权，降低 CPU 占用率
}




int main() {
	srand((unsigned)time(NULL));
	startup();
	while (1)
	{
		show();  // 显示画面
		updateWithoutInput(DELTA_TIME); // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
	gameover();     // 游戏结束、后续处理
	return 0;

}

