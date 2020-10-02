#ifndef __MENU_MAIN_H
#define __MENU_MAIN_H

#include "M5StickC.h"

float menu_map(float a, float aMax, float aMin, float bMax, float bMin);
void menu_select(int f,bool flag);
void menu_setup();
void menu_loop(void(*fuc1)(),char str1[],void(*fuc2)(),char str2[],void(*fuc3)(),char str3[],void(*fuc4)(),char str4[]);

#endif
