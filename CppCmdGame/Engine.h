/*
* 引擎常用类及工具声明
*/

#ifndef _ENGINNE_H_
#define _ENGINNE_H_

#include<iostream>
#include<sstream>
using namespace std;


class Vector2
{
public:
	float x;//x分量
	float y;//y分量

	Vector2();
	Vector2(float,float);

	//运算符重载
	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator*(const float);
	Vector2 operator/(const float);
	//转换为字符串
	string ToString();
};

class Time
{
public:
	static float time;
	static float deltaTime;
};
#endif
