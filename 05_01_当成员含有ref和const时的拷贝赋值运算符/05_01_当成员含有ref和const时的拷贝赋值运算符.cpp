// 05_01_����Ա����ref��constʱ�Ŀ�����ֵ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
class NamedObj{
public:
	NamedObj(std::string &name, const T& value) :nameValue(name),value(objValue){};
	//������operator=
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
	//ֱ�ӱ��뱨����ʾoperator=�Ѿ���ɾ����˵����Ա�ڲ���ref��const��ʱ��
	// ������ֶ�����������ֵ�������������Զ����ɿ�����ֵ


	system("pause");
	return 0;
}