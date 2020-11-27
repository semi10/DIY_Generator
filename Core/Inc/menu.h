/*
 * menu.h
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#ifndef MENU_H_
#define MENU_H_

#include "menuItem.h"

extern "C" {
#include "ssd1306.h"
#include "stdio.h"
}

class Menu {
public:
	Menu(Menu *parentMenu = NULL);
	void addMenuItem(MenuItem *newMenuItem);
	void drawMenu();
	virtual ~Menu();
	Menu *up();
	Menu *down();
	Menu *left();
	Menu *right();
	Menu *select();
	Menu *parentMenu;
protected:
	Menu *activeMenuPointer;
	MenuItem *menuItem[3];
	uint8_t itemCount = 0;
	uint8_t activeItem = 0;

};

#endif /* MENU_H_ */
