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


void Menu::addTimer(Timer *timer)
{
	this->timer[itemCount++] = timer;
}


void Menu::drawMenu()
{
	ssd1306_Fill(Black);
	for (int i = 0; i < itemCount; i++)
	{
	  SSD1306_COLOR itemColor = (i == activeTimer) ? Black : White;

	  ssd1306_SetCursor(0, i * 18);
	  ssd1306_WriteString(timer[i]->str, Font_11x18, itemColor);
	}

	ssd1306_UpdateScreen();
}

void Menu::down()
{
	timer[activeTimer]->unselect();
	activeTimer = (activeTimer + 1) % itemCount;

}


void Menu::up()
{
	timer[activeTimer]->unselect();
	activeTimer = (activeTimer > 0) ? --activeTimer : (itemCount - 1);
}


Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

