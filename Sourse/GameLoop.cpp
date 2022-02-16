
#include "../Head/GameLoop.h"

void GameLoop::Update(void (*f)(void))
{
    (*f)();
}
void GameLoop::FixedUpdate(void (*f)(void))
{
    if (GetTickCount() - lastFrame > 1000 / frame)
    {
        lastFrame = GetTickCount();
        (*f)();
    }
}
GameLoop::GameLoop(float frame)
{
    this->frame = frame;
    lastFrame = GetTickCount();
}