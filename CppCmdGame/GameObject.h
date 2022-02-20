#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <forward_list>
using namespace std;

#include "Component.h"

class Component;

class GameObject
{
public:
    forward_list<Component*> components;

    GameObject();
    void Update();
    void Addcomponent(Component* component);
    template <class T>Component* GetComponent();
};

#endif