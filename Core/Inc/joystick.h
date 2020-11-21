/*
 * joystick.h
 *
 *  Created on: Nov 20, 2020
 *      Author: fsemi
 */

#ifndef SRC_JOYSTICK_H_
#define SRC_JOYSTICK_H_

#include "stdint.h"
#include "button.h"

#define JOYSTICK_BUTTONS_NUM 5

class Joystick {
public:
	Joystick();
	void poll();
	virtual ~Joystick();

private:
	Button button[JOYSTICK_BUTTONS_NUM] = {
			Button(JoystickLeft_GPIO_Port, JoystickLeft_Pin),
			Button(JoystickRight_GPIO_Port, JoystickRight_Pin),
			Button(JoystickDown_GPIO_Port, JoystickDown_Pin),
			Button(JoystickUp_GPIO_Port, JoystickUp_Pin),
			Button(JoystickSelect_GPIO_Port, JoystickSelect_Pin)
	};
};

#endif /* SRC_JOYSTICK_H_ */
