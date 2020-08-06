#ifndef __ThumbstickLoop__
#define __ThumbstickLoop__

#include "BaseLoop.h"
#include "ThumbstickCommand.h"
class LLowPassFilter;

class ThumbstickLoop: public BaseLoop
{
private:
    ThumbstickCommand *_command;
    LLowPassFilter *_lwsFilter;
    LLowPassFilter *_rwsFilter;
    int _lws;
    int _rws;
protected:
    int getLWS();
    int getRWS();
public:
    ThumbstickLoop();
    void setThumbstickCommand(ThumbstickCommand *command);
    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickLoop__) */
