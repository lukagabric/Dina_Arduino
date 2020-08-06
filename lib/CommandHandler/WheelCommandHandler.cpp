#include "WheelCommandHandler.h"
#include "LLowPassFilter.h"

WheelCommandHandler::WheelCommandHandler()
{
    double RC = 1;
    double dt = 1;
    _lwsFilter = new LLowPassFilter(RC, dt);
    _rwsFilter = new LLowPassFilter(RC, dt);
}

void WheelCommandHandler::setWheelCommand(WheelCommand *command)
{
    _command = command;
}

void WheelCommandHandler::handleCommandAtFrequency()
{
    _lws = _lwsFilter->filterValue(_command->getLWS());
    _rws = _rwsFilter->filterValue(_command->getRWS());
}

int WheelCommandHandler::getLWS()
{
    return _lws;
}

int WheelCommandHandler::getRWS()
{
    return _rws;
}