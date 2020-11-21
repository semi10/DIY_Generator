/*
 * menuItem.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "menuItem.h"

MenuItem::MenuItem(char* str, uint8_t x,  uint8_t y) {
	this->str = str;
	this->x = x;
	this->y = y;
}

MenuItem::~MenuItem() {
	// TODO Auto-generated destructor stub
}

