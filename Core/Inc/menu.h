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
	Menu(MenuItem *menuItem);
	void drawMenu();
	virtual ~Menu();
private:
	MenuItem *menuItem;

};

#endif /* MENU_H_ */
