// 48_01_template_metaprograming.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

template <unsigned n>
struct Factorial
{
	enum { value = n * Factorial<n - 1>::value };
};

template<>
struct Factorial<0>
{
	enum { value = 1 };
};


int main()
{
	std::cout << Factorial<10>::value << std::endl;
	std::cout << Factorial<11>::value << std::endl;
	//std::cout << Fatorial<20>::value << std::endl; //20直接就没法编译了
	system("pause");
	return 0; 
}

