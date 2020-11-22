/*
 * menu.h
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#ifndef MENU_H_
#define MENU_H_

#include "menuItem.h"
#include "timerMenuItem.h"

extern "C" {
#include "ssd1306.h"
#include "stdio.h"
}

class Menu {
public:
	Menu();
	void addMenuItem(MenuItem *newMenuItem);
	void drawMenu();
	virtual ~Menu();
	void down();
	void up();
	void select();

private:
	MenuItem *menuItem[3];
	uint8_t itemCount = 0;
	uint8_t activeItem = 0;

};

#endif /* MENU_H_ */
