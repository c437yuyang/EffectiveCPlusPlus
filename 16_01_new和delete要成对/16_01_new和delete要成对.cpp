// 16_01_new和delete要成对.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

class Widget
{
public:
	~Widget()
	{
		std::cout << "~Widget()" << std::endl;
	}
};

int main()
{
	Widget *pW = new Widget[10];

	//delete[]pW; //调用10次析构函数
	delete pW; //只调用了1次析构函数

	system("pause");
    return 0;
}

