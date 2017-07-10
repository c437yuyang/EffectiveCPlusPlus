// 03_01_const成员函数更改对象.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class  Widget {

	
	int m = 1;
	mutable int m1 = 2;
public:
	void printInfo() const 
	{ 
		cout << "a" << endl; 
		/*m += 1;*/ 
		i += 1; //const成员函数里可以修改静态变量，因为不是属于这个对象的数据
		m1 += 1;//mutable的也可以修改
	}
	static int i;
};

int main()
{
	return 0;
}

