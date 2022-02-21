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
	}//当按下ESC时循环，ESC键的键值时27.
	return false;
}
