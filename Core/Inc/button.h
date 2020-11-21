/*
 * button.h
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#ifndef BUTTON_H_
#define BUTTON_H_

extern "C"
{
#include "gpio.h"
}

class Button {
public:
	Button(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
	bool isPressed();
	virtual ~Button();
private:
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;

	uint32_t lastPressTime = 0;
};

#endif /* BUTTON_H_ */
