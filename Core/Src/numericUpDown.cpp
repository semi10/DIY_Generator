/*
 * numericUpDown.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: fsemi
 */

#include "numericUpDown.h"


#include <string.h>

NumericUpDown::NumericUpDown(char* labelStr, uint8_t x,  uint8_t y, char* unitStr): MenuItem(str, x, y)
{
	strncpy(this->labelStr ,labelStr, sizeof(this->labelStr));
	strncpy(this->unitStr ,unitStr, sizeof(this->unitStr));
	updateStr();
}

Menu* NumericUpDown::select()
{
	selected ^= 1;
	updateStr();

	return this->parentMenu;
}

//void NumericUpDown::up()
//{
//	num++;
//	updateStr();
//}
//
//void NumericUpDown::down()
//{
//	num--;
//	updateStr();
//}

void NumericUpDown::updateStr()
{
	if (selected)
	{
		sprintf(str, "%s:<%03u%s>", labelStr, num, unitStr);
	}
	else
	{
		sprintf(str, "%s: %03u%s ", labelStr, num, unitStr);
	}
}

NumericUpDown::~NumericUpDown()
{
	// TODO Auto-generated destructor stub
}

