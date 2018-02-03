// 05_00_空类自动生成的函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//class TestClass{}; //声明一个空类型


//等价于:
class TestClass
{
public:
	TestClass();
	~TestClass();
	TestClass(const TestClass&);
	TestClass& operator=(const TestClass&);
};

class Widget 
{
public:
	Widget(const Widget& rhs) {}

};

int main()
{
	Widget w; //报错，可以看到如果只是显式定义了copy ctor,那么ctor也就不会生成了
	return 0;
}

