#include "DinaMain.h"
#include <Arduino.h>
#include "Constants.h"
#include "LEDWheelCommandHandler.h"
#include "MotorWheelCommandHandler.h"

DinaMain::DinaMain()
{
    _frequencyLoopTime = 0;
}

void DinaMain::setup()
{
    _serial = new SoftwareSerial(BTRX, BTTX);
    _serial->begin(9600);
    _serial->setTimeout(70);

    WheelCommandHandler *wheelCommandHandler;

    #if USE_LEDS_MOCK_FOR_WHEELS
    wheelCommandHandler = new LEDWheelCommandHandler();
    #else
    wheelCommandHandler = new MotorWheelCommandHandler();
    #endif

    _commandReader = new CommandReader(_serial, wheelCommandHandler, this);
}

void DinaMain::loop() 
{
    _commandReader->read();

    unsigned long currentTime = millis();
    if (currentTime - _frequencyLoopTime >= 1000/FREQ_HZ)
    {
        _frequencyLoopTime = currentTime;
        loopAtFrequency();
    }
}

void DinaMain::loopAtFrequency()
{
    if (_currentCommandHandler == NULL) 
    { 
        return; 
    }

    _currentCommandHandler->handleCommandAtFrequency();
}

//CommandReaderDelegate

void DinaMain::updateCommandHandler(CommandHandler *commandHandler)
{
    _currentCommandHandler = commandHandler;
}
