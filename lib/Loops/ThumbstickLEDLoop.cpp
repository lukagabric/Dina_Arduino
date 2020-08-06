#include "ThumbstickLEDLoop.h"
#include "Constants.h"
#include <Arduino.h>

ThumbstickLEDLoop::ThumbstickLEDLoop(): ThumbstickBaseLoop()
{
    _ledMotorController = new LLEDMotorMockController(LEFT_LED_GREEN, LEFT_LED_BLUE, RIGHT_LED_GREEN, RIGHT_LED_BLUE);
}

void ThumbstickLEDLoop::loopAtDefaultFrequency()
{
    ThumbstickBaseLoop::loopAtDefaultFrequency();

    _ledMotorController->light(getLWS(), getRWS());
}
