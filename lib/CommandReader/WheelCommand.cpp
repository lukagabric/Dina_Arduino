#include "WheelCommand.h"

WheelCommand::WheelCommand(int lws, int rws)
{
    _lws = lws;
    _rws = rws;
}

int WheelCommand::getLWS()
{
    return _lws;
}

int WheelCommand::getRWS()
{
    return _rws;
}

