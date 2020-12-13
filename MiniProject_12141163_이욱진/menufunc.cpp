#pragma once
#include "mini.h"
extern int light_mode;
//메뉴는 게임모드와 기본 조립모드 2가지.
void sub_menu_function(int option)
{
	printf("Submenu %d has been selected\n", option);
	switch (option)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	default:
		break;
	}
}

void sub_menu_function2(int option)
{
	printf("Submenu2 %d has been selected\n", option);
	switch (option)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}

void sub_menu_function3(int option)
{
	resize(500, 500);
}

void sub_menu_function4(int option)
{
	light_mode = option;
}

void main_menu_function(int option)
{
	printf("Main menu %d has been selected\n", option);
	if (option == 999)
		exit(0);
	else if (option == 22)
		resize(500, 500);
}