#pragma once
#include <iostream>
#include <thread>
#include <string>
using namespace std;

extern bool is_exit1;

class Para
{
public:
	Para() {
		cout << "Create Para" << endl;
	}

	//拷贝  
	Para(const Para& p) {
		cout << "Copy Para" << endl;
	}

	~Para() {
		cout << "Drop Para" << endl;
	}
	string name;
};

class MyThread
{
public:
	//入口函数
	void Main()
	{
		cout << "MyThread Main" << name << ":" << age;
	}
	string name;
	int age = 100;

};


//线程入口函数
void ThreadMain();
//创建并使用第一个多线程
void create_thread();
//thread对象生命周期和等待分离
void deatch_thread();
//多线程参数传递
void ThreadMain1(int p1, float p2,string str,Para p4);
//全局函数作为线程入口并封装
void thread_Para();
//指针传参
void ThreadMainPtr(Para* p);
//引用传参
void ThreadRef(Para& p);
//指针和引用传参
void Thread_PtrRef();



//成员函数作为线程入口



