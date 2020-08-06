#include "ThumbstickBaseLoop.h"
#include "LLowPassFilter.h"

ThumbstickBaseLoop::ThumbstickBaseLoop()
{
    double RC = 5;
    double dt = 0.9;
    _lwsFilter = new LLowPassFilter(RC, dt);
    _rwsFilter = new LLowPassFilter(RC, dt);
}

void ThumbstickBaseLoop::setThumbstickCommand(ThumbstickCommand *command)
{
    _command = command;
}

void ThumbstickBaseLoop::loopAtDefaultFrequency()
{
    _lws = _lwsFilter->filterValue(_command->getLWS());
    _rws = _rwsFilter->filterValue(_command->getRWS());
}

int ThumbstickBaseLoop::getLWS()
{
    return _lws;
}

int ThumbstickBaseLoop::getRWS()
{
    return _rws;
}