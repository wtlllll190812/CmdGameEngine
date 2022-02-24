/*
* ECS系统组件库
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

class Component//ECS组件基类
{
public:   
    GameObject* owner;

    Component();
    virtual void OnAdd();//组件添加时
    virtual void OnRemove();//组件移除时
    virtual void OnUpdate();//组件更新
};

class Renderer : public Component//渲染器组件
{
public:
    Renderer(Screen *s);
    //组件添加时
    void OnAdd();
    //组件移除时
    void OnRemove();
    //组件更新
    void OnUpdate();
private:
    Screen* s;//屏幕指针
    Transform* tr;//位置组件
};

class Transform : public Component//位置组件
{
public:
    Vector2* position;//世界坐标
    float* Angle;//物体角度

    Transform();
    Transform(float,float);

    /*
    * @brief 位移方法
    * 向指定方向以某个速度产生一段位移
    * @param angle 移动方向
    * @param speed 移动速度
    */
    void Translate(Vector2 angle,float speed);
    //组件添加时
    void OnAdd();
    //组件移除时
    void OnRemove();
    //组件更新
    void OnUpdate();
};

class RigitBody:public Component
{
public:
    float gravity;//重力加速度
    float mass;//物体重量
    Vector2 velocity;//当前速度

    RigitBody();

    /*
    * 向物体添加一个力
    * @param force 力的向量
    */
    void AddForce(Vector2 ,forceMode);
    //组件添加时
    void OnAdd();
    //组件移除时
    void OnRemove();
    //组件更新
    void OnUpdate();

private:
    Vector2 force;//当前力
    Vector2 forceFrame;//添加力，仅作用于本帧

    Transform* tr;//位置组件
};

class Collider :public Component
{
    Collider();
    //组件添加时
    void OnAdd();
    //组件移除时
    void OnRemove();
    //组件更新
    void OnUpdate();
};
#endif
