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
	NumericUpDown(char* labelStr, uint8_t x,  uint8_t y, char* unitStr, uint8_t step = 1);
	Menu* select();
	Menu *left();
	void right();
	void up();
	void down();
	virtual ~NumericUpDown();
private:
	uint8_t step;
	bool selected = false;
	char labelStr[2];
	uint16_t num = 0;
	char unitStr[3];
	void updateStr();
};

#endif /* NUMERICUPDOWN_H_ */
