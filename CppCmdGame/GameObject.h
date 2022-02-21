#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <forward_list>
#include <iostream>#include<type_traits>

using namespace std;

#include "Component.h"
#include "DebugLog.h"

class Component;

class GameObject
{
public:
    forward_list<Component*> components;

    GameObject();
    void Update();
    void Addcomponent(Component* component);
    template <class T>
    Component* GetComponent()
    {
        for (auto it = components.begin(); it != components.end(); it++)
        {
            if (dynamic_cast<T*>(*it))
            {
                return *it;
            }
        }
        Debug::Instance().Log("Component is not exist");
        return nullptr;
    }
};

#endif