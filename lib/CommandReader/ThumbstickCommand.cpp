#include "ThumbstickCommand.h"

ThumbstickCommand::ThumbstickCommand(int lws, int rws)
{
    _lws = lws;
    _rws = rws;
}

int ThumbstickCommand::getLWS()
{
    return _lws;
}

int ThumbstickCommand::getRWS()
{
    return _rws;
}

