/*
* ���泣���༰��������
*/

#ifndef _ENGINNE_H_
#define _ENGINNE_H_

#include<iostream>
#include<sstream>
using namespace std;


class Vector2
{
public:
	float x;//x����
	float y;//y����

	Vector2();
	Vector2(float,float);

	//���������
	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator*(const float);
	Vector2 operator/(const float);
	//ת��Ϊ�ַ���
	string ToString();
};

class Time
{
public:
	static float time;
	static float deltaTime;
};
#endif
