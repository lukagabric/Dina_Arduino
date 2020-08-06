#ifndef __LinePathLEDLoop__
#define __LinePathLEDLoop__

#include "LinePathBaseLoop.h"
#include "LLEDMotorMockController.h"

class LinePathLEDLoop: public LinePathBaseLoop
{
private:
    LLEDMotorMockController *_ledMotorController;
public:
    LinePathLEDLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__LinePathLEDLoop__) */
