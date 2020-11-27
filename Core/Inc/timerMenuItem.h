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

class TimerMenuItem: public MenuItem {
public:
	TimerMenuItem(char* str, uint8_t x,  uint8_t y);
	Menu *select();
	virtual ~TimerMenuItem();
private:
	Menu timerPresetMenu;
    NumericUpDown setFreqItem = NumericUpDown("f: <10Hz>", 2, 0 );
    NumericUpDown setDCItem = NumericUpDown("D: <95%>", 2, 18);
};

#endif /* TIMERMENUITEM_H_ */
