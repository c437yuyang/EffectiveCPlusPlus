// 25_01_STL的swap.cpp : 定义控制台应用程序的入口点。
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
			//using std::swap; //个人认为这里就应该直接在下面确定调用std::swap,是对的
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

namespace std { //这种做法就是stl里面所有容器的做法，提供自己特例版本的std::swap，然后成员内部提供swap接口
	using SCU_YXP::Widget;
	template<> //为std::swap针对Widget给出专门版本（特化）
	void swap<Widget>(Widget &lhs, Widget &rhs)
	{
		lhs.swap(rhs); //再去调用接口实现交换(否则只能声明为friend来访问成员)
	}
}


//看源码得知std::swap 现在还是利用了std::move来实现的(C++11的移动)

int main()
{
	vector<int> iVec1 = { 1,2,3,4 };
	vector<int> iVec2 = { 5,6,7 };
	iVec1.swap(iVec2); //可以看源码就知道内部也是调用的std::swap实现的

	int i = 0;
	int j = 1;
	std::swap(i, j); //可以直接实现交换，内部传的是引用

	SCU_YXP::Widget tc1, tc2;
	using std::swap; //这里确保调用最优版本的swap，优先寻找同一命名空间内的swap，没有声明的话，调用std内的
	swap(tc1, tc2);

	system("pause");
	return 0;
}

