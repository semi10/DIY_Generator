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

Joystick::Joystick() {
	// TODO Auto-generated constructor stub
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
				printf("Left\n");
				break;
			case BT_RIGHT:
				printf("Right\n");
				break;
			case BT_DOWN:
				printf("Down\n");
				break;
			case BT_UP:
				printf("Up\n");
				break;
			case BT_SELECT:
				printf("Select\n");
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
