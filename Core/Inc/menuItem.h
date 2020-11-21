/*
 * menuItem.h
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "stdint.h"


class MenuItem {
public:
	MenuItem(char* str, uint8_t x,  uint8_t y);
	char* str;
	uint8_t x , y;
	virtual ~MenuItem();
private:

};

#endif /* MENUITEM_H_ */
