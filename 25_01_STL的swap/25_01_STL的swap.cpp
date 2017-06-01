// 25_01_STL��swap.cpp : �������̨Ӧ�ó������ڵ㡣
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
			using std::swap; //������Ϊ�����Ӧ��ֱ��������ȷ������std::swap
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
	template<> //Ϊstd::swap���TestClass����ר�Ű汾
	void swap<SCU_YXP::TestClass>(SCU_YXP::TestClass &lhs, SCU_YXP::TestClass &rhs) {
		lhs.swap(rhs);
	}
}


int main()
{
	vector<int> iVec1 = { 1,2,3,4 };
	vector<int> iVec2 = { 5,6,7 };
	iVec1.swap(iVec2); //���Կ�Դ���֪���ڲ�Ҳ�ǵ��õ�std::swapʵ�ֵ�


	SCU_YXP::TestClass tc1, tc2;
	using std::swap; //����ȷ���������Ű汾��swap������Ѱ��ͬһ�����ռ��ڵ�swap��û�������Ļ�������std�ڵ�
	swap(tc1, tc2);

	system("pause");
	return 0;
}

