// 06_01�ܾ�ʹ���Զ����ɵĺ���.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include <iostream>
using namespace std;

class TestNoCopy{
private:
	TestNoCopy(const TestNoCopy&); //����Ϊpublic������ʵ�֣�����ᱨ������Ϊprivate����û��ʵ�֣�����ɾ���������
	TestNoCopy& operator=(const TestNoCopy&);
};

class UnCopyable{
protected:
	UnCopyable();
	~UnCopyable();
private:
	UnCopyable(const UnCopyable&);
	UnCopyable& operator=(const UnCopyable&);
};

class Derived:private UnCopyable{}; //��������ֻҪ�̳��������Ϳ�����

int main()
{

	system("pause");
	return 0;
}