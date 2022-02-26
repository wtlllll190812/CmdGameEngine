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
    res.x = this->x - vector.x;
    res.y = this->y - vector.y;

    return res;
}

Vector2 Vector2::operator-()
{
    this->x = -this->x;
    this->y = -this->y;
    return Vector2();
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

float Vector2::Magnitude()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

string Vector2::ToString()
{
    ostringstream temp;
    temp << x;
    temp << y;
    string s = temp.str();
    return s;
}

float Time::deltaTime = 0;
float Time::time = 0;
