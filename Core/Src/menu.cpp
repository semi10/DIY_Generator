/*
 * menu.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "menu.h"

Menu::Menu(MenuItem *menuItem) {
	// TODO Auto-generated constructor stub
	this->menuItem = menuItem;
}

void Menu::drawMenu()
{
	  ssd1306_SetCursor(menuItem->x, menuItem->y);
	  ssd1306_WriteString(menuItem->str, Font_11x18, White);
	  ssd1306_UpdateScreen();
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

