#ifndef GAMELOOP_H_
#define GAMELOOP_H_
#include <windows.h>

class GameLoop
{
private:
    float frame;
    DWORD lastFrame;

public:
    void FixedUpdate(void (*f)(void));
    void Update(void (*f)(void));
    GameLoop(float frame);
};

#endif
