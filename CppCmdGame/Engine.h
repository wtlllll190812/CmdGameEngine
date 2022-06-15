/*
 * ���泣���༰��������
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
	float x; // x����
	float y; // y����

	static  Vector2 zero;

	Vector2();
	Vector2(float, float);
	explicit Vector2(Vector3);

	//���������
	Vector2 operator+(const Vector2);
	Vector2 operator-(const Vector2);
	Vector2 operator-();
	Vector2 operator*(const float);
	Vector2 operator/(const float);
	bool operator==(const Vector2 &v);

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
	//�㵽ֱ�ߵľ���
	float Distance(Vector2[2]);

	//ת��Ϊ�ַ���
	string ToString();
};
class Vector3
{
public:
	float x; // x����
	float y; // y����
	float z; // z����

	Vector3();
	Vector3(float, float, float);

	//���������
	Vector3 operator+(const Vector3);
	Vector3 operator-(const Vector3);
	Vector3 operator-();
	Vector3 operator*(const float);
	Vector3 operator/(const float);
	bool operator==(const Vector3 &);

	//��ѧ����
	//������ģ
	float Magnitude();
	//�����ĵ��
	float Dot(Vector3);
	//�����Ĳ��
	Vector3 Cross(Vector3);
	//������һ�������ı�ԭֵ��
	Vector3 Normalize();
	//�㵽ֱ�ߵľ���
	float Distance(Vector3[2]);

	//ת��Ϊ�ַ���
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
