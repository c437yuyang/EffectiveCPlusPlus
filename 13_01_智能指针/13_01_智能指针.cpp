// 13_01_智能指针.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <memory>
using namespace std;

int * allocIntMemory(int nSize)
{
	return new int[nSize];
}


class Widget{
	int m;
};

int main()
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif
	//int *pArr = new int[100];

	//Widget *pWidgets = new Widget; //可以看到下面的内存泄露的大小就是结构的大小

	//auto_ptr<Widget> pWidget_auto = 
	//shared_ptr<Widget> pWidget = make_shared(new Widget());
	auto_ptr<int> pArr1(allocIntMemory(100));

	//cout << pArr1[1] << endl;


	//delete pArr;

	system("pause");
	return 0;
}