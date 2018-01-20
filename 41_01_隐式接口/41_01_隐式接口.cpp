// 41_01_隐式接口.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Widget 
{
public:
	Widget();
	virtual ~Widget();
	virtual std::size_t size() const;
	virtual void normalize();
	bool operator!=(const Widget& rhs) { return this->id != rhs.id; }

private:
	int id;
};

void doProcessing(Widget &w)  //正常的多态和接口，运行期多态
{
	Widget w1;
	if (w.size() > 10 && w != w1) 
	{
		
	}
}

template<class T> //隐式接口
void doProcessing1(T& w)
{
	Widget w1;
	if (w.size() > 10 && w != w1) 
	{
		T temp(w);
		w.normalize();
	}
}
int main()
{
	//doProcessing1(1); //报错，没有办法满足size和 !=w1
	Widget w;
	doProcessing1(w); //正常，编译期间的多态,只要最终满足(w.size() > 10 && w != w1)是个bool表达式就可以了
	//总之这个条款讲的就是:
	//看上去好像doProcessing1这个函数中要求类型必须支持:
	//(1)size(2)operator!=(3)copy ctor(4)normalize
	//但是对于	if (w.size() > 10 && w != w1) 这条语句来说，不需要这些东西，只需要最终是个bool表达式即可。
	//因为size()可以从继承获得，operator>10也可以只要类型T可以隐式转型成10的类型(这里是int)即可，后面的不等于也是一样的，只要能够隐式转型成不等式右边的类型即可。
	system("pause");
    return 0;
}

