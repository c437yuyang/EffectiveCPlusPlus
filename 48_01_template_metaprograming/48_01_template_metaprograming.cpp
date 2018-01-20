// 48_01_template_metaprograming.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//std::cout << Fatorial<20>::value << std::endl; //20ֱ�Ӿ�û��������
	system("pause");
	return 0; 
}

