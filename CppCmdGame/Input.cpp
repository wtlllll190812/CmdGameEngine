#include "Input.h"
#include "DebugLog.h"
Input& Input::Instance()
{
	static Input* instance = new Input();
	return *instance;
}

bool Input::GetKeyDown(KeyCode k)
{
	if (_kbhit()) 
	{
		Debug::Instance().Log("GetKeyDown:K");

		if (_getch() == (int)k)
		{ 
			return true;
		}
	}//������ESCʱѭ����ESC���ļ�ֵʱ27.
	return false;
}
