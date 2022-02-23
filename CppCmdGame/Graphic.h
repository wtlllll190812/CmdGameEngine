#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "Screen.h"
#include "Engine.h"
#include<cmath>

class Graphic
{
public:
    static void DrawCircle(Screen *s, int x, int y, int R);
    static void DrawRect(Screen *s, int x, int y, int w, int h);
    static void DrawTriAngle(Screen* s, Vector2[3]);
    static void DrawPolygon(Screen* s, Vector2[],int size);
private:
    static void DrawTopTriAngle(Screen* s, Vector2[3]);
    static void DrawBottomTriAngle(Screen* s, Vector2[3]);
};

#endif