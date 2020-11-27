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
#include "stdint-gcc.h"

class NumericUpDown: public MenuItem {
public:
	NumericUpDown(char* labelStr, uint8_t x,  uint8_t y, char* unitStr);
	Menu* select();
	virtual ~NumericUpDown();
private:
	bool selected = false;
	char labelStr[2];
	uint16_t num = 0;
	char unitStr[3];
	void updateStr();
};

#endif /* NUMERICUPDOWN_H_ */
