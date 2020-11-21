/*
 * menu.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "menu.h"

Menu::Menu(MenuItem *menuItem, uint8_t itemCount) {
	// TODO Auto-generated constructor stub
	this->menuItem = menuItem;
	this->itemCount = itemCount;
}

void Menu::drawMenu()
{
	for (int i = 0; i < itemCount; i++)
	{
	  SSD1306_COLOR itemColor = (i == activeItem) ? Black : White;

	  ssd1306_SetCursor(menuItem[i].x, menuItem[i].y);
	  ssd1306_WriteString(menuItem[i].str, Font_11x18, itemColor);
	}

	ssd1306_UpdateScreen();
}

void Menu::down()
{
	activeItem = (activeItem + 1) % itemCount;

	drawMenu();
}


void Menu::up()
{
	activeItem = (activeItem > 0) ? --activeItem : (itemCount - 1);

	drawMenu();
}


Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

