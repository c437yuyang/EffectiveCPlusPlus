// 00_01_拷贝构造函数和拷贝赋值运算符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget{
public:
	Widget(); //声明为public必须有实现，否则会报错，声明为private可以没有实现，代表删除这个函数
	Widget(const Widget& rhs); //拷贝构造
	Widget& operator=(const Widget& rhs); //拷贝赋值
};

bool hasAcceptableQuality(Widget w);

int main()
{

	//标准:
	//1.有新对象产生，就算是用的等号，也是拷贝构造函数，包括传值等情况
	//2.没有新对象产生，就是用的拷贝赋值


	Widget w1;
	Widget w2(w1); //copy constructor调用
	w2 = w1; //copy assignment
	Widget w3 = w1;//copy constructor

	Widget aWidget;
	if(hasAcceptableQuality(aWidget)){} ////copy constructor,传值的时候产生了新对象
	

	system("pause");
	return 0;
}