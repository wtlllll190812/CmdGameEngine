
#include "GameLoop.h"

void GameLoop::Update(void (*f)(void))
{
    (*f)();
}
void GameLoop::FixedUpdate(void (*f)(void))
{
    if (GetTickCount64() - lastFrame > 1000 / frame)
    {
        lastFrame = GetTickCount64();
        (*f)();
    }
}
GameLoop::GameLoop(float frame)
{
    this->frame = frame;
    lastFrame = GetTickCount64();
}