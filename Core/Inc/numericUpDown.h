/*
 * numericUpDown.h
 *
 *  Created on: Nov 26, 2020
 *      Author: fsemi
 */

#ifndef NUMERICUPDOWN_H_
#define NUMERICUPDOWN_H_

#include <menuItem.h>
#include "menu.h"

class NumericUpDown: public MenuItem {
public:
	NumericUpDown(char* str, uint8_t x,  uint8_t y);
	Menu* select();
	virtual ~NumericUpDown();
};

#endif /* NUMERICUPDOWN_H_ */
