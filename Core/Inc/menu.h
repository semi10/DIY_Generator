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
	Menu(MenuItem *menuItem, uint8_t itemCount);
	void drawMenu();
	virtual ~Menu();
	void down();
	void up();

private:
	MenuItem *menuItem;
	uint8_t itemCount;
	uint8_t activeItem = 0;

};

#endif /* MENU_H_ */
