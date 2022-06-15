/*
 * ECSϵͳ�����
 */

#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include <vector>

#include "GameObject.h"
#include "Graphic.h"
#include "Screen.h"
#include "Engine.h"

using namespace std;

class GameObject;
class Screen;
class Transform;
class Collider;
class Vector2;

enum class forceMode
{
    impules,
    force
};

class Component // ECS�������
{
public:
    GameObject *owner;

    Component();
    virtual void OnAdd()=0;    //������ʱ
    virtual void OnRemove()=0; //����Ƴ�ʱ
    virtual void OnUpdate()=0; //�������
};

class Renderer : public Component //��Ⱦ�����
{
public:
    Vector2 *vertex;
    PixelData pixelData{false, "#", 15};

    Renderer(Screen *, Vector2 *, int);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();

private:
    int vertexNumber; //�ߵ�����
    Screen *s;        //��Ļָ��
    Transform *tr;    //λ�����
};

class Transform : public Component //λ�����
{
public:
    Vector2 *position; //��������
    float *Angle;      //����Ƕ�

    Transform();
    Transform(float, float);

    /*
     * @brief λ�Ʒ���
     * ��ָ��������ĳ���ٶȲ���һ��λ��
     * @param angle �ƶ�����
     * @param speed �ƶ��ٶ�
     */
    void Translate(Vector2 angle, float speed);

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
    Vector2 *ObjectToWorld(Vector2 *ori, int size);
    //������ʱ
    void OnAdd();
    //����Ƴ�ʱ
    void OnRemove();
    //�������
    void OnUpdate();
};

class RigidBody : public Component
{
public:
    float gravity;    //�������ٶ�
    float mass;       //��������
    Vector2 velocity; //��ǰ�ٶ�
    float drag;       //����

    RigidBody();

    /*
     * ���������һ����
     * @param force ��������
     */
    void AddForce(Vector2, forceMode);
    //������ʱ
    virtual void OnAdd();
    //����Ƴ�ʱ
    virtual void OnRemove();
    //�������
    virtual void OnUpdate();

    Vector2 ColliderCheck(Collider* col2);

    // SAT��ײ����㷨(δ���)
    Vector2 SAT(Collider *);
    // GJK��ײ����㷨
    bool GJK(vector<Vector2>& simplex, Transform* tr2, Vector2* v1, int vN1, Vector2* v2, int vN2);
    // EPA�㷨���㴩͸����
    Vector2 EPA(vector<Vector2>& simplex, Vector2* v1, int vN1, Vector2* v2, int vN2);

private:
    Vector2 force;      //��ǰ��
    Vector2 forceFrame; //��������������ڱ�֡

    Collider *col; //��ײ��
    Transform *tr; //λ�����

    /*
     * �������ͼ��ĳ������Զ��
     * @param dir ����
     * @param vertex ����ζ���
     * @param size ����ζ�������
     */
    Vector2 Support(Vector2 dir, Vector2 *vertex, int size);
    
    /*
     *���ظ���ͼ�ε������ 
     * @return ����ߵ�����
     */
    Vector2* FindClosestEdge(vector<Vector2>&);
    /*
     * ��������
     * @param dir ����
     * @param vertex ����ζ���
     */
    bool HandlerSimplex(Vector2 &dir, vector<Vector2> &vertex);
};

class Collider : public Component
{
public:
    Vector2 *vertex;
    int vertexNumber;
    Transform *tr;

    Collider(Vector2[], int);
    //������ʱ
    virtual void OnAdd();
    //����Ƴ�ʱ
    virtual void OnRemove();
    //�������
    virtual void OnUpdate();
};
#endif
