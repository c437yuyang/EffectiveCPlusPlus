// 00_explict���캯��.cpp : �������̨Ӧ�ó������ڵ㡣


#include "stdafx.h"
#include <iostream>
using namespace std;


class A{
public:
	A();
};

class B{
public:
	explicit B(int x = 0, bool b = true);
};

class C{
public:
	C(int x);
};

class D{
public:
	D(int, bool);
};

void printBInfo(B bObj){
	
}

void printCInfo(C cObj) {}
void printDInfo(D cObj) {}

int main()
{

	B bObj;
	printBInfo(bObj);
	B bObj1(28);
	printBInfo(bObj1); //��ȷ

	//printBInfo(28); //�������ܴ�int��Bת��
	printBInfo(B(28)); //��ȷ

	printCInfo(28); //��ȷ������ʵ�ִ�int��C����ʽת��

	//������һ���ܺõ����������캯����������ʽ����ת�����ͽ�������Ϊexplict��

	//printDInfo(1); //���Կ���  ��ʽת��Ҳֻ����һ������ִ����ʽת��

	system("pause");
    return 0;
}
