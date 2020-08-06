#ifndef __LinePathCommand__
#define __LinePathCommand__

class LinePathCommand
{
private:
    int _lws;
    int _rws;
public:
    LinePathCommand(int lws, int rws);

    int getLWS();
    int getRWS();
};

#endif /* defined(__LinePathCommand__) */