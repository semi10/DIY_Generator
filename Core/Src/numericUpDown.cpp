/*
 * numericUpDown.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: fsemi
 */

#include "numericUpDown.h"

NumericUpDown::NumericUpDown(char* str, uint8_t x,  uint8_t y): MenuItem(str, x, y) {

}


void NumericUpDown::select()
{
	printf("From NumericUpDown\n");
}

NumericUpDown::~NumericUpDown() {
	// TODO Auto-generated destructor stub
}

