// 07_virtual析构函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class TimeKeeper{
public:

	virtual ~TimeKeeper() { cout << "~TimeKeeper" << endl; }
};

class AtomicClock:public TimeKeeper{
public:
	~AtomicClock(){ cout << "~AtomicClock" << endl; }
};

class WaterClock:public TimeKeeper {};


int main()
{
	TimeKeeper *ac = new AtomicClock(); //多态
	delete ac; 
	// delete会根据指针本身判断调用哪个类的析构函数，所以如果基类的析构不是virtual的，
	// 就会直接只调用基类的析构，删除不完全，子类部分没删除，造成内存泄露
	// 如果声明为virtual析构的话，才会调用子类的析构函数，当然父类的还是会调用


    return 0;
}

