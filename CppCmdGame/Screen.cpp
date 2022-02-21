#include <windows.h>

#include "Screen.h"

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
            if (d.data[i][j].ch != currentData->data[i][j].ch || d.data[i][j].color != currentData->data[i][j].color)
            {
                nextData->data[i][j].ch = d.data[i][j].ch;
                nextData->data[i][j].color = d.data[i][j].color;
                nextData->data[i][j].changed = true;
            }
            else if (!nextData->data[i][j].changed)
            {
                nextData->data[i][j].changed = false;
            }
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

Screen::Screen()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}
void FrameBuffer::Swap() //交换缓存区
{
    frameData *temp = nextData;
    nextData = currentData;
    currentData = temp;
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
                ScreenPrint(FB.currentData->data[i][j].ch, FB.currentData->data[i][j].color);
            }
            else
            {
                if (i < SCREENSIZE_X - 1)
                    GoToPos(i + 1, j);
                else
                    GoToPos(i, j + 1);
            }
            FB.currentData->data[i][j].changed = false;
        }
    }
}

void Screen::TestInit()
{
    frameData temp;

    for (int j = 0; j < SCREENSIZE_Y; j++)
    {
        for (int i = 0; i < SCREENSIZE_X; i++)
        {
            if (i < SCREENSIZE_X - 1)
                temp.data[i][j].ch = "#";
            else
                temp.data[i][j].ch = "\n";
            if (i > 10)
                temp.data[i][j].color = rand() % 256 + 1;
            else
                temp.data[i][j].color = 15;
        }
    }
    FB.Draw(temp);
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
    FB.DrawPixel(x, y, ch, color);
}
