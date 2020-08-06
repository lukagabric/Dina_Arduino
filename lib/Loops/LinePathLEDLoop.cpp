#include "LinePathLEDLoop.h"
#include "Constants.h"
#include <Arduino.h>

LinePathLEDLoop::LinePathLEDLoop(): LinePathBaseLoop()
{
    _ledMotorController = new LLEDMotorMockController(LEFT_LED_GREEN, LEFT_LED_BLUE, RIGHT_LED_GREEN, RIGHT_LED_BLUE);
}

void LinePathLEDLoop::loopAtDefaultFrequency()
{
    LinePathLEDLoop::loopAtDefaultFrequency();

    _ledMotorController->light(getLWS(), getRWS());
}
