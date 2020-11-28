/*
 * timerMenuItem.h
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#ifndef TIMERMENUITEM_H_
#define TIMERMENUITEM_H_

#include "menuItem.h"
#include "numericUpDown.h"
#include "menu.h"

#include "tim.h"


class TimerMenuItem: public MenuItem {
public:
	TimerMenuItem(char* str, uint8_t x,  uint8_t y);
	Menu *select();
	Menu *left();
	void right();
	void up();
	void down();
	virtual ~TimerMenuItem();
private:
	Menu timerPresetMenu;
    NumericUpDown setFreqItem = NumericUpDown("f", 2, 0, "Hz");
    NumericUpDown setDCItem = NumericUpDown("D", 2, 18,"% ", 5);
};

#endif /* TIMERMENUITEM_H_ */
