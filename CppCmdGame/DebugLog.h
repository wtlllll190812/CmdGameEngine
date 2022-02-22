#ifndef _DEBUGLOG_H_
#define _DEBUGLOG_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
using namespace std;

class Debug
{
public:
	Debug();
	~Debug();
	void Log(string message);
	void Log(char* message);
	void Log(int message);
	static Debug& Instance();
private:
	ofstream file;
};
#endif
