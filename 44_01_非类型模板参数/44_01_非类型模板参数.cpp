// 44_01_������ģ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T,int n> //�����n���Ƿ�����ģ�����������һ���Ļ������ÿ����С��ͬ��n�������һ�ݶ����ƴ���
class Widget {

public:
	void printfInfo(T a) 
	{
		cout << a << endl;
		cout << n << endl;
	}

};


int main()
{
	Widget<int,5> w;
	w.printfInfo(1);

	system("pause");
    return 0;
}

