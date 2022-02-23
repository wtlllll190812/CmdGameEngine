#include "Graphic.h"
#include "DebugLog.h"

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

void Graphic::DrawCircle(Screen* s, int x, int y, int R)
{
    
}

void Graphic::DrawPolygon(Screen* s,Vector2 vertex[],int size)
{
    Vector2 mid;

    for (int i = 0; i < size; i++)
    {
        mid = mid + vertex[i] / size;
    }

    for (size_t i = 0; i <= size-1; i++)
    {
        Vector2 vertexP[3]{ vertex[i],i!=size-1?vertex[i + 1]:vertex[0],mid};
        
        DrawTriAngle(s,vertexP);
    }
}

void Graphic::DrawTriAngle(Screen* s, Vector2 vertex[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (vertex[i].y < vertex[j].y)
            {           
                Vector2 temp;
                temp = vertex[i];
                vertex[i] = vertex[j];
                vertex[j] = temp;
            }
        }
    }
    
    if (vertex[0].y == vertex[1].y)
    {
        DrawBottomTriAngle(s,vertex);
    }
    else if (vertex[1].y==vertex[2].y)
    {      
        DrawTopTriAngle(s, vertex);
    }
    else
    {
        int midX = (int)(vertex[2].x + ((vertex[1].y - vertex[2].y) / (vertex[0].y - vertex[2].y)) * (vertex[0].x - vertex[2].x));
        Vector2 mid (midX,vertex[1].y);

        Vector2 top[3]{ vertex[0], vertex[1], mid };
        DrawTopTriAngle(s, top); 
        Vector2 bottom[3]{ vertex[1], mid, vertex[2] };
        DrawBottomTriAngle(s, bottom);
    }
}

void Graphic::DrawTopTriAngle(Screen* s, Vector2 vertex[3])
{
    bool dir=(vertex[1].x < vertex[2].x);

    float p1 = (float)(vertex[0].x - vertex[1].x) / (vertex[0].y - vertex[1].y);
    float p2 = (float)(vertex[0].x - vertex[2].x) / (vertex[0].y - vertex[2].y);

    if (!dir)
    {
        float t = p1;
        p1 = p2;
        p2 = t;
    }
        
    float startX = dir ? vertex[1].x : vertex[2].x;
    float endX = dir ? vertex[2].x : vertex[1].x;

    for (int scanLineY = vertex[2].y; scanLineY <= vertex[0].y; scanLineY++)
    {
        for (int scanlineX = (int)startX; scanlineX <= (int)endX; scanlineX++)
        {
            s->DrawPixel(scanlineX, scanLineY, "#", 15);
        }
        startX += p1;
        endX += p2;
    }
}

void Graphic::DrawBottomTriAngle(Screen* s, Vector2 vertex[3])
{
    bool dir = (vertex[1].x < vertex[0].x);

    float p1 = (float)(vertex[1].x - vertex[2].x) / (vertex[1].y - vertex[2].y);
    float p2 = (float)(vertex[0].x - vertex[2].x) / (vertex[0].y - vertex[2].y);
    
    if (!dir)
    {
        float t = p1;
        p1 = p2;
        p2 = t;
    }
    
    float startX = dir ? vertex[1].x : vertex[0].x;
    float endX = dir ? vertex[0].x : vertex[1].x;

    for (int scanLineY = vertex[0].y; scanLineY >= vertex[2].y; scanLineY--)
    {
        for (int scanlineX = (int)startX; scanlineX <= (int)endX; scanlineX++)
        {
            s->DrawPixel(scanlineX, scanLineY, "#", 15);
        }
        startX -= p1;
        endX -= p2;
    }
}