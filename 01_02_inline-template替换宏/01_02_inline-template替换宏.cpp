// 01_02_inline-template�滻��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void f(int a);

#define CALL_WITH_MAX(a,b) f((a)>(b)?(a):(b))

//�滻Ϊ
template<class T>
inline void callWithMax(const T& a, const T&b) {
	f(a > b ? a : b);
}


int main()
{
	return 0;
}

