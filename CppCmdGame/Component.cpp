#include "Component.h"
#include "DebugLog.h"

#include<iostream>


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



Renderer::Renderer(Screen* screen,Vector2* v,int size) : Component()
{
	s = screen;
	tr = nullptr;
	vertex = v;
	vertexNumber = size;
}
void Renderer::OnAdd()
{
	tr = dynamic_cast<Transform*>(owner->GetComponent<Transform>());
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
		Vector2* v = tr->ObjectToWorld(vertex,vertexNumber);
		Graphic::DrawPolygon(s, pixelData, v,  vertexNumber);
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
Vector2 Transform::ObjectToWorld(Vector2 ori)
{
	Vector2 res;
	res = ori + (*position);
	return res;
}
Vector2* Transform::ObjectToWorld(Vector2* ori, int size)
{
	Vector2 *res=new Vector2[size];
	for (int i = 0; i < size; i++)
	{
		res[i] = ori[i] + *position;
	}
	return res;
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



RigidBody::RigidBody()
{
	gravity = 4.9;
	mass = 1;
	tr = nullptr;
	col = nullptr;
	drag = 0.1f;
}
void RigidBody::AddForce(Vector2 _force,forceMode mode)
{
	if(mode==forceMode::force)
		force =force+ _force;
	else
	{
		forceFrame = forceFrame + _force;
	}
}
void RigidBody::OnAdd()
{
	Debug::Instance().Log("Component 'RigitBody' Added");
	tr = dynamic_cast<Transform*>(owner->GetComponent<Transform>());
}
void RigidBody::OnRemove()
{
	Debug::Instance().Log("Component 'RigitBody' Removed");
}
void RigidBody::OnUpdate()
{
	Debug::Instance().Log("Component 'RigitBody' Updated");
	//������ٶ�
	Vector2 dragForce;
	if(velocity.Magnitude()>0)
		dragForce = -velocity.Normalize() * pow(velocity.Magnitude(), 2) * drag;
	Vector2 a = (force +forceFrame+ Vector2(0, gravity)+ dragForce)/ mass;

	Debug::Instance().Log("a: ");

	Debug::Instance().Log(velocity.Magnitude());
	//�����ٶ�
	velocity = velocity + a * Time::deltaTime / 1000;

	//�ƶ�����
	tr->Translate(velocity, -Time::deltaTime / 1000);
	forceFrame = Vector2(0,0);	
}
float minOrMax(Vector2 *v,int size,bool isMax,bool isAxisY)
{
	Vector2 res=v[0];
	for (int i = 0; i < size; i++)
	{
		if (isMax == (isAxisY?(v[i].y > res.y):(v[i].x > res.x)))
			res = v[i];	
	}
	return isAxisY? res.y:res.x;
}
Vector2 RigidBody::SAT(Collider* col2)
{		
	Vector2 res(0,0);

	if (!col)
		col = dynamic_cast<Collider*>(owner->GetComponent<Collider>());
	else
	{
		Vector2* c1 = tr->ObjectToWorld(col->vertex, col->vertexNumber);
		Vector2* c2 = col2->tr->ObjectToWorld(col2->vertex, col2->vertexNumber);

		Debug::Instance().Log(minOrMax(c1, col->vertexNumber, true, false) );
		Debug::Instance().Log(minOrMax(c1, col->vertexNumber, false, false) );
		Debug::Instance().Log(minOrMax(c2, col2->vertexNumber, false, false));
		Debug::Instance().Log(minOrMax(c2, col2->vertexNumber, true, false));

		Vector2 mmX(minOrMax(c2, col2->vertexNumber, false, false), minOrMax(c2, col2->vertexNumber, true, false));
		Vector2 mmY(minOrMax(c2, col2->vertexNumber, false, true), minOrMax(c2, col2->vertexNumber, true, true));

		res.x = max(mmX.x -minOrMax(c1,  col->vertexNumber, true, false), minOrMax(c1, col->vertexNumber, false, false) - mmX.y);
		res.y = max(mmY.x -minOrMax(c1,  col->vertexNumber, true, true), minOrMax(c1, col->vertexNumber, false, true) - mmY.y);

		/*res = (minOrMax(c1, col->vertexNumber, true, false) > mmX.x
			&& minOrMax(c1, col->vertexNumber, true, false) < mmX.y)
			|| (minOrMax(c1, col->vertexNumber, false, false) > mmX.x
			&& minOrMax(c1, col->vertexNumber, false, false) < mmX.y);

		res =res&& (minOrMax(c1, col->vertexNumber, true, true) > mmY.x
				&& minOrMax(c1, col->vertexNumber, true, true) < mmY.y)
				|| (minOrMax(c1, col->vertexNumber, false, true) > mmY.x
				&& minOrMax(c1, col->vertexNumber, false, true) < mmY.y);*/
	}
	return res;
}
bool RigidBody::GJK(Collider* col2)
{
	if (!col)
		col = dynamic_cast<Collider*>(owner->GetComponent<Collider>());
	//ת��Ϊ��������
	Vector2* c1 = tr->ObjectToWorld(col->vertex, col->vertexNumber);
	Vector2* c2 = col2->tr->ObjectToWorld(col2->vertex, col2->vertexNumber);
	//������
	vector<Vector2> simplex;
	//�����ʼ����
	Vector2 d = ((*col2->tr->position)-(*tr->position)).Normalize();
	//���һ��֧��
	simplex.push_back(Support(d, c1, col->vertexNumber) - Support(-d, c2, col2->vertexNumber));

	//�����Ϊ������
	d = -simplex.front();
	//��ʼ����
	while (1)
	{
		Vector2 A = Support(d, c1, col->vertexNumber) - Support(-d, c2, col2->vertexNumber);
		//���µĵ㲻����ԭ��
		if (A.Dot(d) < 0)
		{
			return false;
		}

		simplex.push_back(A);

		if (HandlerSimplex(d,simplex))
		{
			return true;
		}
	}
}

bool RigidBody::HandlerSimplex(Vector2& dir, vector<Vector2>& simplex)
{
	if (simplex.size() == 2)//��ֻ��һ����ʱ
	{
		//��������AO��AB
		Vector2 AO = -simplex.back();
		Vector2 AB = simplex.front() - simplex.back();
		//����AO�ķ�����
		Vector3 ABperp = AB.Cross(AO).Cross(AB);
		//����������Ϊ�µķ���
		dir = (Vector2)ABperp.Normalize();
		return false;
	}
	else
	{
		//������Ҫ������
		Vector2 AO = - simplex.back();
		Vector2 AB = simplex.front() - simplex.back();
		Vector2 AC = *(simplex.begin()+1) - simplex.back();
		//����AB��AC������
		Vector3 ABperp = AC.Cross(AB).Cross(AB).Normalize();
		Vector3 ACperp = AB.Cross(AC).Cross(AC).Normalize();

		Debug::Instance().Log(ABperp.Dot(AO));
		Debug::Instance().Log(ACperp.Dot(AO));


		//�ж�ԭ��λ��
		if (ABperp.Dot(AO) > 0)
		{			

			simplex.erase(simplex.begin()+1);
			dir = (Vector2)ABperp;
			return false;
		}
		else if (ACperp.Dot(AO) > 0)
		{

			simplex.erase(simplex.begin());
			dir = (Vector2)ACperp;
			return false;
		}

		return true;
	}
}
Vector2 RigidBody::Support(Vector2 dir, Vector2* vertex, int size)
{
	Vector2 res;
	int max=0;

	for (int i = 0; i < size; i++)
	{
		int d = dir.Dot(vertex[i]);
		if (d > max)
		{
			max = d;
			res = vertex[i];
		}
	}


	return res;
}


Collider::Collider(Vector2 data[],int size)
{
	vertex = data;
	vertexNumber = size;
	tr = nullptr;
}
void Collider::OnAdd()
{
	Debug::Instance().Log("Component 'Collider' Added");
	tr=dynamic_cast<Transform*>(owner->GetComponent<Transform>());
}
void Collider::OnRemove()
{
	Debug::Instance().Log("Component 'Collider' Removed");
}
void Collider::OnUpdate()
{
	Debug::Instance().Log("Component 'Collider' Updated");
}
