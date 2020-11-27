/*
 * menu.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "menu.h"

Menu::Menu(Menu *parentMenu)
{
	this->parentMenu = parentMenu;
}


void Menu::addMenuItem(MenuItem *newMenuItem)
{
	newMenuItem->parentMenu = this;
	menuItem[itemCount++] = newMenuItem;
}


void Menu::drawMenu()
{
	ssd1306_Fill(Black);
	for (int i = 0; i < itemCount; i++)
	{
	  SSD1306_COLOR itemColor = (i == activeItem) ? Black : White;

	  ssd1306_SetCursor(menuItem[i]->x, menuItem[i]->y);
	  ssd1306_WriteString(menuItem[i]->str, Font_11x18, itemColor);
	}

	activeMenuPointer = this;
	ssd1306_UpdateScreen();
}

Menu *Menu::down()
{
	activeItem = (activeItem + 1) % itemCount;
	return this;
}


Menu *Menu::up()
{
	activeItem = (activeItem > 0) ? --activeItem : (itemCount - 1);
	return this;
}

Menu *Menu::left()
{
	if (parentMenu) return parentMenu;
	else return this;
}

Menu *Menu::right()
{
	return this;
}

Menu *Menu::select()
{
	return menuItem[activeItem]->select();
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

