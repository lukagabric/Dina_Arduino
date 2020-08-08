#include "LinePathLoop.h"
#include "LLowPassFilter.h"
#include "Actuator.h"
#include <Arduino.h>

LinePathLoop::LinePathLoop(Actuator *actuator, double fHz, unsigned long directionInterval)
{
    _lws = _rws = 0;
    _actuator = actuator;
    _fHz = fHz;
    _direction = MoveDirectionForward;
    _speedIncrement = 1.1;
    _directionInterval = directionInterval;
    _moveTime = millis();
}

void LinePathLoop::resetLoop()
{
    _lws = _rws = 0;
    _moveTime = millis();
    _direction = MoveDirectionForward;
}

void LinePathLoop::loopAtDefaultFrequency()
{
    unsigned long currentTime = millis();
    if (currentTime - _moveTime > _directionInterval)
    {
        _direction = _direction == MoveDirectionForward ? MoveDirectionBackward : MoveDirectionForward;
        _moveTime = currentTime;
    }

    if (_direction == MoveDirectionForward)
    {        
        if (_lws <= 255)
        {
            _lws = _rws = _lws + _speedIncrement;
            if (_lws > 255)
            {
                _lws = _rws = 255;
            }
        }
    }
    else
    {
        if (_lws >= -255)
        {
            _lws = _rws = _lws - _speedIncrement;
            if (_lws < -255)
            {
                _lws = _rws = -255;
            }
        }
    }

    _actuator->actuate(_lws, _rws);
}
