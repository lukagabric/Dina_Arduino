#ifndef __MotorWheelCommandHandler__
#define __MotorWheelCommandHandler__

#include "WheelCommandHandler.h"
#include "LMotorController.h"

class MotorWheelCommandHandler: public WheelCommandHandler
{
private:
    LMotorController *_motorController;
public:
    MotorWheelCommandHandler();

    void handleCommandAtFrequency();
};

#endif /* defined(__MotorWheellCommandHandler__) */
