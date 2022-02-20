#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "GameObject.h"
#include "Graphic.h"
#include "Screen.h"

class GameObject;
class Screen;

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
};
#endif
