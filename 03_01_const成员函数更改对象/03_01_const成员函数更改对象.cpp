// 03_01_const��Ա�������Ķ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class  Widget {

	
	int m = 1;
	mutable int m1 = 2;
public:
	void printInfo() const 
	{ 
		cout << "a" << endl; 
		/*m += 1;*/ 
		i += 1; //const��Ա����������޸ľ�̬��������Ϊ��������������������
		m1 += 1;//mutable��Ҳ�����޸�
	}
	static int i;
};

int main()
{
	return 0;
}

