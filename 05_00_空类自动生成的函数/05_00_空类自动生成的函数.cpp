// 05_00_�����Զ����ɵĺ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//class TestClass{}; //����һ��������


//�ȼ���:
class TestClass
{
public:
	TestClass();
	~TestClass();
	TestClass(const TestClass&);
	TestClass& operator=(const TestClass&);
};

class Widget 
{
public:
	Widget(const Widget& rhs) {}

};

int main()
{
	Widget w; //�������Կ������ֻ����ʽ������copy ctor,��ôctorҲ�Ͳ���������
	return 0;
}

