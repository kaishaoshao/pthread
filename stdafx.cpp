#include "stdafx.h"


void ThreadMain()
{
    //this_thread::get_id ����߳�id�� 
	cout << "begin first thread main" << endl;
	cout << "first thread ID:" << this_thread::get_id << endl;

	for (int i = 0; i < 10; i++)
	{
		if (!is_exit1) break;
		//���߳��е����ߺ���
		cout <<"���߳�ִ��ʱ��" << i <<"s" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "end first thread " << this_thread::get_id << endl;
}

void create_thread()
{
	cout << "main thread ID:" << this_thread::get_id() << endl;
	//�̴߳�������
	thread th(ThreadMain);
	cout << "begin wait sub thread" << endl;
	//�����ȴ����߳��˳�
	th.join();
	cout << "end wait sub thread" << endl;
}


void deatch_thread()
{
	thread th(ThreadMain);
	//th.detach(); //���߳������̷߳��� �ػ��߳�
	//�ӣ����߳��˳��� ���̲߳�һ���˳�
	this_thread::sleep_for(chrono::seconds(1));
	is_exit1 = true;
	cout << "���߳��������ȴ����߳��˳�" << endl;
	th.join();
	cout << "���߳��Ѿ��˳�" << endl;
}


void ThreadMain1(int p1, float p2, string str, Para p4)
{
	this_thread::sleep_for(100ms);
	cout << "ThreadMain1:" << p1 << " " << p2 << " " << str << " " << p4.name << endl;
}


void thread_Para()
{
	thread th;
	//ջ�ռ����һ�Դ�����֮���ͷ�
	{
		float f1 = 12.1f;
		Para p;
		p.name = "test Para class";
		//���к�������   ���󿽱�������p
		th = thread(ThreadMain1, 101, f1, "test string kk", p);
	}
	th.join();
}

void ThreadRef(Para& p)
{
	this_thread::sleep_for(100ms);
	cout << "ThreadMainPtr name=" << p.name << endl;
}



void ThreadMainPtr(Para* p)
{
	this_thread::sleep_for(100ms);
	cout << "ThreadMainPtr name=" << p->name << endl;
}

void Thread_PtrRef()
{

	//Ҫȷ������������������߳�����������һ�µ�
	{
		//��������
		Para p;
		p.name = "test Ref";
		//����ref��ʶһ�£�������������
		thread th(ThreadRef, ref(p));
		th.join();

	}
	getchar();
	{
		//�����߳�ָ��
		Para p;
		p.name = "test ThreadMainPtr name";
		thread th(ThreadMainPtr, &p);
		th.detach();
	}
	getchar();
	{
		//�����߳�ָ��
		Para p;
		p.name = "test ThreadMainPtr name";
		thread th(ThreadMainPtr, &p);
		th.join();
		getchar();
	}

}
