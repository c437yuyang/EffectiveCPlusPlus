// 18_01_���������ͱ���ͻ��˴���.cpp : �������̨Ӧ�ó������ڵ㡣
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
//	//�����򵥵Ĺ��캯�����ͻ�����ֱ�Ӵ��ݸ�Day����30��Month>12
//	Date(int d, int m, int y) :Day(d), Month(m), Year(y) {}
//};


struct Day
{
	explicit Day(int d) :val(d) {} 
	// ��������Ϊexplicit�����õ�ʱ�򣬾ͱ���Date(Day(xxx),xxxx),
	// �û���֪����Day�����ˣ��ͻᴫһ��С��30���������еĻ��������Լ���һ���ж�,������Year��Month����
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

