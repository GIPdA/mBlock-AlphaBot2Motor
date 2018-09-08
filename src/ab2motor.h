#ifndef AB2MOTOR_H
#define AB2MOTOR_H

#include <Arduino.h>

class AB2Motor
{
public:
	AB2Motor();
	void begin();
	void drive(int motor, int direction, int speed);
};

#endif