#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "GameObject.h"

class GameObject;

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
    Renderer();
    void OnAdd();
    void OnRemove();
    void OnUpdate();
};
#endif
