// 40_01_virtual�̳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class WidgetA
{
private:
	int id;
};

class WidgetAB :virtual public WidgetA //virtual�̳п��Ա���̳ж����ĳ�Ա�ظ�
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

