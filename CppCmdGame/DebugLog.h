#ifndef _DEBUGLOG_H_
#define _DEBUGLOG_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>

using namespace std;

/*
* @brief 提供常用的Debug方法
* 当前只有不完善的生成日志文件功能
*/
class Debug
{
public:

	/*
	* @brief 生成日志文件
	*/
	Debug();
	
	/*
	* @brief 销毁时关闭并保存日志文件
	*/
	~Debug();
	
	/*
	* @brief 写入日志文件
	* @param message 写入的内容
	*/
	void Log(string message);

	/*
	* @brief 写入日志文件
	* @param message 写入的内容
	*/
	void Log(char* message);

	/*
	* @brief 写入日志文件
	* @param message 写入的内容
	*/
	void Log(int message);

	/*
	* @brief 获取Debug类的单例
	*/
	static Debug& Instance();
private:
	ofstream file;//日志文件
};
#endif
