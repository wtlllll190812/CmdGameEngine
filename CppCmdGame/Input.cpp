#include "Input.h"
#include "DebugLog.h"

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

Input &Input::Instance()
{
	static Input *instance = new Input();
	return *instance;
}

bool Input::GetKeyDown(KeyCode code)
{
	if (KEYDOWN((int)code))
	{
		Debug::Instance().Log("GetInput");
		return true;
	}
	return false;
}
