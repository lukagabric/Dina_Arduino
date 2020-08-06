#ifndef __ThumbstickBaseLoop__
#define __ThumbstickBaseLoop__

#include "BaseLoop.h"
#include "ThumbstickCommand.h"
class LLowPassFilter;

class ThumbstickBaseLoop: public BaseLoop
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
    ThumbstickBaseLoop();
    
    void setThumbstickCommand(ThumbstickCommand *command);
    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickBaseLoop__) */
