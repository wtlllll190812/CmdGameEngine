#include "DebugLog.h"

Debug::Debug()
{
	time_t curtime;
	struct tm t ;

	time(&curtime);
	char buffer[80]; 
	localtime_s(&t, &curtime);
	strftime(buffer, 80, "%Y-%m-%d_%H_%M_%S", &t);
	
	string fileName=buffer;
	file.open(".\\Log\\Log"+fileName + ".txt", ios::out);

}

Debug::~Debug()
{
	file.close();
}

void Debug::Log(string message)
{
	file << message << endl;
}

Debug& Debug::Instance()
{
	static Debug* instance = new Debug();
	return *instance;
}
