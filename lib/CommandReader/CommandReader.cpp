#include <Arduino.h>
#include "CommandReader.h"

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

        if (secondCommaIndex == -1 || thirdCommaIndex == -1)
        {
            return;
        }

        String rwsPercentString = inputString.substring(firstCommaIndex + 1, secondCommaIndex);
        String lwsPercentString = inputString.substring(secondCommaIndex + 1, thirdCommaIndex);

        int rwsPercent = rwsPercentString.toInt();
        int lwsPercent = lwsPercentString.toInt();

        int rws = map(rwsPercent, -100, 100, -255, 255);
        int lws = map(lwsPercent, -100, 100, -255, 255);

        _thumbstickLoop->setSpeeds(lws, rws);
        loop = _thumbstickLoop;
    }
    else if (command == "1")
    {
        _linePathLoop->resetLoop();
        loop = _linePathLoop;
    }

    _delegate->updateBaseLoop(loop);
}
