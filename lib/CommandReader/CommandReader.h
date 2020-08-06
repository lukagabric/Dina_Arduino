#ifndef __CommandReader__
#define __CommandReader__

#include "SoftwareSerial.h"
#include "BaseLoop.h"
#include "ThumbstickLoop.h"

class CommandReaderDelegate
{
    public:
    virtual void updateBaseLoop(BaseLoop *commandHandler) = 0;
};

class CommandReader
{
private:
    SoftwareSerial *_serial;
    CommandReaderDelegate *_delegate;
    ThumbstickLoop *_wheelBaseLoop;
public:
    CommandReader(SoftwareSerial *serial, ThumbstickLoop *wheelBaseLoop, CommandReaderDelegate *delegate);

    void read();
};

#endif /* defined(__CommandReader__) */
