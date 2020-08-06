#ifndef __LinePathBaseLoop__
#define __LinePathBaseLoop__

#include "BaseLoop.h"
#include "LinePathCommand.h"
class LLowPassFilter;

class LinePathBaseLoop: public BaseLoop
{
private:
    LinePathCommand *_command;
    LLowPassFilter *_lwsFilter;
    LLowPassFilter *_rwsFilter;
    int _lws;
    int _rws;
protected:
    int getLWS();
    int getRWS();
public:
    LinePathBaseLoop();
    
    void setLinePathCommand(LinePathCommand *command);
    void loopAtDefaultFrequency();
};

#endif /* defined(__LinePathBaseLoop__) */
