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
		Graphic::DrawRect(s, Vector2((tr->position->x * 10 + 5) / 10, (tr->position->y * 10 + 5) / 10), 4, 5);
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
	(*position) = (*position) - angle * speed;
	Debug::Instance().Log("Move to"+position->ToString());
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

RigitBody::RigitBody()
{
	gravity = 4.9;
	mass = 1;
	tr = nullptr;
}

void RigitBody::AddForce(Vector2 _force,forceMode mode)
{
	if(mode==forceMode::force)
		force =force+ _force;
	else
	{
		forceFrame = forceFrame + _force;
	}
}

void RigitBody::OnAdd()
{
	tr = dynamic_cast<Transform*>(owner->GetComponent<Transform>());
}

void RigitBody::OnRemove()
{
}

void RigitBody::OnUpdate()
{
	Vector2 a = (force +forceFrame+ Vector2(0, gravity))/ mass;
	velocity = velocity + a * Time::deltaTime / 1000;

	tr->Translate(velocity, -Time::deltaTime / 1000);
	forceFrame = Vector2(0,0);
}

void Collider::OnAdd()
{
}

void Collider::OnRemove()
{
}

void Collider::OnUpdate()
{
}
