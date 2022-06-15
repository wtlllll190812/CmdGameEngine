#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <forward_list>
#include <iostream>
#include <type_traits>

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
    void Addcomponent(Component *component);

    /*
     * @brief ��ȡ���
     * @param T �������
     */
    template <class T>
    T *GetComponent()
    {
        for (auto it = components.begin(); it != components.end(); it++)
        {
            auto com=dynamic_cast<T*>(*it);
            if (com)
            {
                return com;
            }
        }
        Debug::Instance().Log("Component is not exist");
        return nullptr;
    }

private:
    forward_list<Component *> components; //�������
};

#endif