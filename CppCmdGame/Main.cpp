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
GameLoop mainLoop(20);
GameObject game;
Transform t(10.0f,10.0f);
Renderer r(&mainScreen);

forward_list<GameObject*> gameObjects;

void FixedUpdate();
void GameInit();
void Update();

int main()
{ 
    game.Addcomponent(&t);   
    game.Addcomponent(&r);

    gameObjects.push_front(&game);
    GameInit();

    Debug::Instance().Log("Game started");

    
    while (true)
    {  
        
        mainLoop.FixedUpdate(FixedUpdate);
        mainLoop.Update(Update);
    }

    return 0;
}

void GameInit()
{
    mainScreen.Reset();
}

void FixedUpdate()
{
    mainScreen.Reset();

    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        (*it)->Update();
    }

    Vector2 test[4]{ Vector2(10,10),Vector2(10,20),Vector2(20,20),Vector2(20,10)};
    Graphic::DrawPolygon(&mainScreen, test,4);

    mainScreen.DisPlay();
}

void Update()
{
    if (Input::GetKeyDown(KeyCode::W))
        t.Translate(Vector2(0, 1), 0.001f);
    if (Input::GetKeyDown(KeyCode::S))
        t.Translate(Vector2(0, -1), 0.001f);
    if (Input::GetKeyDown(KeyCode::A))
        t.Translate(Vector2(1, 0), 0.001f);
    if (Input::GetKeyDown(KeyCode::D))
        t.Translate(Vector2(-1, 0), 0.001f);
}