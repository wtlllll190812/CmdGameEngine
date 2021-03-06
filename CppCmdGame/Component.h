/*
 * ECS系统组件库
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

class Component // ECS组件基类
{
public:
    GameObject *owner;

    Component();
    virtual void OnAdd()=0;    //组件添加时
    virtual void OnRemove()=0; //组件移除时
    virtual void OnUpdate()=0; //组件更新
};

class Renderer : public Component //渲染器组件
{
public:
    Vector2 *vertex;
    PixelData pixelData{false, "#", 15};

    Renderer(Screen *, Vector2 *, int);
    //组件添加时
    void OnAdd();
    //组件移除时
    void OnRemove();
    //组件更新
    void OnUpdate();

private:
    int vertexNumber; //边的数量
    Screen *s;        //屏幕指针
    Transform *tr;    //位置组件
};

class Transform : public Component //位置组件
{
public:
    Vector2 *position; //世界坐标
    float *Angle;      //物体角度

    Transform();
    Transform(float, float);

    /*
     * @brief 位移方法
     * 向指定方向以某个速度产生一段位移
     * @param angle 移动方向
     * @param speed 移动速度
     */
    void Translate(Vector2 angle, float speed);

    /*
     * @brief 局部坐标转世界坐标
     * @param ori 初始坐标
     * @return 世界坐标
     */
    Vector2 ObjectToWorld(Vector2 ori);

    /*
     * @brief 局部坐标数组转世界坐标数组
     * @param ori 初始坐标数组
     * @param size 数组大小
     * @return 世界坐标
     */
    Vector2 *ObjectToWorld(Vector2 *ori, int size);
    //组件添加时
    void OnAdd();
    //组件移除时
    void OnRemove();
    //组件更新
    void OnUpdate();
};

class RigidBody : public Component
{
public:
    float gravity;    //重力加速度
    float mass;       //物体重量
    Vector2 velocity; //当前速度
    float drag;       //阻力

    RigidBody();

    /*
     * 向物体添加一个力
     * @param force 力的向量
     */
    void AddForce(Vector2, forceMode);
    //组件添加时
    virtual void OnAdd();
    //组件移除时
    virtual void OnRemove();
    //组件更新
    virtual void OnUpdate();

    Vector2 ColliderCheck(Collider* col2);

    // SAT碰撞检测算法(未完成)
    Vector2 SAT(Collider *);
    // GJK碰撞检测算法
    bool GJK(vector<Vector2>& simplex, Transform* tr2, Vector2* v1, int vN1, Vector2* v2, int vN2);
    // EPA算法计算穿透向量
    Vector2 EPA(vector<Vector2>& simplex, Vector2* v1, int vN1, Vector2* v2, int vN2);

private:
    Vector2 force;      //当前力
    Vector2 forceFrame; //添加力，仅作用于本帧

    Collider *col; //碰撞体
    Transform *tr; //位置组件

    /*
     * 计算给定图形某方向最远点
     * @param dir 方向
     * @param vertex 多边形顶点
     * @param size 多边形顶点数量
     */
    Vector2 Support(Vector2 dir, Vector2 *vertex, int size);
    
    /*
     *返回给定图形的最近边 
     * @return 最近边的引用
     */
    Vector2* FindClosestEdge(vector<Vector2>&);
    /*
     * 处理单纯形
     * @param dir 方向
     * @param vertex 多边形顶点
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
    //组件添加时
    virtual void OnAdd();
    //组件移除时
    virtual void OnRemove();
    //组件更新
    virtual void OnUpdate();
};
#endif
