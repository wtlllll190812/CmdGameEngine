#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "Screen.h"
#include "Engine.h"
#include<cmath>

/*
* @brief ͼ��������
*/
class Graphic
{
public:
    
    /*
    * @brief ��һ��Բ
    * @param s Ҫ���Ƶ�Screen����
    * @param pos Բ������
    * @param R ֱ��
    */
    static void DrawCircle(Screen *s, Vector2 pos, int R);
    
    /*
    * @brief ��һ������
    * @param s Ҫ���Ƶ�Screen����
    * @param pos ��������
    * @param w ���ο��
    * @param h ���θ߶�
    */
    static void DrawRect(Screen *s, Vector2 pos, int w, int h);

    /*
    * @brief ��һ������
    * @param s Ҫ���Ƶ�Screen����
    * @param vertex ���㼯��
    */
    static void DrawTriAngle(Screen* s, PixelData pd, Vector2[3]);

    /*
    * @brief ��һ�������
    * ���ƶ���Σ�Ŀǰֻ֧��͹�����
    * @param s Ҫ���Ƶ�Screen����
    * @param pos ��������
    * @param vertex ���㼯��
    * @param size ��������
    */
    static void DrawPolygon(Screen* s, PixelData pd, Vector2[],int size);
private:

    /*
    * @brief ���������ϰ벿��
    * @param s Ҫ���Ƶ�Screen����
    * @param vertex ���㼯��
    */
    static void DrawTopTriAngle(Screen* s, PixelData pd, Vector2[3]);

    /*
    * @brief ���������°벿��
    * @param s Ҫ���Ƶ�Screen����
    * @param vertex ���㼯��
    */
    static void DrawBottomTriAngle(Screen* s, PixelData pd, Vector2[3]);
};

#endif