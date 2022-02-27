#include "Engine.h"

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(float _x, float _y)
{
    this->x = _x;
    this->y = _y;
}

Vector2::Vector2(Vector3 v)
{
    x = v.x;
    y = v.y;
}

Vector2 Vector2::operator+(const Vector2 vector)
{
    Vector2 res;
    res.x = this->x + vector.x;
    res.y = this->y + vector.y;
    
    return res;
}

Vector2 Vector2::operator-(const Vector2 vector)
{
    Vector2 res;
    res.x = x - vector.x;
    res.y = y - vector.y;

    return res;
}

Vector2 Vector2::operator-()
{
    Vector2 res;
    res.x = -x;
    res.y = -y;
    return res;
}

Vector2 Vector2::operator*(const float s)
{
    Vector2 res;
    res.x = this->x * s;
    res.y = this->y * s;

    return res;
}

Vector2 Vector2::operator/(const float s)
{
    Vector2 res;
    res.x = this->x / s;
    res.y = this->y / s;

    return res;
}

bool Vector2::operator==(const Vector2& v)
{
    return x == v.x && y == v.y;
}

Vector2::operator Vector3()
{
    return Vector3(x,y,0);
}

float Vector2::Magnitude()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::Dot(Vector2 v)
{
    float res;
    res = x * v.x;
    res += y * v.y;
    return res;
}

Vector3 Vector2::Cross(Vector2 v)
{
    Vector3 v1 = (Vector3) * this;
    Vector3 v2 = (Vector3)v;

    return v1.Cross(v2);
}

Vector2 Vector2::Normalize()
{
    Vector2 res;
    res.x =x/ Magnitude();
    res.y =y/ Magnitude();
    return res;
}

string Vector2::ToString()
{
    ostringstream temp;
    temp << "x: "<<x<<" ";
    temp << "y: "<<y;
    string s = temp.str();
    return s;
}


Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

Vector3 Vector3::operator+(const Vector3 vector)
{
    Vector3 res;
    res.x = x + vector.x;
    res.y = y + vector.y;
    res.z = z + vector.z;

    return res;
}

Vector3 Vector3::operator-(const Vector3 vector)
{
    Vector3 res;
    res.x = x - vector.x;
    res.y = y - vector.y;
    res.z = z - vector.z;

    return res;
}

Vector3 Vector3::operator-()
{
    Vector3 res;
    res.x = -x;
    res.y = -y;
    res.z = -z;
    return res;
}

Vector3 Vector3::operator*(const float s)
{
    Vector3 res;
    res.x = x * s;
    res.y = y * s;
    res.z = z * s;

    return res;
}

Vector3 Vector3::operator/(const float s)
{
    Vector3 res;
    res.x = x / s;
    res.y = y / s;
    res.z = z / s;

    return res;
}

bool Vector3::operator==(const Vector3& v)
{
    return x==v.x&&y==v.y&&z==v.z;
}

float Vector3::Magnitude()
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z,2));
}

float Vector3::Dot(Vector3 v)
{
    float res;
    res = x * v.x;
    res += y * v.y;
    res += z * v.z;
    return res;
}

Vector3 Vector3::Cross(Vector3 v)
{
    Vector3 res;
    res.x = y * v.z - v.y * z;
    res.y = z * v.x - v.z * x;
    res.z = x * v.y - v.x * y;
    return res;
}

Vector3 Vector3::Normalize()
{
    Vector3 res;
    res.x = x / Magnitude();
    res.y = y / Magnitude();
    res.z = z / Magnitude();
    return res;
}

string Vector3::ToString()
{
    ostringstream temp;
    temp << "x: " << x << " ";
    temp << "y: " << y << " ";
    temp << "z: " << z;
    string s = temp.str();
    return s;
}


float Time::deltaTime = 0;
float Time::time = 0;


