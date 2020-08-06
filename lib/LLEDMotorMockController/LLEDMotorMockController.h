#ifndef __LLEDMotorMockController__
#define __LLEDMotorMockController__

#include "Arduino.h"

class LLEDMotorMockController
{
protected:
    int _leftGreen;
    int _leftBlue;
    int _rightGreen;
    int _rightBlue;
public:
    LLEDMotorMockController(int leftGreen, int leftBlue, int rightGreen, int rightBlue);

    void light(int leftSpeed, int rightSpeed);
};


#endif /* defined(__LLEDMotorMockController__) */
