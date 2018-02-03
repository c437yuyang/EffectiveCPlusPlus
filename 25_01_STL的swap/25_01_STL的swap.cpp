// 25_01_STL��swap.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

namespace SCU_YXP {
	class Widget
	{
	public:
		Widget();
		~Widget();
		void swap(Widget &rhs) 
		{
			//using std::swap; //������Ϊ�����Ӧ��ֱ��������ȷ������std::swap,�ǶԵ�
			std::swap(pIvec, rhs.pIvec);
		}
	private:
		vector<int> *pIvec;
	};

	Widget::Widget()
	{
		pIvec = new vector<int>(10, 0);
	}

	Widget::~Widget()
	{
	}
}

namespace std { //������������stl���������������������ṩ�Լ������汾��std::swap��Ȼ���Ա�ڲ��ṩswap�ӿ�
	using SCU_YXP::Widget;
	template<> //Ϊstd::swap���Widget����ר�Ű汾���ػ���
	void swap<Widget>(Widget &lhs, Widget &rhs)
	{
		lhs.swap(rhs); //��ȥ���ýӿ�ʵ�ֽ���(����ֻ������Ϊfriend�����ʳ�Ա)
	}
}


//��Դ���֪std::swap ���ڻ���������std::move��ʵ�ֵ�(C++11���ƶ�)

int main()
{
	vector<int> iVec1 = { 1,2,3,4 };
	vector<int> iVec2 = { 5,6,7 };
	iVec1.swap(iVec2); //���Կ�Դ���֪���ڲ�Ҳ�ǵ��õ�std::swapʵ�ֵ�

	int i = 0;
	int j = 1;
	std::swap(i, j); //����ֱ��ʵ�ֽ������ڲ�����������

	SCU_YXP::Widget tc1, tc2;
	using std::swap; //����ȷ���������Ű汾��swap������Ѱ��ͬһ�����ռ��ڵ�swap��û�������Ļ�������std�ڵ�
	swap(tc1, tc2);

	system("pause");
	return 0;
}

