// 44_01_非类型模板参数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T,int n> //这里的n就是非类型模板参数，这样一来的话，针对每个大小不同的n都会差生一份二进制代码
class Widget {

public:
	void printfInfo(T a) 
	{
		cout << a << endl;
		cout << n << endl;
	}

};


int main()
{
	Widget<int,5> w;
	w.printfInfo(1);

	system("pause");
    return 0;
}

