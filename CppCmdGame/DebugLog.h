#ifndef _DEBUGLOG_H_
#define _DEBUGLOG_H_

#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

class Debug
{
public:
	Debug();
	~Debug();
	void Log(string message);
	static Debug& Instance();
private:
	ofstream file;
};
#endif
