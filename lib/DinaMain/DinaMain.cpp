#include "DinaMain.h"
#include <Arduino.h>
#include "Constants.h"
#include "ThumbstickLoop.h"
#include "LinePathLoop.h"
#include "LLEDMotorMockController.h"
#include "LMotorController.h"

DinaMain::DinaMain()
{
    _frequencyLoopTime = 0;
}

void DinaMain::setup()
{
    _serial = new SoftwareSerial(BTRX, BTTX);
    _serial->begin(9600);
    _serial->setTimeout(70);

    Actuator *actuator;

    #if USE_LEDS_TO_MOCK_MOTORS
    actuator = new LLEDMotorMockController(LEFT_LED_GREEN, LEFT_LED_BLUE, RIGHT_LED_GREEN, RIGHT_LED_BLUE);
    #else
    actuator = new LMotorController(ENA, IN1, IN2, ENB, IN3, IN4, AConst, BConst);    
    #endif

    ThumbstickLoop *thumbstickLoop = new ThumbstickLoop(actuator);
    LinePathLoop *linePathLoop = new LinePathLoop(actuator, DEFAULT_FREQUENCY_HZ, LINE_PATH_MOTION_DURATION);

    _commandReader = new CommandReader(_serial, thumbstickLoop, linePathLoop, this);
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

void DinaMain::updateBaseLoop(BaseLoop *baseLoop)
{
    _currentBaseLoop = baseLoop;
}
