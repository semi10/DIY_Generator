/*
 * joystick.h
 *
 *  Created on: Nov 20, 2020
 *      Author: fsemi
 */

#ifndef SRC_JOYSTICK_H_
#define SRC_JOYSTICK_H_

#include "stdint.h"


class Joystick {
public:
	Joystick();
	void process(uint16_t JoystickInput);
	virtual ~Joystick();
};

#endif /* SRC_JOYSTICK_H_ */
