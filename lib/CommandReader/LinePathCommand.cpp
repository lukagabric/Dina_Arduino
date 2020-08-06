#include "LinePathCommand.h"

LinePathCommand::LinePathCommand(int lws, int rws)
{
    _lws = lws;
    _rws = rws;
}

int LinePathCommand::getLWS()
{
    return _lws;
}

int LinePathCommand::getRWS()
{
    return _rws;
}

