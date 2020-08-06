#ifndef __WheelCommand__
#define __WheelCommand__

class WheelCommand
{
private:
    int _lws;
    int _rws;
public:
    WheelCommand(int lws, int rws);

    int getLWS();
    int getRWS();
};

#endif /* defined(__WheelCommand__) */