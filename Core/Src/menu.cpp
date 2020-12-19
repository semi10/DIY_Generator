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

	if (generatorState == ACTIVE)
	{
		for (int i = 0; i < itemCount; i++)
		{
		  SSD1306_COLOR itemColor = (i == activeTimer) ? Black : White;

		  ssd1306_SetCursor(0, i * 15);
		  ssd1306_WriteString(timer[i]->str, Font_11x18, itemColor);
		}
	}
	else
	{
		ssd1306_SetCursor(0, 20);
		ssd1306_WriteString("STANDBY", Font_16x26, White);
	}

	ssd1306_UpdateScreen();
}

void Menu::down()
{
	if (generatorState == DISABLED) return;

	getActiveTimer()->unselect();
	activeTimer = (activeTimer + 1) % itemCount;
}


void Menu::up()
{
	if (generatorState == DISABLED) return;

	getActiveTimer()->unselect();
	activeTimer = (activeTimer > 0) ? --activeTimer : (itemCount - 1);
}

void Menu::right()
{
	if (generatorState == DISABLED) return;

	getActiveTimer()->right();
}

void Menu::left()
{
	if (isActiveTimerIdle())
	{
		toggleGeneratorState();
	}
	else
	{
		getActiveTimer()->left();
	}
}

void Menu::select()
{
	if (generatorState == DISABLED) return;

	getActiveTimer()->select();
}

void Menu::toggleGeneratorState()
{
	generatorState = (generatorState == ACTIVE) ? DISABLED : ACTIVE;

	for (int i = 0; i < MAX_TIMER_NUMB; i++)
	{
		timer[i]->setState(generatorState);
	}
}


bool Menu::isActiveTimerIdle()
{
	return getActiveTimer()->isIdle();
}




Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

