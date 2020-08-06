#include <Arduino.h>
#include "CommandReader.h"
#include "ThumbstickCommand.h"

CommandReader::CommandReader(SoftwareSerial *serial, ThumbstickBaseLoop *thumbstickBaseLoop, CommandReaderDelegate *delegate)
{
    _serial = serial;
    _thumbstickBaseLoop = thumbstickBaseLoop;
    _delegate = delegate;
}

void CommandReader::read()
{
    if (!_serial->available()) return;

    String inputString = _serial->readString();
    int firstCommaIndex = inputString.indexOf(",");
    int secondCommaIndex = inputString.indexOf(",", firstCommaIndex+1);
    String lwsPercentString = inputString.substring(0, firstCommaIndex);
    String rwsPercentString = inputString.substring(firstCommaIndex + 1, secondCommaIndex);
    int lwsPercent = lwsPercentString.toInt();
    int rwsPercent = rwsPercentString.toInt();

    int lws = map(lwsPercent, -100, 100, -255, 255);
    int rws = map(rwsPercent, -100, 100, -255, 255);

    ThumbstickCommand *command = new ThumbstickCommand(lws, rws);
    _thumbstickBaseLoop->setThumbstickCommand(command);
    _delegate->updateBaseLoop(_thumbstickBaseLoop);
}
