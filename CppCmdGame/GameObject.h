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
* @brief ECSϵͳʵ����
*/
class GameObject
{
public:
    GameObject();
    void Update();
    
    /*
    * @brief ������
    * @param component �������
    */
    void Addcomponent(Component* component);
    
    /*
    * @brief ��ȡ���
    * @param T �������
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
    forward_list<Component*> components;//�������
};

#endif