/*
 * timerMenuItem.h
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#ifndef TIMERMENUITEM_H_
#define TIMERMENUITEM_H_

#include "tim.h"

enum State { IDLE, FREQ_SEL, DUTY_SEL };

class Timer {
public:
	Timer(char labelStr, TIM_HandleTypeDef* htim);
	TIM_HandleTypeDef* htim;
	uint16_t frequency;
	uint8_t dutyCycle;
	char labelStr;
	char str[12];
	void select();
	void unselect();
	void left();
	void right();
	virtual ~Timer();
private:
	State timerState = IDLE;
	uint16_t calcFrequency();
	uint8_t calcDutyCycle();
	void setFrequency(uint16_t frequency);
	void setDutyCycle(uint8_t dutyCycle);
	void printFreqSel();
	void printDutySel();
	void printDefault();

};

#endif /* TIMERMENUITEM_H_ */
