/*
* ���泣���༰��������
*/

#ifndef _ENGINNE_H_
#define _ENGINNE_H_

#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;

class Vector3;
class Vector2
{
public:
	float x;//x����
	float y;//y����

	Vector2();
	Vector2(float,float);
	explicit Vector2(Vector3);

	//���������
	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator-();
	Vector2 operator*(const float);
	Vector2 operator/(const float);
	bool operator==(const Vector2& v);

	//����ת��
	operator Vector3();

	//��ѧ����
	//������ģ
	float Magnitude();
	//�����ĵ��
	float Dot(Vector2);
	//�����Ĳ��
	Vector3 Cross(Vector2);
	//������һ�������ı�ԭֵ��
	Vector2 Normalize();

	//ת��Ϊ�ַ���
	string ToString();
};
class Vector3
{
public:
	float x;//x����
	float y;//y����
	float z;//z����

	Vector3();
	Vector3(float, float,float);

	//���������
	Vector3 operator+(const Vector3);
	Vector3 operator-(const Vector3);
	Vector3 operator-();
	Vector3 operator*(const float);
	Vector3 operator/(const float);
	bool operator==(const Vector3&);

	//��ѧ����
	//������ģ
	float Magnitude();
	//�����ĵ��
	float Dot(Vector3);
	//�����Ĳ��
	Vector3 Cross(Vector3);
	//������һ�������ı�ԭֵ��
	Vector3 Normalize();

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
