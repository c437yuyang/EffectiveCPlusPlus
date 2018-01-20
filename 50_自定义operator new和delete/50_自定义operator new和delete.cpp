// 50_�Զ���operator new��delete.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

//�Զ���operator newʵ�� ���ô���ļ�⣬���overturns��underturns
void *operator new(std::size_t size) throw(std::bad_alloc)
{
	using namespace std;
	size_t real_size = size + 2 * sizeof(int); //�������ڱ��ֽ�

	void *pMem = malloc(real_size);
	if (!pMem)  throw std::bad_alloc();

	*(static_cast<int *> (pMem)) = signature;
	*(reinterpret_cast<int *>(static_cast<Byte *> (pMem) + real_size - sizeof(int))) = signature;

	return static_cast<Byte *>(pMem) + sizeof(int); //����������ʼλ��

}

int main()
{
	return 0;
}

