#ifndef __ThumbstickLEDLoop__
#define __ThumbstickLEDLoop__

#include "ThumbstickLoop.h"

class ThumbstickLEDLoop: public ThumbstickLoop
{
public:
    ThumbstickLEDLoop();

    void loopAtDefaultFrequency();
};

#endif /* defined(__ThumbstickLEDLoop__) */
