// 50_自定义operator new和delete.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

//自定义operator new实现 运用错误的检测，检测overturns和underturns
void *operator new(std::size_t size) throw(std::bad_alloc)
{
	using namespace std;
	size_t real_size = size + 2 * sizeof(int); //多两个哨兵字节

	void *pMem = malloc(real_size);
	if (!pMem)  throw std::bad_alloc();

	*(static_cast<int *> (pMem)) = signature;
	*(reinterpret_cast<int *>(static_cast<Byte *> (pMem) + real_size - sizeof(int))) = signature;

	return static_cast<Byte *>(pMem) + sizeof(int); //返回数据起始位置

}

int main()
{
	return 0;
}

