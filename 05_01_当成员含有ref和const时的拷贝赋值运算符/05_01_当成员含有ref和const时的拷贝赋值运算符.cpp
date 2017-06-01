// 05_01_当成员含有ref和const时的拷贝赋值运算符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
class NamedObj{
public:
	NamedObj(std::string &name, const T& value) :nameValue(name),value(objValue){};
	//不声明operator=
private:
	std::string &nameValue;
	const T objValue;
};


int main()
{

	std::string newDog("newDog");
	std::string oldDog("oldDog");

	NamedObj<int> oldD(newDog, 1);
	NamedObj<int> newD(oldDog, 36);

	//oldD = newD; 
	//直接编译报错，提示operator=已经被删除，说明成员内部有ref和const的时候，
	// 如果不手动声明拷贝赋值，编译器不会自动生成拷贝赋值


	system("pause");
	return 0;
}