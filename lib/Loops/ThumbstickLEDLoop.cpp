#include "ThumbstickLEDLoop.h"
#include "Constants.h"
#include <Arduino.h>

ThumbstickLEDLoop::ThumbstickLEDLoop(): ThumbstickLoop()
{
    pinMode(LEFT_LED_GREEN, OUTPUT);
    pinMode(LEFT_LED_BLUE, OUTPUT);
    pinMode(RIGHT_LED_GREEN, OUTPUT);
    pinMode(RIGHT_LED_BLUE, OUTPUT);
}

void ThumbstickLEDLoop::loopAtDefaultFrequency()
{
    ThumbstickLoop::loopAtDefaultFrequency();

    int lws = ThumbstickLoop::getLWS();
    int rws = ThumbstickLoop::getRWS();

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
