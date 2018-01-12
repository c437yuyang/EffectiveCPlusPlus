// 25_02_class_templates_swap.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>

namespace SCU_YXP
{
	template <class T>
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
		std::vector<T> *pIvec;
	};

	template<class T>
	Widget<T>::Widget()
	{
		//pIvec = new vector<T>(10, 0);
	}

	template<class T>
	Widget<T>::~Widget()
	{
	}

	//template<class T>
	//void swap(Widget<T> &lhs, Widget<T> &rhs)
	//{
	//	lhs.swap(rhs);
	//}
}

//�����������ֻ����class templates ��������������function templates ������ (��������ԭ�����ǲ���д����?����֮������������Ҳ��ģ��Ļ����ͱ�ȥ��������)
//VC++ ����Ҳ�ǻᱨ���
//namespace std
//{
//	using SCU_YXP::Widget;
//	template <typename T>
//	void swap<Widget<T>>(Widget<T>&lhs, Widget<T>&rhs)
//	{
//		lhs.swap(rhs);
//	}
//}

//��ȷ�������ǣ�����ͬ�������ռ����һ��non-member��������������member swap
namespace SCU_YXP
{
	template<class T>
	void swap(Widget<T>&a, Widget<T>&b) //�����κεط�����swap���������ʱ��,��ԥKoening���ҷ��򶼻�������ר���汾���������������ȥָ����ʹ��std::swap���Ǿ�ʹ��stl����
	{
		a.swap(b);
		std::cout << "SCU_YXP::swap" << std::endl;
	}
}

template<class T>
void func(Widget<T> &a,Widget<T> &b)
{
	swap(a, b); //���ｫ�ܹ�����SCU_YXP::swap������koening
}

int main()
{
	using namespace SCU_YXP;
	Widget<int> w1, w2;
	swap(w1, w2); //ֱ�ӵ��õĻ��ͻ�ȥ����swap
	std::swap(w1, w2);

	system("pause");
    return 0;
}

