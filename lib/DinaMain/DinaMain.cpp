#include "DinaMain.h"
#include <Arduino.h>
#include "Constants.h"
#include "ThumbstickLEDLoop.h"
#include "ThumbstickMotorLoop.h"

DinaMain::DinaMain()
{
    _frequencyLoopTime = 0;
}

void DinaMain::setup()
{
    _serial = new SoftwareSerial(BTRX, BTTX);
    _serial->begin(9600);
    _serial->setTimeout(70);

    ThumbstickBaseLoop *thumbstickBaseLoop;

    #if USE_LEDS_TO_MOCK_MOTORS
    thumbstickBaseLoop = new ThumbstickLEDLoop();
    #else
    thumbstickBaseLoop = new ThumbstickMotorLoop();
    #endif

    _commandReader = new CommandReader(_serial, thumbstickBaseLoop, this);
}

void DinaMain::loop() 
{
    _commandReader->read();

    unsigned long currentTime = millis();
    if (currentTime - _frequencyLoopTime >= 1000/DEFAULT_FREQUENCY_HZ)
    {
        _frequencyLoopTime = currentTime;
        loopAtFrequency();
    }
}

void DinaMain::loopAtFrequency()
{
    if (_currentBaseLoop == NULL) 
    { 
        return; 
    }

    _currentBaseLoop->loopAtDefaultFrequency();
}

//CommandReaderDelegate

void DinaMain::updateBaseLoop(BaseLoop *commandHandler)
{
    _currentBaseLoop = commandHandler;
}
