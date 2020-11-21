/*
 * button.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: fsemi
 */

#include "button.h"

Button::Button(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	this->GPIOx = GPIOx;
	this->GPIO_Pin = GPIO_Pin;
}

bool Button::isPressed()
{
	bool buttonPressed = false;

	if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin))
	{
		if ((HAL_GetTick() - lastPressTime) > 300) // Debounce
		{
			buttonPressed = true;
			lastPressTime = HAL_GetTick();
		}
	}

	return buttonPressed;
}


Button::~Button() {
	// TODO Auto-generated destructor stub
}

