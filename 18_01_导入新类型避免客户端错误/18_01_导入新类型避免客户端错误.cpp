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



//ʹ���⸲����
struct Day //���ʹ���ڲ����͵Ļ�Ҳ���ԣ����ǿͻ���ʹ�õ�ʱ��ͱ���Date::Day
{
	explicit Day(int d) :val(d) {}
	// ��������Ϊexplicit�����õ�ʱ�򣬾ͱ���Date(Day(xxx),xxxx),
	// �û���֪����Day�����ˣ��ͻᴫһ��С��30���������еĻ��������Լ���һ���ж�,������Year��Month����
	int val;
};

//����ֵ������:
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

