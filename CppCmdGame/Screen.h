#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
using namespace std;

#define SCREENSIZE_X 128 //屏幕宽度
#define SCREENSIZE_Y 32  //屏幕高度

typedef struct _ScreenData //像素数据
{
    bool changed; //脏标识
    string data;  //像素内容
    int color;    //像素颜色

    //==操作符重载
    _ScreenData &operator=(const _ScreenData &value)
    {
        data = value.data;
        changed = value.changed;
        color = value.color;
        return *this;
    }
} PixelData;

typedef struct _frameData //帧数据
{
    PixelData data[SCREENSIZE_X][SCREENSIZE_Y];
} frameData;

//==操作符重载
bool operator==(const PixelData &, const PixelData &);

//帧缓存（双缓存模式）
class FrameBuffer
{
public:
    frameData *currentData;              //当前数据
    static const PixelData pixelDefault; //静态常量，像素默认值

    FrameBuffer();

    //写入数据并交换缓存区
    void Draw(frameData d);

    //逐像素写入数据
    void DrawPixel(int x, int y, string ch, int color);

    //交换缓存区并初始化缓存区
    void Swap();

private:
    frameData data[2];
    frameData *nextData;

    //初始化数据
    void DataInit();
};

//屏幕对象
class Screen
{
public:
    Screen();

    /*
     * @brief 完全清除屏幕
     */
    void Clean();

    /*
     * @brief 读取缓存区内数据并显示在屏幕上
     */
    void DisPlay();

    /*
     * @brief 重置光标位置至（0,0）处
     */
    void Reset();

    /*
     * @brief 向指定像素写入数据
     * @param x x坐标
     * @param y y坐标
     * @param ch 字符
     * @param color 颜色
     */
    void DrawPixel(int x, int y, string ch, int color);

private:
    /*
     * 向屏幕写入数据
     * @param s 字符
     * @param color 字符颜色
     */
    void ScreenPrint(string s, int color);

    /*
     * @brief 挪动光标到指定位置
     * @param x x坐标
     * @param y y坐标
     */
    void GoToPos(short x, short y);

    FrameBuffer FB; //屏幕帧缓存数据
};
#endif
