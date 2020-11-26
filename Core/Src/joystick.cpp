/*
 * Joystick.cpp
 *
 *  Created on: Nov 20, 2020
 *      Author: fsemi
 */

#include <joystick.h>

extern "C"
{
#include "stdio.h"
#include "gpio.h"
}

enum joystickButton { BT_LEFT, BT_RIGHT, BT_DOWN, BT_UP, BT_SELECT };

Joystick::Joystick(Menu *activeMenu) {
	this->activeMenu = activeMenu;
}

void Joystick::poll()
{
	for (int i = 0; i < JOYSTICK_BUTTONS_NUM; i++)
	{
		if (button[i].isPressed())
		{
			switch (i)
			{
			case BT_LEFT:
				activeMenu = activeMenu->left();
				break;
			case BT_RIGHT:
				activeMenu = activeMenu->right();
				break;
			case BT_DOWN:
				activeMenu = activeMenu->down();
				break;
			case BT_UP:
				activeMenu = activeMenu->up();
				break;
			case BT_SELECT:
				activeMenu = activeMenu->select();
				break;
			default:
				printf("Unknown button\n");
			}
		}
	}
}

Joystick::~Joystick() {
	// TODO Auto-generated destructor stub
}
