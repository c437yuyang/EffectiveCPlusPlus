// 45_01_����ָ����ʽת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	unique_ptr<double> pd(new double(1.0));
	unique_ptr<int> pi(new int(5));

	//unique_ptr<double> pd1(new int(1)); //����������û��ʵ��


	cout << (*pd) << endl;
	cout << (*pi) << endl;

	system("pause");
    return 0;
}

