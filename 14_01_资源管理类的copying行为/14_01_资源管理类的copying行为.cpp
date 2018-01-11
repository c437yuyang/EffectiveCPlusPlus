// 14_01_资源管理类的copying行为.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <memory>
class Mutex;
void lock(Mutex*);
void unlock(Mutex*);

//下面这个类实现对于mutex的管理，是加锁和解锁这里不是闪出去
class Lock
{
public:
	explicit Lock(Mutex* pm):mutexPtr(pm)
	{
		lock(mutexPtr);
	}
	~Lock()
	{
		unlock(mutexPtr);
	}
private:
	Mutex *mutexPtr;
};

//但是这样的RAII类，被复制的时候语义就不对了
//因此有以下四种情形一般:
//1.禁止复制，private继承自uncopyable即可。
//2.对底层资源使用引用计数,因此把mutex* 改成 shared_ptr<Mutex>即可，再定制一个删除器(auto_ptr不能定制删除器，永远都是delete操作)，这里就是unlock即可。
//此时的代码:
class Lock
{
public:
	explicit Lock(Mutex* pm) :mutexPtr(pm,unlock) //这里传入删除器进行构造
	{
		lock(mutexPtr.get());
	}
	//去掉析构函数了
private:
	std::shared_ptr<Mutex> mutexPtr;
};

//3.复制底部资源，也就是深拷贝，这时自己改写copying函数即可。
//4.转移底部资源的拥有权，这时使用auto_ptr即可。


int main()
{
    return 0;
}

