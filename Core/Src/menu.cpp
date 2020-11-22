/*
 * menu.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "menu.h"

Menu::Menu()
{

}


void Menu::addMenuItem(MenuItem *newMenuItem)
{
	menuItem[itemCount] = newMenuItem;
	itemCount++;
}


void Menu::drawMenu()
{
	for (int i = 0; i < itemCount; i++)
	{
	  SSD1306_COLOR itemColor = (i == activeItem) ? Black : White;

	  ssd1306_SetCursor(menuItem[i]->x, menuItem[i]->y);
	  ssd1306_WriteString(menuItem[i]->str, Font_11x18, itemColor);
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

void Menu::select()
{
	(menuItem[activeItem])->select();
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

