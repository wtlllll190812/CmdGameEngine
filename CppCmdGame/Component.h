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
class Collider;
class Vector2;

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
    Vector2* vertex;
    PixelData pixelData{false,"#",15};

    Renderer(Screen* ,Vector2* ,int);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
private:
    int vertexNumber;//�ߵ�����
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
   
    /*
    * @brief �ֲ�����ת��������
    * @param ori ��ʼ����
    * @return ��������
    */
    Vector2 ObjectToWorld(Vector2 ori);
    
    /*
    * @brief �ֲ���������ת������������
    * @param ori ��ʼ��������
    * @param size �����С 
    * @return ��������
    */
    Vector2* ObjectToWorld(Vector2* ori,int size);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
};

class RigidBody:public Component
{
public:
    float gravity;//�������ٶ�
    float mass;//��������
    Vector2 velocity;//��ǰ�ٶ�
    float drag;//����

    RigidBody();

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
    //SAT��ײ����㷨
    Vector2 SAT(Collider*);
private:
    Vector2 force;//��ǰ��
    Vector2 forceFrame;//��������������ڱ�֡

    Collider* col;//��ײ��
    Transform* tr;//λ�����
};

class Collider :public Component
{
public:
    Vector2* vertex;
    int vertexNumber;
    Transform* tr;

    Collider(Vector2[],int);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
};
#endif
