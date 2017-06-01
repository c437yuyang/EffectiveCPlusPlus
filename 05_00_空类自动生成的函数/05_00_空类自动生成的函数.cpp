// 05_00_空类自动生成的函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class TestClass{}; //声明一个空类型


//等价于:
//class TestClass{
//public:
//	TestClass();
//	~TestClass();
//	TestClass(const TestClass&);
//	TestClass& operator=(const TestClass&);
//};

int main()
{
    return 0;
}

