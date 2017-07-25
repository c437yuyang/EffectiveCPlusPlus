// 42_嵌套从属类型.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

template <typename C>
void print2nd(const C& container)
{
	//C::const_iterator* x = &(container.begin()); //VS里面可以直接运行，书上写的是可能和这个类别里面的静态成员变量之类的冲突，或者和operator*=冲突
	//C::const_iterator iter = container.begin(); //这里其实也是一个编译期多态,VS里可以直接正常运行
	typename C::const_iterator iter = container.begin(); //书上说的要加上typename才表示是类型
	cout << *(iter + 1) << endl;
}


int main()
{

	vector<int> v = { 1,23,4 };
	print2nd(v);

	return 0;
}

