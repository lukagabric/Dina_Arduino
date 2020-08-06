#include "LinePathBaseLoop.h"
#include "LLowPassFilter.h"

LinePathBaseLoop::LinePathBaseLoop()
{
    double RC = 5;
    double dt = 0.9;
    _lwsFilter = new LLowPassFilter(RC, dt);
    _rwsFilter = new LLowPassFilter(RC, dt);
}

void LinePathBaseLoop::setLinePathCommand(LinePathCommand *command)
{
    _command = command;
}

void LinePathBaseLoop::loopAtDefaultFrequency()
{
    _lws = _lwsFilter->filterValue(_command->getLWS());
    _rws = _rwsFilter->filterValue(_command->getRWS());
}

int LinePathBaseLoop::getLWS()
{
    return _lws;
}

int LinePathBaseLoop::getRWS()
{
    return _rws;
}