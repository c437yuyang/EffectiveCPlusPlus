// 06_01拒绝使用自动生成的函数.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;

class TestNoCopy
{
private:
	TestNoCopy(const TestNoCopy&); //声明为public必须有实现，否则会报错，声明为private可以没有实现，代表删除这个函数
	TestNoCopy& operator=(const TestNoCopy&);
};

class UnCopyable
{
protected:
	UnCopyable() {}
	~UnCopyable() {}
private:
	UnCopyable(const UnCopyable&);
	UnCopyable& operator=(const UnCopyable&);
};

class Derived :private UnCopyable
{

}; //现在子类只要private继承自这个类就可以了，因为父类如果没有copying函数的话，子类的无法处理父类的成员部分（但是不能再去手动声明public的copying函数，否则还是可以拷贝的）

int main()
{
	Derived d1;
	Derived d2(d1);
	system("pause");
	return 0;
}