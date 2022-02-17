#include <iostream>
#include <windows.h>

using namespace std;

#include "../Head/Screen.h"
#include "../Head/GameLoop.h"
#include "../Head/Graphic.h"

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

    Graphic::DrawRect(&mainScreen, 10, 10, 4, 5);
    // mainScreen.TestInit();
    mainScreen.DisPlay();
}
