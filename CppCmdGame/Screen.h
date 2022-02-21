#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
using namespace std;

#define SCREENSIZE_X 128
#define SCREENSIZE_Y 32

typedef struct _ScreenData //像素数据
{
    bool changed; //脏标识
    string ch;
    int color;
   
    _ScreenData& operator=(const _ScreenData& value)
    {
        ch = value.ch;
        changed = value.changed;
        color = value.color;
        return *this;
    }
} PixelData;

typedef struct _frameData //帧数据
{
    PixelData data[SCREENSIZE_X][SCREENSIZE_Y];
} frameData;

bool operator==(const PixelData&, const PixelData&);

//帧缓存（双缓存模式）
class FrameBuffer
{
public:
    frameData *currentData; //当前数据
    static const PixelData PZero;
    FrameBuffer();
    void Draw(frameData d); //写入数据并交换缓存区
    void DrawPixel(int x, int y, string ch, int color);
    void Swap(); //交换缓存区
    void DataInit();//初始化数据

private:
    frameData data[2];
    frameData *nextData;
};

class Screen
{
public:
    Screen();
    void Clean();
    void DisPlay();
    void Reset();
    void ScreenPrint(string s, int color);
    void GoToPos(short x, short y);
    void DrawPixel(int x, int y, string ch, int color);

private:
    FrameBuffer FB;
};
#endif
