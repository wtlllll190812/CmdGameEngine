/*
 * 引擎常用类及工具声明
 */

#ifndef _ENGINNE_H_
#define _ENGINNE_H_

#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

class Vector3;
class Vector2
{
public:
	float x; // x分量
	float y; // y分量

	static  Vector2 zero;

	Vector2();
	Vector2(float, float);
	explicit Vector2(Vector3);

	//运算符重载
	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator-();
	Vector2 operator*(const float);
	Vector2 operator/(const float);
	bool operator==(const Vector2 &v);

	//类型转换
	operator Vector3();

	//数学运算
	//向量的模
	float Magnitude();
	//向量的点乘
	float Dot(Vector2);
	//向量的叉乘
	Vector3 Cross(Vector2);
	//向量归一化（不改变原值）
	Vector2 Normalize();
	//点到直线的距离
	float Distance(Vector2[2]);

	//转换为字符串
	string ToString();
};
class Vector3
{
public:
	float x; // x分量
	float y; // y分量
	float z; // z分量

	Vector3();
	Vector3(float, float, float);

	//运算符重载
	Vector3 operator+(const Vector3);
	Vector3 operator-(const Vector3);
	Vector3 operator-();
	Vector3 operator*(const float);
	Vector3 operator/(const float);
	bool operator==(const Vector3 &);

	//数学运算
	//向量的模
	float Magnitude();
	//向量的点乘
	float Dot(Vector3);
	//向量的叉乘
	Vector3 Cross(Vector3);
	//向量归一化（不改变原值）
	Vector3 Normalize();
	//点到直线的距离
	float Distance(Vector3[2]);

	//转换为字符串
	string ToString();
};
class Time
{
public:
	static float time;
	static float deltaTime;
};
class BoundBox
{
public:
	float x[2] = { FLT_MAX,FLT_MIN };
	float y[2] = { FLT_MAX,FLT_MIN };
	BoundBox(const vector<Vector2>& points);
};

#endif
