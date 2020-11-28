/*
 * numericUpDown.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: fsemi
 */

#include "numericUpDown.h"


#include <string.h>

NumericUpDown::NumericUpDown(char* labelStr, uint8_t x,  uint8_t y, char* unitStr, uint8_t step): MenuItem(labelStr, x, y)
{
	this->step = step;
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


void NumericUpDown::up()
{
	selected = false;
	updateStr();
}

void NumericUpDown::down()
{
	selected = false;
	updateStr();
}


Menu* NumericUpDown::left()
{
	if (selected)
	{
		num -= step;
		updateStr();
		return parentMenu;
	}
	else
	{
		return parentMenu->back();
	}
}

void NumericUpDown::right()
{
	if (selected)
	{
		num += step;
		updateStr();
	}
}

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

