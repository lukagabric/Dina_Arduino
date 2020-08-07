#ifndef __LinePathLoop__
#define __LinePathLoop__

#include "BaseLoop.h"
#include "LinePathCommand.h"
class Actuator;

enum MoveDirection { MoveDirectionForward = 1, MoveDirectionBackward = -1 };

class LinePathLoop: public BaseLoop
{
private:
    LinePathCommand *_command;
    Actuator *_actuator;
    double _fHz;
    int _lws;
    int _rws;
    int _speedIncrement;
    MoveDirection _direction;
    unsigned long _directionInterval;
    unsigned long _moveTime;
public:
    LinePathLoop(Actuator *actuator, double fHz, unsigned long directionInterval);
    
    void setLinePathCommand(LinePathCommand *command);
    void loopAtDefaultFrequency();
};

#endif /* defined(__LinePathLoop__) */
