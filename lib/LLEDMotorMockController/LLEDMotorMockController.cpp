#include "LLEDMotorMockController.h"
#include <Arduino.h>

LLEDMotorMockController::LLEDMotorMockController(int leftGreen, int leftBlue, int rightGreen, int rightBlue)
{
	_leftGreen = leftGreen;
	_leftBlue = leftBlue;
	_rightGreen = rightGreen;
	_rightBlue = rightBlue;

    pinMode(_leftGreen, OUTPUT);
    pinMode(_leftBlue, OUTPUT);
    pinMode(_rightGreen, OUTPUT);
    pinMode(_rightBlue, OUTPUT);
}

void LLEDMotorMockController::light(int leftSpeed, int rightSpeed)
{
	if (leftSpeed >= 0)
    {
        analogWrite(_leftGreen, leftSpeed);
        analogWrite(_leftBlue, 0);
    } 
    else
    {
        analogWrite(_leftGreen, 0);
        analogWrite(_leftBlue, -1*leftSpeed);
    }

    if (rightSpeed >= 0)
    {
        analogWrite(_rightGreen, rightSpeed);
        analogWrite(_rightBlue, 0);
    } 
    else
    {
        analogWrite(_rightGreen, 0);
        analogWrite(_rightBlue, -1*rightSpeed);
    }
}
