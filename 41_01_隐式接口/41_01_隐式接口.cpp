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
		
	}
}



int main()
{

	

	//doProcessing1(1); //报错，没有办法满足size和 !=w1
	Widget w;
	doProcessing1(w); //正常，编译期间的多态,只要最终满足(w.size() > 10 && w != w1)是个bool表达式就可以了

	system("pause");
    return 0;
}

