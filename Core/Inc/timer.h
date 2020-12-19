/*
 * timerMenuItem.h
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#ifndef TIMERMENUITEM_H_
#define TIMERMENUITEM_H_

#include "tim.h"

#define DUTY_CYCLE_MIN 		5
#define DUTY_CYCLE_MAX 		95
#define DUTY_CYCLE_DEFAULT 	50
#define DUTY_CYLCE_STEP 	5

#define FREQUENCY_MIN 	  	1
#define FREQUENCY_MAX  	  	99
#define FREQUENCY_DEFAULT	1
#define FREQUENCY_STEP 	  	1


enum MenuState { IDLE, FREQ_SEL, DUTY_SEL };
enum GeneratorState { DISABLED, ACTIVE };

struct TimerPreset
{
	uint16_t frequency;
	uint8_t dutyCycle;
	bool timerIsOn;
};

class Timer {
public:
	Timer(char labelStr, TIM_HandleTypeDef* htim, TimerPreset* timerPreset, void (*storePresetCallback)(void));
	TIM_HandleTypeDef* htim;
	TimerPreset* preset;
	char labelStr;
	char str[12];
	void select();
	void unselect();
	void left();
	void right();
	void toggle();
	void setState(GeneratorState generatorState);
	bool isIdle() { return (menuState == IDLE); }
	virtual ~Timer();
private:
	MenuState menuState = IDLE;
	uint16_t calcFrequency();
	uint8_t calcDutyCycle();
	void setFrequencyAndDC(uint16_t frequency);
	void setDutyCycle(uint8_t dutyCycle);
	void turn(bool timerIsOn);
	void (*storePreset)(void);
	void printFreqSel();
	void printDutySel();
	void printDefault();

};

#endif /* TIMERMENUITEM_H_ */
