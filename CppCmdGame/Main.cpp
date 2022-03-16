#include <iostream>
#include <windows.h>
#include <forward_list>
#include <vector>
using namespace std;

#include "Screen.h"
#include "GameLoop.h"
#include "Graphic.h"
#include "GameObject.h"
#include "Component.h"
#include "DebugLog.h"
#include "Input.h"

#define FRAMERATE 20

Vector2 vertex[4]{Vector2(-10, -2), Vector2(10, -2), Vector2(10, 2), Vector2(-10, 2)};

Screen mainScreen;
GameLoop mainLoop(FRAMERATE);
GameObject game;

Transform t(18, 5);
Renderer r(&mainScreen, vertex, 4);
RigidBody ri;
Collider col1(vertex, 4);

GameObject game2;
Transform t2(20.0f, 15.0f);
Collider col2(vertex, 4);
Renderer r2(&mainScreen, vertex, 4);

forward_list<GameObject *> gameObjects;

void FixedUpdate();
void GameInit();
void Update();
void Physics(RigidBody *Rb);



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
        Physics(dynamic_cast<RigidBody *>((*it)->GetComponent<RigidBody>()));
        (*it)->Update();
    }

    mainScreen.DisPlay();
}

void Update()
{
    // ri.AddForce(Vector2(0, 0.1f), forceMode::impules);

    if (Input::GetKeyDown(KeyCode::W))
        t.Translate(Vector2(0, 1), 0.001f);
    if (Input::GetKeyDown(KeyCode::S))
        t.Translate(Vector2(0, -1), 0.001f);
    if (Input::GetKeyDown(KeyCode::A))
        t.Translate(Vector2(1, 0), 0.001f);
    if (Input::GetKeyDown(KeyCode::D))
        t.Translate(Vector2(-1, 0), 0.001f);
}

void Physics(RigidBody *Rb)
{
    if (!Rb)
        return;

    for (auto _it = gameObjects.begin(); _it != gameObjects.end(); _it++)
    {
        Collider *col;
        if (*_it == Rb->owner)
            continue;
        if (col = dynamic_cast<Collider *>((*_it)->GetComponent<Collider>()))
        {
            Renderer *r = dynamic_cast<Renderer *>(Rb->owner->GetComponent<Renderer>());
            Vector2 res = Rb->ColliderCheck(col);
            if (res == Vector2::zero)
            {
                r->pixelData = PixelData{false, " ", 174};
            }
            else
            {
                Rb->AddForce((-Rb->velocity - res * FRAMERATE) * FRAMERATE / 2, forceMode::impules);
                r->pixelData = PixelData{false, " ", 196};
            }
        }
    }
}