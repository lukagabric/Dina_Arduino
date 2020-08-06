#ifndef __WheelCommandHandler__
#define __WheelCommandHandler__

#include "CommandHandler.h"
#include "WheelCommand.h"
class LLowPassFilter;

class WheelCommandHandler: public CommandHandler
{
private:
    WheelCommand *_command;
    LLowPassFilter *_lwsFilter;
    LLowPassFilter *_rwsFilter;
    int _lws;
    int _rws;
protected:
    int getLWS();
    int getRWS();
public:
    WheelCommandHandler();
    void setWheelCommand(WheelCommand *command);
    void handleCommandAtFrequency();
};

#endif /* defined(__WheelCommandHandler__) */
