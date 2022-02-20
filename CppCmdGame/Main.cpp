#include <iostream>
#include <windows.h>
#include <forward_list>
using namespace std;

#include "Screen.h"
#include "GameLoop.h"
#include "Graphic.h"
#include "GameObject.h"
#include "Component.h"
#include "DebugLog.h"

Screen mainScreen;
GameLoop mainLoop(30);
GameObject game;
void GameLogic();


forward_list<GameObject*> gameObjects;

int main()
{
    Renderer r;
    game.Addcomponent(&r);
    Debug::Instance().Log("sdsdsd");
    while (true)
    {
        GameLogic();
    }

    return 0;
}
void GameLogic()
{
    mainScreen.Reset();

    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
    {
        (*it)->Update();
    }
    
    Graphic::DrawRect(&mainScreen, 10, 10, 4, 5);

    mainScreen.DisPlay();
}
