#ifndef __ThumbstickMotorLoop__
#define __ThumbstickMotorLoop__

#include "ThumbstickBaseLoop.h"
#include "LMotorController.h"

class ThumbstickMotorLoop: public ThumbstickBaseLoop
{
private:
    LMotorController *_motorController;
public:
    ThumbstickMotorLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickMotorLoop__) */
