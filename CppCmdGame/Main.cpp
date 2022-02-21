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
#include "Input.h"

Screen mainScreen;
GameLoop mainLoop(30);
GameObject game;
void GameLogic();
void GameInit();

forward_list<GameObject*> gameObjects;

int main()
{ 
    Transform t(10.0f,10.0f);
    Renderer r(&mainScreen);
    
    game.Addcomponent(&t);   
    game.Addcomponent(&r);

    gameObjects.push_front(&game);
    GameInit();
    Debug::Instance().Log("Game started");
    Debug::Instance().Log(t.position->ToString());
    while (true)
    {  
        t.Translate(Vector2(1, 0), 0.01f);

        GameLogic();
    }

    return 0;
}
void GameInit()
{
    mainScreen.Reset();
}
void GameLogic()
{
    mainScreen.Reset();

    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        (*it)->Update();
    }

    mainScreen.DisPlay();
}
