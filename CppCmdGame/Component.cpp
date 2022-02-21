#include "Component.h"
#include "DebugLog.h"

#include<iostream>
using namespace std;


Component::Component()
{
	owner = nullptr;
}
void Component::OnAdd()
{
}
void Component::OnRemove()
{
}
void Component::OnUpdate()
{
}



Renderer::Renderer(Screen* screen) : Component()
{
	s = screen;
	s->Reset();
	tr = nullptr;
}
void Renderer::OnAdd()
{
	Debug::Instance().Log("Component 'Renderer' Added");
}
void Renderer::OnRemove()
{
	Debug::Instance().Log("Component 'Renderer' Removed");
}
void Renderer::OnUpdate()
{
	if (!tr)
		tr = dynamic_cast<Transform*>(owner->GetComponent<Transform>()) ;
	else
	{
		Graphic::DrawRect(s, (tr->position->x * 10 + 5) / 10, (tr->position->y * 10 + 5) / 10, 4, 5);
	}
	Debug::Instance().Log("Component 'Renderer' Updated");
}


Transform::Transform() : Component()
{
	position = new Vector2(0,0);
	Angle = new float;
	Angle = 0;
}

Transform::Transform(float x, float y)
{
	position = new Vector2(x, y);
	Angle = new float;
	Angle = 0;
}

void Transform::Translate(Vector2 angle, float speed)
{
	(*position) = (*position) + angle * speed;
	Debug::Instance().Log(position->ToString());
}

void Transform::OnAdd()
{
	Debug::Instance().Log("Component 'Transform' Added");
}

void Transform::OnRemove()
{
	Debug::Instance().Log("Component 'Transform' Removed");
}

void Transform::OnUpdate()
{
	Debug::Instance().Log("Component 'Transform' Updated");
}
