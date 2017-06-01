// 06_01拒绝使用自动生成的函数.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;

class TestNoCopy{
private:
	TestNoCopy(const TestNoCopy&); //声明为public必须有实现，否则会报错，声明为private可以没有实现，代表删除这个函数
	TestNoCopy& operator=(const TestNoCopy&);
};

class UnCopyable{
protected:
	UnCopyable();
	~UnCopyable();
private:
	UnCopyable(const UnCopyable&);
	UnCopyable& operator=(const UnCopyable&);
};

class Derived:private UnCopyable{}; //现在子类只要继承自这个类就可以了

int main()
{

	system("pause");
	return 0;
}