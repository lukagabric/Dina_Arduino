#ifndef __LLEDMotorMockController__
#define __LLEDMotorMockController__

#include "Actuator.h"
#include "Arduino.h"

class LLEDMotorMockController: public Actuator
{
protected:
    int _leftGreen;
    int _leftBlue;
    int _rightGreen;
    int _rightBlue;
public:
    LLEDMotorMockController(int leftGreen, int leftBlue, int rightGreen, int rightBlue);

    //Actuator
    void actuate(int leftWheelSpeed, int rightWheelSpeed);
};


#endif /* defined(__LLEDMotorMockController__) */
