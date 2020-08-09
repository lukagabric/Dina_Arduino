#include "ThumbstickLoop.h"
#include "LLowPassFilter.h"
#include "Actuator.h"
#include <Arduino.h>

ThumbstickLoop::ThumbstickLoop(Actuator *actuator)
{
    _actuator = actuator;

    double RC = 5;
    double dt = 0.9;
    _lwsFilter = new LLowPassFilter(RC, dt, -255, 255);
    _rwsFilter = new LLowPassFilter(RC, dt, -255, 255);

    _lws = _rws = _rawLWS = _rawRWS = 0;
}

void ThumbstickLoop::setSpeeds(int lws, int rws)
{
    _rawLWS = lws;
    _rawRWS = rws;
}

void ThumbstickLoop::loopAtDefaultFrequency()
{
    _lws = _lwsFilter->filterValue(_rawLWS);
    _rws = _rwsFilter->filterValue(_rawRWS);
    
    _actuator->actuate(_lws, _rws);
}
