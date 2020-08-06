#ifndef __CommandReader__
#define __CommandReader__

#include "SoftwareSerial.h"
#include "BaseLoop.h"
#include "ThumbstickBaseLoop.h"

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
    ThumbstickBaseLoop *_thumbstickBaseLoop;
public:
    CommandReader(SoftwareSerial *serial, ThumbstickBaseLoop *thumbstickBaseLoop, CommandReaderDelegate *delegate);

    void read();
};

#endif /* defined(__CommandReader__) */
