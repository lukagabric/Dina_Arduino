#include "LinePathMotorLoop.h"
#include "Constants.h"
#include <Arduino.h>

LinePathMotorLoop::LinePathMotorLoop(): LinePathBaseLoop()
{
    _motorController = new LMotorController(ENA, IN1, IN2, ENB, IN3, IN4, AConst, BConst);
}

void LinePathMotorLoop::loopAtDefaultFrequency()
{
    LinePathBaseLoop::loopAtDefaultFrequency();

    _motorController->moveRaw(getLWS(), getRWS());
}
