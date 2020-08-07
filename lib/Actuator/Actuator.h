#ifndef __Actuator__
#define __Actuator__

class Actuator
{
public:
    virtual void actuate(int leftWheelSpeed, int rightWheelSpeed) = 0;
};


#endif /* defined(__Actuator__) */
