#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "Screen.h"

class Graphic
{
public:
    static void DrawCircle(Screen *s, int x, int y, int R);
    static void DrawRect(Screen *s, int x, int y, int w, int h);
};

#endif