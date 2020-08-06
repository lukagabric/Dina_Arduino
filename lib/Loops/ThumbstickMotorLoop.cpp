#include "ThumbstickMotorLoop.h"
#include "Constants.h"
#include <Arduino.h>

ThumbstickMotorLoop::ThumbstickMotorLoop(): ThumbstickBaseLoop()
{
    _motorController = new LMotorController(ENA, IN1, IN2, ENB, IN3, IN4, AConst, BConst);
}

void ThumbstickMotorLoop::loopAtDefaultFrequency()
{
    ThumbstickBaseLoop::loopAtDefaultFrequency();

    _motorController->moveRaw(getLWS(), getRWS());
}
