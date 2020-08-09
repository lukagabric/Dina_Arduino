#ifndef __ThumbstickLoop__
#define __ThumbstickLoop__

#include "BaseLoop.h"
class Actuator;
class LLowPassFilter;

class ThumbstickLoop: public BaseLoop
{
private:
    Actuator *_actuator;
    LLowPassFilter *_lwsFilter;
    LLowPassFilter *_rwsFilter;
    int _lws;
    int _rws;
    int _rawLWS;
    int _rawRWS;
public:
    ThumbstickLoop(Actuator *actuator);
    
    void setSpeeds(int lws, int rws);
    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickLoop__) */
