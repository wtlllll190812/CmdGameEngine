#ifndef GAMELOOP_H_
#define GAMELOOP_H_
#include <windows.h>

#include "Engine.h"
/*
* 游戏引擎生命周期控制
*/
class GameLoop
{
private:
    float frame;//游戏帧数
    DWORD lastFrame;//上一帧事件

public:

    /*
    * @brief 每帧运行一次
    * @param f 回调函数
    */
    void FixedUpdate(void (*f)(void));
    
    /*
    * @brief 持续运行
    * @param f 回调函数
    */
    void Update(void (*f)(void));
    GameLoop(float frame);
};

#endif
