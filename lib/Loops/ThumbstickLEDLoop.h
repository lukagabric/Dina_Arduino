#ifndef __ThumbstickLEDLoop__
#define __ThumbstickLEDLoop__

#include "ThumbstickBaseLoop.h"
#include "LLEDMotorMockController.h"

class ThumbstickLEDLoop: public ThumbstickBaseLoop
{
private:
    LLEDMotorMockController *_ledMotorController;
public:
    ThumbstickLEDLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickLEDLoop__) */
