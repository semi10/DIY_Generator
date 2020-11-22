/*
 * menuItem.h
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

extern "C"
{
#include "stdio.h"
}

class Menu;

class MenuItem {
public:
	MenuItem(char* str, uint8_t x,  uint8_t y);
	char* str;
	uint8_t x , y;
	virtual void select();
	Menu *parentMenu;
	virtual ~MenuItem();
private:

};

#endif /* MENUITEM_H_ */
