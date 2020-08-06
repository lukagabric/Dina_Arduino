#ifndef __LinePathMotorLoop__
#define __LinePathMotorLoop__

#include "LinePathBaseLoop.h"
#include "LMotorController.h"

class LinePathMotorLoop: public LinePathBaseLoop
{
private:
    LMotorController *_motorController;
public:
    LinePathMotorLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__LinePathMotorLoop__) */
