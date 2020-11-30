/*
 * menu.h
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#ifndef MENU_H_
#define MENU_H_

#include "timer.h"

extern "C" {
#include "ssd1306.h"
#include "stdio.h"
}

class Menu {
public:
	Menu();
	void addTimer(Timer *timer);
	void drawMenu();
	void up();
	void down();
	virtual ~Menu();
	Timer *getActiveTimer() { return timer[activeTimer]; }
private:
	Timer *timer[3];
	uint8_t activeTimer = 0;
	uint8_t itemCount = 0;

};

#endif /* MENU_H_ */
