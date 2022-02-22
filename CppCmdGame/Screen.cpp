#include <windows.h>

#include "Screen.h"
#include "DebugLog.h"

const PixelData FrameBuffer::PZero = { false,"#",0 };

FrameBuffer::FrameBuffer()
{
    currentData = &data[0];
    nextData = &data[1];
}

void FrameBuffer::Draw(frameData d) //写入数据
{
    for (int j = 0; j < SCREENSIZE_Y; j++)
    {
        for (int i = 0; i < SCREENSIZE_X; i++)
        {
            nextData->data[i][j].ch = d.data[i][j].ch;
            nextData->data[i][j].color = d.data[i][j].color;
        }
    }
}

void FrameBuffer::DataInit()
{
    for (int j = 0; j < SCREENSIZE_Y; j++)
    {
        for (int i = 0; i < SCREENSIZE_X; i++)
        {
            if (nextData->data[i][j] == currentData->data[i][j])
                nextData->data[i][j].changed = false;
            else
            {
                nextData->data[i][j].changed = true;
            }
            currentData->data[i][j] = PZero;
        }
    }
}

void FrameBuffer::DrawPixel(int x, int y, string ch, int color)
{
    if (ch != nextData->data[x][y].ch || color != nextData->data[x][y].color)
    {
        nextData->data[x][y].ch = ch;
        nextData->data[x][y].color = color;
        nextData->data[x][y].changed = true;
    }
}

void FrameBuffer::Swap() //交换缓存区
{
    DataInit();
    frameData *temp = nextData;
    nextData = currentData;
    currentData = temp;
}

Screen::Screen()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void Screen::Clean(void)
{
    system("cls");
}

void Screen::Reset()
{
    GoToPos(0, 0);
}

void Screen::DisPlay(void)
{
    FB.Swap();
    for (int j = 0; j < SCREENSIZE_Y; j++)
    {
        for (int i = 0; i < SCREENSIZE_X; i++)
        {          
            if (FB.currentData->data[i][j].changed)
            {
                GoToPos(i, j);
                ScreenPrint(FB.currentData->data[i][j].ch, FB.currentData->data[i][j].color);
            }
        }
        ScreenPrint("\n",0);
    }
}

void Screen::ScreenPrint(string s, int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << s;
}

void Screen::GoToPos(short x, short y)
{
    COORD c{x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Screen::DrawPixel(int x, int y, string ch, int color)
{
    if (x > SCREENSIZE_X || y > SCREENSIZE_Y || x < 0 || y < 0)
    {
        return;
    }
    FB.DrawPixel(x, y, ch, color);
}

bool operator==(const PixelData& p1, const PixelData& p2)
{
    return p1.ch==p2.ch&&p1.color==p2.color;
}


