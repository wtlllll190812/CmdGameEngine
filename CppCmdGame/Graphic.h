#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "Screen.h"
#include "Engine.h"
#include<cmath>

/*
* @brief 图形生成类
*/
class Graphic
{
public:
    
    /*
    * @brief 画一个圆
    * @param s 要绘制的Screen对象
    * @param pos 圆心坐标
    * @param R 直径
    */
    static void DrawCircle(Screen *s, Vector2 pos, int R);
    
    /*
    * @brief 画一个矩形
    * @param s 要绘制的Screen对象
    * @param pos 中心坐标
    * @param w 矩形宽度
    * @param h 矩形高度
    */
    static void DrawRect(Screen *s, Vector2 pos, int w, int h);

    /*
    * @brief 画一个三角
    * @param s 要绘制的Screen对象
    * @param vertex 顶点集合
    */
    static void DrawTriAngle(Screen* s, PixelData pd, Vector2[3]);

    /*
    * @brief 画一个多边形
    * 绘制多边形，目前只支持凸多边形
    * @param s 要绘制的Screen对象
    * @param pos 绘制坐标
    * @param vertex 顶点集合
    * @param size 顶点数量
    */
    static void DrawPolygon(Screen* s, PixelData pd, Vector2[],int size);
private:

    /*
    * @brief 绘制三角上半部分
    * @param s 要绘制的Screen对象
    * @param vertex 顶点集合
    */
    static void DrawTopTriAngle(Screen* s, PixelData pd, Vector2[3]);

    /*
    * @brief 绘制三角下半部分
    * @param s 要绘制的Screen对象
    * @param vertex 顶点集合
    */
    static void DrawBottomTriAngle(Screen* s, PixelData pd, Vector2[3]);
};

#endif