/*
 * timerMenuItem.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#include "timer.h"

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

Timer::Timer(char labelStr,  TIM_HandleTypeDef* htim){
	this->labelStr = labelStr;
	this->htim = htim;

	frequency = calcFrequency();
	dutyCycle = calcDutyCycle();
	printDefault();
}

void Timer::select()
{
	switch (timerState)
	{
	case IDLE:
		timerState = FREQ_SEL;
		printFreqSel();
		break;
	case FREQ_SEL:
		timerState = DUTY_SEL;
		printDutySel();
		break;
	case DUTY_SEL:
	default:
		unselect();
		timerState = IDLE;
		printDefault();
	}
}

void Timer::unselect()
{
	timerState = IDLE;
	printDefault();
}


uint16_t Timer::calcFrequency()
{
	return (BASE_CLK / (PRESCALER * htim->Init.Period));
}

uint8_t Timer::calcDutyCycle()
{
	return uint8_t((htim->Instance->CCR1 / (float)htim->Init.Period) * 100);
}

void Timer::left()
{
	switch (timerState)
	{
	case FREQ_SEL:
		frequency = max(1, frequency - 1);
		setFrequency(frequency);
		printFreqSel();
		break;
	case DUTY_SEL:
		dutyCycle = max(5, dutyCycle - 5);
		setDutyCycle(dutyCycle);
		printDutySel();
		break;
	case IDLE:
	default:
		unselect();
	}
}

void Timer::right()
{
	switch (timerState)
	{
	case FREQ_SEL:
		frequency = min(99, frequency + 1);
		setFrequency(frequency);
		printFreqSel();
		break;
	case DUTY_SEL:
		dutyCycle = min(95, dutyCycle + 5);
		setDutyCycle(dutyCycle);
		printDutySel();
		break;
	case IDLE:
	default:
		unselect();
	}
}

void Timer::setFrequency(uint16_t frequency)
{
	htim->Init.Period = (BASE_CLK / (PRESCALER * frequency)) - 1;
	setDutyCycle(dutyCycle);

	HAL_TIM_PWM_DeInit(htim);
	HAL_TIM_PWM_Init(htim);
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
}

void Timer::setDutyCycle(uint8_t dutyCycle)
{
	htim->Instance->CCR1 = (htim->Init.Period * (dutyCycle / 100.0f));
}

void Timer::printFreqSel()
{
	if (frequency < 10) { sprintf(str, "%c <%uHz>%2u%% ", labelStr, frequency, dutyCycle); }
	else 				{ sprintf(str, "%c<%2uHz>%2u%% ", labelStr, frequency, dutyCycle); }
}

void Timer::printDutySel()
{
	if (dutyCycle < 10)	 { sprintf(str, "%c %2uHz <%u%%>", labelStr, frequency, dutyCycle); }
	else				 { sprintf(str, "%c %2uHz<%2u%%>", labelStr, frequency, dutyCycle); }
}

void Timer::printDefault()
{
	sprintf(str, "%c %2uHz %2u%% ", labelStr, frequency, dutyCycle);
}


Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

