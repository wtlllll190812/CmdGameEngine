#ifndef _ENGINNE_H_
#define _ENGINNE_H_

#include<iostream>
#include<sstream>
using namespace std;
class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float,float);
	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator*(const float);
	Vector2 operator/(const float);
	string ToString();
};
#endif
