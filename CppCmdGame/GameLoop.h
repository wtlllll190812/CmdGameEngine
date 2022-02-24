#ifndef GAMELOOP_H_
#define GAMELOOP_H_
#include <windows.h>

#include "Engine.h"
/*
* ��Ϸ�����������ڿ���
*/
class GameLoop
{
private:
    float frame;//��Ϸ֡��
    DWORD lastFrame;//��һ֡�¼�

public:

    /*
    * @brief ÿ֡����һ��
    * @param f �ص�����
    */
    void FixedUpdate(void (*f)(void));
    
    /*
    * @brief ��������
    * @param f �ص�����
    */
    void Update(void (*f)(void));
    GameLoop(float frame);
};

#endif
