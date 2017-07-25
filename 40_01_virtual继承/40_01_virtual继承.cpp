// 40_01_virtual继承.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class WidgetA
{
private:
	int id;
};

class WidgetAB :virtual public WidgetA //virtual继承可以避免继承而来的成员重复
{

};

class WidgetAC :virtual public WidgetA
{

};

class WidgetABCD : public WidgetAB,public WidgetAC
{

};


int main()
{
	return 0;
}

