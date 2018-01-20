// 45_01_智能指针隐式转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include "auto_ptr.h"
using namespace std;

class Parent{};
class Son:public Parent{};

int main()
{
	//unique_ptr<double> pd(new double(1.0));
	//unique_ptr<int> pi(new int(5));

	////unique_ptr<double> pd1(new int(1)); //报错，看来并没有实现
	//unique_ptr<double> pd1((double *)pi.get()); //只能自己来这样实现，但是这样也是错的
	//unique_ptr<char> pc1(new char('1'));
	//unique_ptr<int> pi2 = unique_ptr<char>(new char); //可以看到这里其实是不支持的，所以stl里面没有实现这个功能。

	//unique_ptr<int> pi1(pi.get()); //可以看到，这样也是两个指针同一份数据，最后程序会出错(析构两次),而直接用copying函数是会把原来的智能指针置为null的
	////就会有两个unique_ptr指向同一份数据了(还不对,这里)
	//
	//cout << (*pd) << endl;
	//cout << (*pi) << endl;
	//cout << (*pd1) << endl;
	//cout << (*pi1) << endl;

	//自己定义的auto_ptr类型
	using YXP_Utility::auto_ptr;
	auto_ptr<Son> ps(new Son);
	//auto_ptr<Parent> pp(ps); //支持隐式转换了
	auto_ptr<Parent> pp1 = auto_ptr<Son>(new Son()); //支持隐式转换了

	auto_ptr<Son> ps1 = auto_ptr<Parent>(new Parent); //这里编译就会报错，提示parent* 不能转换成Son*


	system("pause");
    return 0;
}

