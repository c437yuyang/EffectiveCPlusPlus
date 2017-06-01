// 01_02_inline-template替换宏.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void f(int a);

#define CALL_WITH_MAX(a,b) f((a)>(b)?(a):(b))

//替换为
template<class T>
inline void callWithMax(const T& a, const T&b) {
	f(a > b ? a : b);
}


int main()
{
	return 0;
}

