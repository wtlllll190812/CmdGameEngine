#include <iostream>
#include <windows.h>

using namespace std;

#include "../Head/Screen.h"
#include "../Head/GameLoop.h"

Screen mainScreen;
GameLoop mainLoop(1);

void GameLogic();

int main()
{
    while (true)
    {
        mainLoop.FixedUpdate(GameLogic);
    }

    return 0;
}
void GameLogic()
{
    mainScreen.Reset();

    mainScreen.TestInit();

    mainScreen.DisPlay();
}
