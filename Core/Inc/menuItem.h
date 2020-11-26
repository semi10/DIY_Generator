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

class MenuItem {
public:
	MenuItem(char* str, uint8_t x,  uint8_t y);
	char* str;
	virtual void select() = 0;
	uint8_t x , y;
	virtual ~MenuItem();
private:

};

#endif /* MENUITEM_H_ */
