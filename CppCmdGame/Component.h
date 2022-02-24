/*
* ECSϵͳ�����
*/

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "GameObject.h"
#include "Graphic.h"
#include "Screen.h"
#include "Engine.h"

class GameObject;
class Screen;
class Transform;

enum class forceMode
{
    impules
    , force
};

class Component//ECS�������
{
public:   
    GameObject* owner;

    Component();
    virtual void OnAdd();//������ʱ
    virtual void OnRemove();//����Ƴ�ʱ
    virtual void OnUpdate();//�������
};

class Renderer : public Component//��Ⱦ�����
{
public:
    Renderer(Screen *s);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
private:
    Screen* s;//��Ļָ��
    Transform* tr;//λ�����
};

class Transform : public Component//λ�����
{
public:
    Vector2* position;//��������
    float* Angle;//����Ƕ�

    Transform();
    Transform(float,float);

    /*
    * @brief λ�Ʒ���
    * ��ָ��������ĳ���ٶȲ���һ��λ��
    * @param angle �ƶ�����
    * @param speed �ƶ��ٶ�
    */
    void Translate(Vector2 angle,float speed);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
};

class RigitBody:public Component
{
public:
    float gravity;//�������ٶ�
    float mass;//��������
    Vector2 velocity;//��ǰ�ٶ�

    RigitBody();

    /*
    * ���������һ����
    * @param force ��������
    */
    void AddForce(Vector2 ,forceMode);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();

private:
    Vector2 force;//��ǰ��
    Vector2 forceFrame;//��������������ڱ�֡

    Transform* tr;//λ�����
};

class Collider :public Component
{
    Collider();
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
};
#endif
