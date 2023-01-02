#include "stdafx.h"


void ThreadMain()
{
    //this_thread::get_id 获得线程id号 
	cout << "begin first thread main" << endl;
	cout << "first thread ID:" << this_thread::get_id << endl;

	for (int i = 0; i < 10; i++)
	{
		if (!is_exit1) break;
		//多线程中的休眠函数
		cout <<"子线程执行时间" << i <<"s" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "end first thread " << this_thread::get_id << endl;
}

void create_thread()
{
	cout << "main thread ID:" << this_thread::get_id() << endl;
	//线程创建启动
	thread th(ThreadMain);
	cout << "begin wait sub thread" << endl;
	//阻塞等待子线程退出
	th.join();
	cout << "end wait sub thread" << endl;
}


void deatch_thread()
{
	thread th(ThreadMain);
	//th.detach(); //子线程与主线程分离 守护线程
	//坑：主线程退出后 子线程不一定退出
	this_thread::sleep_for(chrono::seconds(1));
	is_exit1 = true;
	cout << "主线程阻塞，等待子线程退出" << endl;
	th.join();
	cout << "子线程已经退出" << endl;
}


void ThreadMain1(int p1, float p2, string str, Para p4)
{
	this_thread::sleep_for(100ms);
	cout << "ThreadMain1:" << p1 << " " << p2 << " " << str << " " << p4.name << endl;
}


void thread_Para()
{
	thread th;
	//栈空间会在一对大括号之间释放
	{
		float f1 = 12.1f;
		Para p;
		p.name = "test Para class";
		//所有函数复制   对象拷贝了三次p
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

	//要确保对象的生命周期与线程生命周期是一致的
	{
		//传递引用
		Para p;
		p.name = "test Ref";
		//采用ref标识一下，表明其是引用
		thread th(ThreadRef, ref(p));
		th.join();

	}
	getchar();
	{
		//传递线程指针
		Para p;
		p.name = "test ThreadMainPtr name";
		thread th(ThreadMainPtr, &p);
		th.detach();
	}
	getchar();
	{
		//传递线程指针
		Para p;
		p.name = "test ThreadMainPtr name";
		thread th(ThreadMainPtr, &p);
		th.join();
		getchar();
	}

}
