/*
 * timerMenuItem.h
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#ifndef TIMERMENUITEM_H_
#define TIMERMENUITEM_H_

#include <menuItem.h>

class TimerMenuItem: public MenuItem {
public:
	TimerMenuItem(char* str, uint8_t x,  uint8_t y);
	void select();
	virtual ~TimerMenuItem();
};

#endif /* TIMERMENUITEM_H_ */
