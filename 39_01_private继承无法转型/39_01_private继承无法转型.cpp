// 39_01_private继承无法转型.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;


class Person {
	
};


class Student :private Person {

};


void eat(Person &p) {}
void study(Student &s) {}


int main()
{
	Person p;
	Student s;

	eat(p);
	//eat(s); //转型出错，private继承不是is-a的关系，不能向上转型

	//Person *p2 = new Student();//转型出错，private继承不是is-a的关系，不能向上转型


	system("pause");
    return 0;
}
