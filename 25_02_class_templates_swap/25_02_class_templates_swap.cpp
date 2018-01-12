// 25_02_class_templates_swap.cpp : 定义控制台应用程序的入口点。
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
			//using std::swap; //个人认为这里就应该直接在下面确定调用std::swap,是对的
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

//错误的做法，只允许class templates 特例化，不允许function templates 特例化 (这是书上原话，是不是写反了?，总之这里就是如果类也是模板的话，就别去特例化了)
//VC++ 编译也是会报错的
//namespace std
//{
//	using SCU_YXP::Widget;
//	template <typename T>
//	void swap<Widget<T>>(Widget<T>&lhs, Widget<T>&rhs)
//	{
//		lhs.swap(rhs);
//	}
//}

//正确的做法是，在相同的命名空间添加一个non-member函数重载来调用member swap
namespace SCU_YXP
{
	template<class T>
	void swap(Widget<T>&a, Widget<T>&b) //现在任何地方打算swap两个对象的时候,犹豫Koening查找法则都会调用这个专属版本，但是这里如果你去指明了使用std::swap还是就使用stl的了
	{
		a.swap(b);
		std::cout << "SCU_YXP::swap" << std::endl;
	}
}

template<class T>
void func(Widget<T> &a,Widget<T> &b)
{
	swap(a, b); //这里将能够调用SCU_YXP::swap，由于koening
}

int main()
{
	using namespace SCU_YXP;
	Widget<int> w1, w2;
	swap(w1, w2); //直接调用的话就会去调用swap
	std::swap(w1, w2);

	system("pause");
    return 0;
}

