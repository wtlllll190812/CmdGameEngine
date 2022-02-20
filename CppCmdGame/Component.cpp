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
	Debug::Instance().Log("Component 'Renderer' Updated");
	Graphic::DrawRect(s, 10, 10, 4, 5);
}


