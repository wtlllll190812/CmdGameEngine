#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{
}

void GameObject::Update()
{
    (*components.begin())->OnUpdate();
    for (auto it = components.begin(); it != components.end(); ++it)
    {
        (*it)->OnUpdate();
    }
}

void GameObject::Addcomponent(Component* component)
{
    components.push_front(component);
    component->owner = this;
    component->OnAdd();
}

template <class T>
Component* GameObject::GetComponent()
{
    for (auto it = components.begin(); it != components.end(); ++it) 
    {
        if (typeid(T) == typeid(*it))
            return *it;
    }
    cout << "Component is not exist" << endl;
    return nullptr;
}