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

TimerMenuItem::~TimerMenuItem() {
	// TODO Auto-generated destructor stub
}

