// 45_01_智能指针隐式转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	unique_ptr<double> pd(new double(1.0));
	unique_ptr<int> pi(new int(5));

	//unique_ptr<double> pd1(new int(1)); //报错，看来并没有实现


	cout << (*pd) << endl;
	cout << (*pi) << endl;

	system("pause");
    return 0;
}

