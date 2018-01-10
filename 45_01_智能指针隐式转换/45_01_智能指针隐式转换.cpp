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
	unique_ptr<double> pd1((double *)pi.get()); //只能自己来这样实现，但是这样也是错的
	unique_ptr<int> pi1(pi.get()); //可以看到，这样也是两个指针同一份数据，最后程序会出错(析构两次),而直接用copying函数是会把原来的智能指针置为null的
	//就会有两个unique_ptr指向同一份数据了(还不对,这里)
	
	cout << (*pd) << endl;
	cout << (*pi) << endl;
	cout << (*pd1) << endl;
	cout << (*pi1) << endl;

	

	system("pause");
    return 0;
}

