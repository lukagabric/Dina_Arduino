#ifndef __ThumbstickLEDLoop__
#define __ThumbstickLEDLoop__

#include "ThumbstickBaseLoop.h"

class ThumbstickLEDLoop: public ThumbstickBaseLoop
{
public:
    ThumbstickLEDLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickLEDLoop__) */
