#ifndef __ThumbstickCommand__
#define __ThumbstickCommand__

class ThumbstickCommand
{
private:
    int _lws;
    int _rws;
public:
    ThumbstickCommand(int lws, int rws);

    int getLWS();
    int getRWS();
};

#endif /* defined(__ThumbstickCommand__) */