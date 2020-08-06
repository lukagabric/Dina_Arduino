#include "ThumbstickLoop.h"
#include "LLowPassFilter.h"

ThumbstickLoop::ThumbstickLoop()
{
    double RC = 5;
    double dt = 0.9;
    _lwsFilter = new LLowPassFilter(RC, dt);
    _rwsFilter = new LLowPassFilter(RC, dt);
}

void ThumbstickLoop::setThumbstickCommand(ThumbstickCommand *command)
{
    _command = command;
}

void ThumbstickLoop::loopAtDefaultFrequency()
{
    _lws = _lwsFilter->filterValue(_command->getLWS());
    _rws = _rwsFilter->filterValue(_command->getRWS());
}

int ThumbstickLoop::getLWS()
{
    return _lws;
}

int ThumbstickLoop::getRWS()
{
    return _rws;
}