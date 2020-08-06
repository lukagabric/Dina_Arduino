#ifndef __ThumbstickMotorLoop__
#define __ThumbstickMotorLoop__

#include "ThumbstickLoop.h"
#include "LMotorController.h"

class ThumbstickMotorLoop: public ThumbstickLoop
{
private:
    LMotorController *_motorController;
public:
    ThumbstickMotorLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__MotorWheellBaseLoop__) */
