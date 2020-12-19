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

#define MAX_TIMER_NUMB 4
#define START_PAGE_ADDR 0x0801FC00L

class Menu {
public:
	Menu();
	void addTimer(Timer *timer);
	void drawMenu();
	void up();
	void down();
	void right();
	void left();
	void select();
	virtual ~Menu();
	Timer *getActiveTimer() { return timer[activeTimer]; }
	bool isActiveTimerIdle();
private:
	Timer *timer[MAX_TIMER_NUMB];
	uint8_t activeTimer = 0;
	uint8_t itemCount = 0;
	GeneratorState generatorState = ACTIVE;
	void toggleGeneratorState();
};

#endif /* MENU_H_ */
