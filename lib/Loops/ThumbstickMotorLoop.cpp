#include "ThumbstickMotorLoop.h"
#include "Constants.h"
#include <Arduino.h>

ThumbstickMotorLoop::ThumbstickMotorLoop(): ThumbstickLoop()
{
    _motorController = new LMotorController(ENA, IN1, IN2, ENB, IN3, IN4, AConst, BConst);
}

void ThumbstickMotorLoop::loopAtDefaultFrequency()
{
    ThumbstickLoop::loopAtDefaultFrequency();

    _motorController->moveRaw(getLWS(), getRWS());
}
