#ifndef __LinePathLoop__
#define __LinePathLoop__

#include "BaseLoop.h"
class Actuator;

enum MoveDirection { MoveDirectionForward = 1, MoveDirectionBackward = -1 };

class LinePathLoop: public BaseLoop
{
private:
    Actuator *_actuator;
    double _fHz;
    double _lws;
    double _rws;
    double _speedIncrement;
    MoveDirection _direction;
    unsigned long _directionInterval;
    unsigned long _moveTime;
public:
    LinePathLoop(Actuator *actuator, double fHz, unsigned long directionInterval);
    
    void resetLoop();
    void loopAtDefaultFrequency();
};

#endif /* defined(__LinePathLoop__) */
