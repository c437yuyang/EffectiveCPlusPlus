// 39_02_EBO优化.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//现实中不是这样的空白类型，是内部含有typedefs,enums,static member,non virtual函数等这样的类型
class Empty
{ //空白类型大小是1
};

class HoldsInt
{ //本身是5，但是由于内存对齐变成了8
	int num;
	Empty empty;
};

class HoldsInt1
{
	Empty empty;
	int num;
};

class HoldsIntUsePrivateInherit :private Empty
{ //private继承可以解决这个问题
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

