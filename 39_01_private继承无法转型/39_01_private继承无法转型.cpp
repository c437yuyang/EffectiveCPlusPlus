// 39_01_private�̳��޷�ת��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//eat(s); //ת�ͳ���private�̳в���is-a�Ĺ�ϵ����������ת��

	//Person *p2 = new Student();//ת�ͳ���private�̳в���is-a�Ĺ�ϵ����������ת��


	system("pause");
    return 0;
}
