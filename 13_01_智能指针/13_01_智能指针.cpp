// 13_01_����ָ��.cpp : �������̨Ӧ�ó������ڵ㡣

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

	//Widget *pWidgets = new Widget; //���Կ���������ڴ�й¶�Ĵ�С���ǽṹ�Ĵ�С

	//auto_ptr<Widget> pWidget_auto = 
	//shared_ptr<Widget> pWidget = make_shared(new Widget());
	auto_ptr<int> pArr1(allocIntMemory(100));

	//cout << pArr1[1] << endl;


	//delete pArr;

	system("pause");
	return 0;
}