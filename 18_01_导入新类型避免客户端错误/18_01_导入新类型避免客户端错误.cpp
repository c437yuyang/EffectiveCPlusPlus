// 18_01_导入新类型避免客户端错误.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//class Date {
//private:
//	int Day;
//	int Month;
//	int Year;
//public:
//	//这样简单的构造函数，客户可以直接传递给Day大于30，Month>12
//	Date(int d, int m, int y) :Day(d), Month(m), Year(y) {}
//};


struct Day
{
	explicit Day(int d) :val(d) {} 
	// 这里声明为explicit，调用的时候，就必须Date(Day(xxx),xxxx),
	// 用户就知道是Day类型了，就会传一个小于30的数，不行的话还可以自己加一个判断,其他的Year和Month类似
	int val;
};


class Date {
private:
	Day day;
	int month;
	int year;
public:
	
	Date(Day d, int m, int y) :day(d), month(m), year(y) {}
};


int main()
{
    return 0;
}

