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



//使用外覆类型
struct Day //如果使用内部类型的话也可以，但是客户在使用的时候就必须Date::Day
{
	explicit Day(int d) :val(d) {}
	// 这里声明为explicit，调用的时候，就必须Date(Day(xxx),xxxx),
	// 用户就知道是Day类型了，就会传一个小于30的数，不行的话还可以自己加一个判断,其他的Year和Month类似
	int val;
};

//限制值的做法:
class Month
{
public:
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	static Month Apr() { return Month(3); }
	static Month Mar() { return Month(4); }
	//...
private:
	explicit Month(int m) :_m(m) {}
private:
	int _m;
};

class Date
{
public:
private:
	Day day;
	int month;
	int year;
public:

	Date(Day d, int m, int y) :day(d), month(m), year(y) {}
};


int main()
{
	//Date(Date::Day(20), 20, 30);
	return 0;
}

