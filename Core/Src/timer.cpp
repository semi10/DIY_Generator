/*
 * timerMenuItem.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: fsemi
 */

#include "timer.h"

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

Timer::Timer(char labelStr,  TIM_HandleTypeDef* htim, TimerPreset* timerPreset, void (*storePresetCallback)(void)){
	this->labelStr = labelStr;
	this->htim = htim;

	preset = timerPreset;

	storePreset = storePresetCallback;

	setFrequencyAndDC(preset->frequency);

	printDefault();
}

void Timer::select()
{
	switch (menuState)
	{
	case IDLE:
		menuState = FREQ_SEL;
		printFreqSel();
		break;
	case FREQ_SEL:
		menuState = DUTY_SEL;
		printDutySel();
		break;
	case DUTY_SEL:
	default:
		unselect();
		menuState = IDLE;
		printDefault();
	}
}

void Timer::unselect()
{
	menuState = IDLE;
	storePreset();
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
	switch (menuState)
	{
	case FREQ_SEL:
		preset->frequency -= FREQUENCY_STEP;
		setFrequencyAndDC(preset->frequency);
		printFreqSel();
		break;
	case DUTY_SEL:
		preset->dutyCycle -= DUTY_CYLCE_STEP;
		setDutyCycle(preset->dutyCycle);
		printDutySel();
		break;
	case IDLE:
	default:
		unselect();
	}
}

void Timer::right()
{
	switch (menuState)
	{
	case FREQ_SEL:
		preset->frequency += FREQUENCY_STEP;
		setFrequencyAndDC(preset->frequency);
		printFreqSel();
		break;
	case DUTY_SEL:
		preset->dutyCycle += DUTY_CYLCE_STEP;
		setDutyCycle(preset->dutyCycle);
		printDutySel();
		break;
	case IDLE:
		toggle();
		break;
	default:
		unselect();
	}
}

void Timer::setFrequencyAndDC(uint16_t frequency)
{
	preset->frequency = min(FREQUENCY_MAX, frequency);
	preset->frequency = max(FREQUENCY_MIN, frequency);


	htim->Init.Period = (BASE_CLK / (PRESCALER * preset->frequency)) - 1;
	setDutyCycle(preset->dutyCycle);

	HAL_TIM_PWM_DeInit(htim);
	HAL_TIM_PWM_Init(htim);

	turn(preset->timerIsOn);
}

void Timer::setDutyCycle(uint8_t dutyCycle)
{
	preset->dutyCycle = min(DUTY_CYCLE_MAX, dutyCycle);
	preset->dutyCycle = max(DUTY_CYCLE_MIN, dutyCycle);

	htim->Instance->CCR1 = (htim->Init.Period * (preset->dutyCycle / 100.0f));
}

void Timer::turn(bool timerIsOn)
{
	preset->timerIsOn = timerIsOn;

	if (timerIsOn)
	{
		HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
	}
	else
	{
		HAL_TIM_PWM_Stop(htim, TIM_CHANNEL_1);
	}

	printDefault();
}

void Timer::toggle()
{
	preset->timerIsOn ^= 1;
	turn(preset->timerIsOn);
	storePreset();
}

void Timer::setState(GeneratorState generatorState)
{
	if (generatorState == ACTIVE)
	{
		turn(preset->timerIsOn);
	}
	else
	{
		HAL_TIM_PWM_Stop(htim, TIM_CHANNEL_1);
	}
}


void Timer::printFreqSel()
{
	if (preset->frequency < 10) { sprintf(str, "%c <%uHz>%2u%% ", labelStr, preset->frequency, preset->dutyCycle); }
	else 				{ sprintf(str, "%c<%2uHz>%2u%% ", labelStr, preset->frequency, preset->dutyCycle); }
}

void Timer::printDutySel()
{
	if (preset->dutyCycle < 10)	 { sprintf(str, "%c %2uHz <%u%%>", labelStr, preset->frequency, preset->dutyCycle); }
	else				 { sprintf(str, "%c %2uHz<%2u%%>", labelStr, preset->frequency, preset->dutyCycle); }
}

void Timer::printDefault()
{
	if (preset->timerIsOn)
	{
		sprintf(str, "%c %2uHz %2u%% ", labelStr, preset->frequency, preset->dutyCycle);
	}
	else
	{
		sprintf(str, "%c %2uHz OFF ", labelStr, preset->frequency);
	}
}


Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

