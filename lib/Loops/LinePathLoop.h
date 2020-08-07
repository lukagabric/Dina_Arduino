#ifndef __LinePathLoop__
#define __LinePathLoop__

#include "BaseLoop.h"
#include "LinePathCommand.h"
class Actuator;
class LLowPassFilter;

class LinePathLoop: public BaseLoop
{
private:
    LinePathCommand *_command;
    Actuator *_actuator;
    LLowPassFilter *_lwsFilter;
    LLowPassFilter *_rwsFilter;
    int _lws;
    int _rws;
public:
    LinePathLoop(Actuator *actuator);
    
    void setLinePathCommand(LinePathCommand *command);
    void loopAtDefaultFrequency();
};

#endif /* defined(__LinePathLoop__) */
