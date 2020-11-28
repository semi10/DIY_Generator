/*
 * timerMenuItem.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#include "timerMenuItem.h"


TimerMenuItem::TimerMenuItem(char* str, uint8_t x,  uint8_t y): MenuItem(str, x, y) {
	  timerPresetMenu.parentMenu = this->parentMenu;
	  timerPresetMenu.addMenuItem(&setFreqItem);
	  timerPresetMenu.addMenuItem(&setDCItem);
}

Menu* TimerMenuItem::select()
{
	printf("From TimerMenuItem\n");
	return &timerPresetMenu;
}

Menu* TimerMenuItem::left()
{
	return parentMenu->back();
}

void TimerMenuItem::right()
{
	printf("TimerMenuItem Right\n");
}

void TimerMenuItem::up()
{
	printf("TimerMenuItem Up\n");
}

void TimerMenuItem::down()
{
	printf("TimerMenuItem Down\n");
}



TimerMenuItem::~TimerMenuItem()
{
	// TODO Auto-generated destructor stub
}

