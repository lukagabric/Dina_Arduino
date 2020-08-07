#ifndef __ThumbstickLoop__
#define __ThumbstickLoop__

#include "BaseLoop.h"
#include "ThumbstickCommand.h"
class Actuator;
class LLowPassFilter;

class ThumbstickLoop: public BaseLoop
{
private:
    ThumbstickCommand *_command;
    Actuator *_actuator;
    LLowPassFilter *_lwsFilter;
    LLowPassFilter *_rwsFilter;
    int _lws;
    int _rws;
public:
    ThumbstickLoop(Actuator *actuator);
    
    void setThumbstickCommand(ThumbstickCommand *command);
    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickLoop__) */
