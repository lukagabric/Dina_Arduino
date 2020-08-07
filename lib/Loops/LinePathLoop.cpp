#include "LinePathLoop.h"
#include "LLowPassFilter.h"
#include "Actuator.h"

LinePathLoop::LinePathLoop(Actuator *actuator)
{
    _actuator = actuator;

    double RC = 5;
    double dt = 0.9;
    _lwsFilter = new LLowPassFilter(RC, dt, -255, 255);
    _rwsFilter = new LLowPassFilter(RC, dt, -255, 255);
}

void LinePathLoop::setLinePathCommand(LinePathCommand *command)
{
    _command = command;
}

void LinePathLoop::loopAtDefaultFrequency()
{
    _lws = _lwsFilter->filterValue(_command->getLWS());
    _rws = _rwsFilter->filterValue(_command->getRWS());

    _actuator->actuate(_lws, _rws);
}
