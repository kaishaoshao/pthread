#include "stdafx.h"
#include <iostream>
#include <thread>

using namespace std;

bool is_exit1 = false;

int main(int argc,char* argv[])
{
	MyThread myth;
	myth.name = "Test name 001";
	myth.age = 20;
	//��Ա�����ķ�����ͨ����ַ�ģ�ͨ������myth�ĵ�ַ����Main
	thread th(&MyThread::Main,&myth);
	th.join();
	return 0;
}