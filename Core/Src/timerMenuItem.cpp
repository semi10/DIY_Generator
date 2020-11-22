/*
 * timerMenuItem.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#include "timerMenuItem.h"

TimerMenuItem::TimerMenuItem(char* str, uint8_t x,  uint8_t y): MenuItem(str, x, y) {
	// TODO Auto-generated constructor stub
}

void TimerMenuItem::select()
{
	printf("From TimerMenuItem\n");
}

TimerMenuItem::~TimerMenuItem() {
	// TODO Auto-generated destructor stub
}

