// 25_01_STL的swap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

namespace SCU_YXP {
	class TestClass
	{
	public:
		TestClass();
		~TestClass();
		void swap(TestClass &other) {
			using std::swap; //个人认为这里就应该直接在下面确定调用std::swap
			swap(pIvec, other.pIvec);
		}
	private:

		vector<int> *pIvec;

	};

	TestClass::TestClass()
	{
		pIvec = new vector<int>(10, 0);
	}

	TestClass::~TestClass()
	{
	}

	void swap(TestClass &lhs, TestClass &rhs) {
		lhs.swap(rhs);
	}

}



namespace std {
	template<> //为std::swap针对TestClass给出专门版本
	void swap<SCU_YXP::TestClass>(SCU_YXP::TestClass &lhs, SCU_YXP::TestClass &rhs) {
		lhs.swap(rhs);
	}
}


int main()
{
	vector<int> iVec1 = { 1,2,3,4 };
	vector<int> iVec2 = { 5,6,7 };
	iVec1.swap(iVec2); //可以看源码就知道内部也是调用的std::swap实现的


	SCU_YXP::TestClass tc1, tc2;
	using std::swap; //这里确保调用最优版本的swap，优先寻找同一命名空间内的swap，没有声明的话，调用std内的
	swap(tc1, tc2);

	system("pause");
	return 0;
}

