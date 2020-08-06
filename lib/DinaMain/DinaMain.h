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

    BaseLoop *_currentBaseLoop;
public:
    DinaMain();

    void setup();
    void loop();

    //CommandReaderDelegate
    void updateBaseLoop(BaseLoop *baseLoop);
};

#endif /* defined(__DinaMain__) */
