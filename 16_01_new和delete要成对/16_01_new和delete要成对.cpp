// 16_01_new��deleteҪ�ɶ�.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//delete[]pW; //����10����������
	delete pW; //ֻ������1����������

	system("pause");
    return 0;
}

