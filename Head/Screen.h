#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
using namespace std;

#define SCREENSIZE_X 129
#define SCREENSIZE_Y 32

typedef struct _ScreenData //像素数据
{
    bool changed; //脏标识
    string ch;
    int color;
    _ScreenData()
    {
        changed = false;
        ch = "#";
        color = 01;
    }
} PixelData;

typedef struct _frameData //帧数据
{
    PixelData data[SCREENSIZE_X][SCREENSIZE_Y];
} frameData;

//帧缓存（双缓存模式）
class FrameBuffer
{
public:
    frameData *currentData; //当前数据

    FrameBuffer();
    void Draw(frameData d); //写入数据并交换缓存区
    void DrawPixel(int x, int y, string ch, int color);
    void Swap(); //交换缓存区

private:
    frameData data[2];
    frameData *nextData;
};

class Screen
{
public:
    void Clean();
    void DisPlay();
    void TestInit();
    void Reset();
    void ScreenPrint(string s, int color);
    void GoToPos(short x, short y);
    void DrawPixel(int x, int y, string ch, int color);

private:
    FrameBuffer FB;
};
#endif
