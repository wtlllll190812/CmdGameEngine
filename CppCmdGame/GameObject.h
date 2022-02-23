#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <forward_list>
#include <iostream>
#include<type_traits>

#include "Component.h"
#include "DebugLog.h"

using namespace std;

class Component;

/*
* @brief ECS系统实体类
*/
class GameObject
{
public:
    GameObject();
    void Update();
    
    /*
    * @brief 添加组件
    * @param component 组件对象
    */
    void Addcomponent(Component* component);
    
    /*
    * @brief 获取组件
    * @param T 组件类型
    */
    template <class T>Component* GetComponent()
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
private:
    forward_list<Component*> components;//组件链表
};

#endif