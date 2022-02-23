#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "GameObject.h"
#include "Graphic.h"
#include "Screen.h"
#include "Engine.h"

class GameObject;
class Screen;
class Transform;

class Component
{
public:   
    GameObject* owner;

    Component();
    virtual void OnAdd();
    virtual void OnRemove();
    virtual void OnUpdate();
};

class Renderer : public Component
{
public:
    Renderer(Screen *s);
    void OnAdd();
    void OnRemove();
    void OnUpdate();
private:
    Screen* s;
    Transform* tr;
};

class Transform : public Component
{
public:
    Vector2* position;
    float* Angle;
    Transform();
    Transform(float,float);
    void Translate(Vector2 angle,float speed);
    void OnAdd();
    void OnRemove();
    void OnUpdate();
};

class RigitBody: Component
{
public:
    float gravity;


    RigitBody();
    void AddForce(Vector2 force);
    void OnAdd();
    void OnRemove();
    void OnUpdate();
private:
    Vector2 force;
    Vector2 v;
    Transform* tr;
};

class Collider :Component
{
    Collider();
    void AddForce(Vector2 force);
    void OnAdd();
    void OnRemove();
    void OnUpdate();
};
#endif
