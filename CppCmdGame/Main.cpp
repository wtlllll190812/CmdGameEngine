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

Vector2 vertex[4]{ Vector2(10,10),Vector2(20,10),Vector2(20,20),Vector2(10,20) };

Screen mainScreen;
GameLoop mainLoop(20);
GameObject game;

Transform t(20.0f,0);
Renderer r(&mainScreen, vertex, 4);
RigitBody ri;
Collider col1(vertex, 4);

GameObject game2;
Transform t2(20.0f,15.0f);
Collider col2(vertex, 4);
Renderer r2(&mainScreen, vertex, 4);

forward_list<GameObject*> gameObjects;

void FixedUpdate();
void GameInit();
void Update();
void Physics(RigitBody* Rb);

int main()
{ 
    game.Addcomponent(&t);   
    game.Addcomponent(&r);
    game.Addcomponent(&ri);
    game.Addcomponent(&col1);

    game2.Addcomponent(&t2);
    game2.Addcomponent(&col2);
    game2.Addcomponent(&r2);

    gameObjects.push_front(&game);
    gameObjects.push_front(&game2);
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
        Physics(dynamic_cast<RigitBody*>((*it)->GetComponent<RigitBody>()));
        (*it)->Update();
    }

    mainScreen.DisPlay();
}

void Update()
{
    //ri.AddForce(Vector2(0, 0.1f), forceMode::impules);

    if (Input::GetKeyDown(KeyCode::W))
        t.Translate(Vector2(0, 1), 0.001f);
    if (Input::GetKeyDown(KeyCode::S))
        t.Translate(Vector2(0, -1), 0.001f);
    if (Input::GetKeyDown(KeyCode::A))
        t.Translate(Vector2(1, 0), 0.001f);
    if (Input::GetKeyDown(KeyCode::D))
        t.Translate(Vector2(-1, 0), 0.001f);
}

void Physics(RigitBody* Rb)
{
    if (!Rb)return;

    for (auto _it = gameObjects.begin(); _it != gameObjects.end(); _it++)
    {
        Collider* col;
        if (*_it == Rb->owner)
            continue;
        if (col = dynamic_cast<Collider*>((*_it)->GetComponent<Collider>()))
        {
            Vector2 res = Rb->SAT(col);
            Renderer* r = dynamic_cast<Renderer*>(Rb->owner->GetComponent<Renderer>());
            Debug::Instance().Log(res.ToString());
            if (res.x<0&&res.y<0)
            {
                Rb->AddForce(-Rb->velocity*(res.Magnitude()), forceMode::impules);
                r->pixelData = PixelData{ false," ",226 };
            }
            else
            {
                r->pixelData = PixelData{ false," ",199 };
            }
        }
    }
}