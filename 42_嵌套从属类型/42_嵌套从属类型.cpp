// 42_Ƕ�״�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

template <typename C>
void print2nd(const C& container)
{
	//C::const_iterator* x = &(container.begin()); //VS�������ֱ�����У�����д���ǿ��ܺ�����������ľ�̬��Ա����֮��ĳ�ͻ�����ߺ�operator*=��ͻ
	//C::const_iterator iter = container.begin(); //������ʵҲ��һ�������ڶ�̬,VS�����ֱ����������
	typename C::const_iterator iter = container.begin(); //����˵��Ҫ����typename�ű�ʾ������
	cout << *(iter + 1) << endl;
}


int main()
{

	vector<int> v = { 1,23,4 };
	print2nd(v);

	return 0;
}

