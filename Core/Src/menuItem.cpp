/*
 * menuItem.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "menuItem.h"

extern "C"
{
#include "stdio.h"
#include "string.h"
}


MenuItem::MenuItem(char* str, uint8_t x,  uint8_t y) {

	strncpy(this->str, str, 12);
	this->x = x;
	this->y = y;
}


//Menu* MenuItem::up()
//{
//	return parentMenu;
//}
//
//Menu* MenuItem::down()
//{
//	return parentMenu;
//}

MenuItem::~MenuItem() {
	// TODO Auto-generated destructor stub
}

