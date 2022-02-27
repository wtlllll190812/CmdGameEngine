#include "GameObject.h"

GameObject::GameObject()
{
}

void GameObject::Update()
{
    for (auto it = components.begin(); it != components.end(); it++)
    {
        (*it)->OnUpdate();
    }
}

void GameObject::Addcomponent(Component *component)
{
    components.push_front(component);
    component->owner = this;
    component->OnAdd();
}
