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

	//����  
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
	//��ں���
	void Main()
	{
		cout << "MyThread Main" << name << ":" << age;
	}
	string name;
	int age = 100;

};


//�߳���ں���
void ThreadMain();
//������ʹ�õ�һ�����߳�
void create_thread();
//thread�����������ں͵ȴ�����
void deatch_thread();
//���̲߳�������
void ThreadMain1(int p1, float p2,string str,Para p4);
//ȫ�ֺ�����Ϊ�߳���ڲ���װ
void thread_Para();
//ָ�봫��
void ThreadMainPtr(Para* p);
//���ô���
void ThreadRef(Para& p);
//ָ������ô���
void Thread_PtrRef();



//��Ա������Ϊ�߳����



