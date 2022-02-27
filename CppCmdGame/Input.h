#ifndef _INPUT_H_
#define _INPUT_H_

#include <conio.h>
#include <iostream>
#include <format>
#include <windows.h>

using namespace std;

/*
 * @brief 按键键位枚举
 */
enum class KeyCode
{
	BackSpace = 8,
	Tab,
	Clear = 12,
	Enter,
	Shift = 16,
	Control,
	Alt,
	CapeLock = 20,
	Esc = 27,
	Space = 32,
	PageUp,
	PageDown,
	End,
	Home,
	LeftArrow,
	UpArrow,
	RightArrow,
	DownArrow,

	A0 = 48,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A8,
	A9,

	A = 65,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,

};

/*
 * @brief 输入管理类
 */
class Input
{
public:
	/*
	 * @brief 返回Input的单例
	 */
	static Input &Instance();

	/*
	 * @brief 获取按键状态
	 * @return 按键是否按下
	 * @param 按键枚举
	 */
	bool static GetKeyDown(KeyCode k);
};

#endif
