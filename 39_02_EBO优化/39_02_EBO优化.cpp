// 39_02_EBO优化.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Empty {
};

class HoldsInt {
	int num;
	Empty empty;
};

class HoldsInt1 {
	Empty empty;
	int num;
};

class HoldsIntUsePrivateInherit :private Empty{
	int num;
};




int main()
{

	cout << sizeof(Empty) << endl;//1
	cout << sizeof(HoldsInt) << endl; //8
	cout << sizeof(HoldsInt1) << endl; //8

	cout << sizeof(HoldsIntUsePrivateInherit) << endl; //4


	system("pause");
    return 0;
}

