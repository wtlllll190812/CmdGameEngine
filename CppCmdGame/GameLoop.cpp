
#include "GameLoop.h"

void GameLoop::Update(void (*f)(void))
{
    Time::time = GetTickCount64();
    (*f)();
}
void GameLoop::FixedUpdate(void (*f)(void))
{
    Time::deltaTime = GetTickCount64() - lastFrame;
    if (Time::deltaTime > 1000 / frame)
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