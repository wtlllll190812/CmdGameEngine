#include "Graphic.h"

void Graphic::DrawRect(Screen *s, int x, int y, int w, int h)
{
    for (int i = x - w / 2; i < x + w - w / 2; i++)
    {
        for (int j = y - h / 2; j < y + h - h / 2; j++)
        {
            s->DrawPixel(i, j, "#", 15);
        }
    }
}
void Graphic::DrawCircle(Screen *s, int x, int y, int R)
{
}