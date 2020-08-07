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

void LLEDMotorMockController::actuate(int leftWheelSpeed, int rightWheelSpeed)
{
	if (leftWheelSpeed >= 0)
    {
        analogWrite(_leftGreen, leftWheelSpeed);
        analogWrite(_leftBlue, 0);
    } 
    else
    {
        analogWrite(_leftGreen, 0);
        analogWrite(_leftBlue, -1*leftWheelSpeed);
    }

    if (rightWheelSpeed >= 0)
    {
        analogWrite(_rightGreen, rightWheelSpeed);
        analogWrite(_rightBlue, 0);
    } 
    else
    {
        analogWrite(_rightGreen, 0);
        analogWrite(_rightBlue, -1*rightWheelSpeed);
    }
}
