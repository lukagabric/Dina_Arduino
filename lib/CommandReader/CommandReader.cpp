#include <Arduino.h>
#include "CommandReader.h"
#include "ThumbstickCommand.h"

CommandReader::CommandReader(SoftwareSerial *serial, ThumbstickLoop *thumbstickLoop, LinePathLoop *linePathLoop, CommandReaderDelegate *delegate)
{
    _serial = serial;
    _thumbstickLoop = thumbstickLoop;
    _linePathLoop = linePathLoop;
    _delegate = delegate;
}

void CommandReader::read()
{
    if (!_serial->available()) return;

    String inputString = _serial->readString();
    int firstCommaIndex = inputString.indexOf(",");

    String command = inputString.substring(0, firstCommaIndex);
    
    BaseLoop *loop;

    if (command == "0")
    {
        int secondCommaIndex = inputString.indexOf(",", firstCommaIndex + 1);
        int thirdCommaIndex = inputString.indexOf(",", secondCommaIndex + 1);

        String lwsPercentString = inputString.substring(firstCommaIndex + 1, secondCommaIndex);
        String rwsPercentString = inputString.substring(secondCommaIndex + 1, thirdCommaIndex);

        int lwsPercent = lwsPercentString.toInt();
        int rwsPercent = rwsPercentString.toInt();

        int lws = map(lwsPercent, -100, 100, -255, 255);
        int rws = map(rwsPercent, -100, 100, -255, 255);

        ThumbstickCommand *command = new ThumbstickCommand(lws, rws);
        _thumbstickLoop->setThumbstickCommand(command);
        loop = _thumbstickLoop;
    }
    else if (command == "1")
    {
        _linePathLoop->resetLoop();
        loop = _linePathLoop;
    }

    _delegate->updateBaseLoop(loop);
}
