// 06_01�ܾ�ʹ���Զ����ɵĺ���.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <iostream>
using namespace std;

class TestNoCopy
{
private:
	TestNoCopy(const TestNoCopy&); //����Ϊpublic������ʵ�֣�����ᱨ������Ϊprivate����û��ʵ�֣�����ɾ���������
	TestNoCopy& operator=(const TestNoCopy&);
};

class UnCopyable
{
protected:
	UnCopyable() {}
	~UnCopyable() {}
private:
	UnCopyable(const UnCopyable&);
	UnCopyable& operator=(const UnCopyable&);
};

class Derived :private UnCopyable
{

}; //��������ֻҪprivate�̳��������Ϳ����ˣ���Ϊ�������û��copying�����Ļ���������޷�������ĳ�Ա���֣����ǲ�����ȥ�ֶ�����public��copying�����������ǿ��Կ����ģ�

int main()
{
	Derived d1;
	Derived d2(d1);
	system("pause");
	return 0;
}