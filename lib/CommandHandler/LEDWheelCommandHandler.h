#ifndef __LEDWheelCommandHandler__
#define __LEDWheelCommandHandler__

#include "WheelCommandHandler.h"

class LEDWheelCommandHandler: public WheelCommandHandler
{
public:
    LEDWheelCommandHandler();

    void handleCommandAtFrequency();
};

#endif /* defined(__LEDWheelCommandHandler__) */
