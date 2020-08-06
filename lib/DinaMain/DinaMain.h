#ifndef __DinaMain__
#define __DinaMain__

#include "SoftwareSerial.h"
#include "CommandReader.h"

class DinaMain: public CommandReaderDelegate
{
private:
    SoftwareSerial *_serial;
    CommandReader *_commandReader;

    void loopAtFrequency();
    unsigned long _frequencyLoopTime;

    CommandHandler *_currentCommandHandler;
public:
    DinaMain();

    void setup();
    void loop();

    //CommandReaderDelegate
    void updateCommandHandler(CommandHandler *commandHandler);
};

#endif /* defined(__DinaMain__) */
