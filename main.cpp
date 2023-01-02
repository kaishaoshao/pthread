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
	//成员函数的访问是通过地址的，通过传递myth的地址访问Main
	thread th(&MyThread::Main,&myth);
	th.join();
	return 0;
}