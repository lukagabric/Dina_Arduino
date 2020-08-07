#ifndef __CommandReader__
#define __CommandReader__

#include "SoftwareSerial.h"
#include "BaseLoop.h"
#include "ThumbstickLoop.h"
#include "LinePathLoop.h"

class CommandReaderDelegate
{
    public:
    virtual void updateBaseLoop(BaseLoop *baseLoop) = 0;
};

class CommandReader
{
private:
    SoftwareSerial *_serial;
    CommandReaderDelegate *_delegate;
    ThumbstickLoop *_thumbstickLoop;
    LinePathLoop *linePathLoop;
public:
    CommandReader(SoftwareSerial *serial, ThumbstickLoop *thumbstickLoop, LinePathLoop *linePathLoop, CommandReaderDelegate *delegate);

    void read();
};

#endif /* defined(__CommandReader__) */
