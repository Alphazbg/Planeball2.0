#pragma once
#include "ball.h"

void plane_init();
void plane_enter();
void plane_update(int dt);
void plane_render();

void controlByKeyboard();

int isCollides(int x, int y);

int plane_collide(Ball ball[],int i);

//void plane_score(Ball ball[]);

//bool flag = true;