#include "LEDWheelCommandHandler.h"
#include "Constants.h"
#include <Arduino.h>

LEDWheelCommandHandler::LEDWheelCommandHandler(): WheelCommandHandler()
{
    pinMode(LEFT_LED_GREEN, OUTPUT);
    pinMode(LEFT_LED_BLUE, OUTPUT);
    pinMode(RIGHT_LED_GREEN, OUTPUT);
    pinMode(RIGHT_LED_BLUE, OUTPUT);
}

void LEDWheelCommandHandler::handleCommandAtFrequency()
{
    WheelCommandHandler::handleCommandAtFrequency();

    int lws = WheelCommandHandler::getLWS();
    int rws = WheelCommandHandler::getRWS();

    if (lws >= 0)
    {
        analogWrite(LEFT_LED_GREEN, lws);
        analogWrite(LEFT_LED_BLUE, 0);
    } 
    else
    {
        analogWrite(LEFT_LED_GREEN, 0);
        analogWrite(LEFT_LED_BLUE, -1*lws);
    }

    if (rws >= 0)
    {
        analogWrite(RIGHT_LED_GREEN, rws);
        analogWrite(RIGHT_LED_BLUE, 0);
    } 
    else
    {
        analogWrite(RIGHT_LED_GREEN, 0);
        analogWrite(RIGHT_LED_BLUE, -1*rws);
    }
}
