// 39_02_EBO�Ż�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//��ʵ�в��������Ŀհ����ͣ����ڲ�����typedefs,enums,static member,non virtual����������������
class Empty
{ //�հ����ʹ�С��1
};

class HoldsInt
{ //������5�����������ڴ��������8
	int num;
	Empty empty;
};

class HoldsInt1
{
	Empty empty;
	int num;
};

class HoldsIntUsePrivateInherit :private Empty
{ //private�̳п��Խ���������
	int num;
};




int main()
{

	cout << sizeof(Empty) << endl;//1
	cout << sizeof(HoldsInt) << endl; //8
	cout << sizeof(HoldsInt1) << endl; //8

	cout << sizeof(HoldsIntUsePrivateInherit) << endl; //4


	system("pause");
	return 0;
}

