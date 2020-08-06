#ifndef __CommandReader__
#define __CommandReader__

#include "SoftwareSerial.h"
#include "CommandHandler.h"
#include "WheelCommandHandler.h"

class CommandReaderDelegate
{
    public:
    virtual void updateCommandHandler(CommandHandler *commandHandler) = 0;
};

class CommandReader
{
private:
    SoftwareSerial *_serial;
    CommandReaderDelegate *_delegate;
    WheelCommandHandler *_wheelCommandHandler;
public:
    CommandReader(SoftwareSerial *serial, WheelCommandHandler *wheelCommandHandler, CommandReaderDelegate *delegate);

    void read();
};

#endif /* defined(__CommandReader__) */
