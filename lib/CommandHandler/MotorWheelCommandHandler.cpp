#include "MotorWheelCommandHandler.h"
#include "Constants.h"
#include <Arduino.h>

MotorWheelCommandHandler::MotorWheelCommandHandler(): WheelCommandHandler()
{
    _motorController = new LMotorController(ENA, IN1, IN2, ENB, IN3, IN4, AConst, BConst);
}

void MotorWheelCommandHandler::handleCommandAtFrequency()
{
    WheelCommandHandler::handleCommandAtFrequency();

    _motorController->moveRaw(getLWS(), getRWS());
}
