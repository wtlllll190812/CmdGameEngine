#ifndef _DEBUGLOG_H_
#define _DEBUGLOG_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>

using namespace std;

/*
* @brief �ṩ���õ�Debug����
* ��ǰֻ�в����Ƶ�������־�ļ�����
*/
class Debug
{
public:

	/*
	* @brief ������־�ļ�
	*/
	Debug();
	
	/*
	* @brief ����ʱ�رղ�������־�ļ�
	*/
	~Debug();
	
	/*
	* @brief д����־�ļ�
	* @param message д�������
	*/
	void Log(string message);

	/*
	* @brief д����־�ļ�
	* @param message д�������
	*/
	void Log(char* message);

	/*
	* @brief д����־�ļ�
	* @param message д�������
	*/
	void Log(int message);

	/*
	* @brief ��ȡDebug��ĵ���
	*/
	static Debug& Instance();
private:
	ofstream file;//��־�ļ�
};
#endif
