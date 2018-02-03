// 00_explict构造函数.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <iostream>
using namespace std;


class A{
public:
	A();
};

class B{
public:
	explicit B(int x = 0, bool b = true);
};

class C{
public:
	C(int x);
};

class D{
public:
	D(int, bool);
};

void printBInfo(B bObj){
	
}

void printCInfo(C cObj) {}
void printDInfo(D cObj) {}

int main()
{

	B bObj;
	printBInfo(bObj);
	B bObj1(28);
	printBInfo(bObj1); //正确

	//printBInfo(28); //出错，不能从int到B转换
	printBInfo(B(28)); //正确

	printCInfo(28); //正确，可以实现从int到C的隐式转换

	//除非有一个很好的理由允许构造函数被用于隐式类型转换，就建议声明为explict的

	//printDInfo(1); //可以看到  隐式转换也只能是一个参数执行隐式转换

	system("pause");
    return 0;
}
