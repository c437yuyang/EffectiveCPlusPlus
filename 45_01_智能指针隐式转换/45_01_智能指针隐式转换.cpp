// 45_01_����ָ����ʽת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include "auto_ptr.h"
using namespace std;

class Parent{};
class Son:public Parent{};

int main()
{
	//unique_ptr<double> pd(new double(1.0));
	//unique_ptr<int> pi(new int(5));

	////unique_ptr<double> pd1(new int(1)); //����������û��ʵ��
	//unique_ptr<double> pd1((double *)pi.get()); //ֻ���Լ�������ʵ�֣���������Ҳ�Ǵ��
	//unique_ptr<char> pc1(new char('1'));
	//unique_ptr<int> pi2 = unique_ptr<char>(new char); //���Կ���������ʵ�ǲ�֧�ֵģ�����stl����û��ʵ��������ܡ�

	//unique_ptr<int> pi1(pi.get()); //���Կ���������Ҳ������ָ��ͬһ�����ݣ�����������(��������),��ֱ����copying�����ǻ��ԭ��������ָ����Ϊnull��
	////�ͻ�������unique_ptrָ��ͬһ��������(������,����)
	//
	//cout << (*pd) << endl;
	//cout << (*pi) << endl;
	//cout << (*pd1) << endl;
	//cout << (*pi1) << endl;

	//�Լ������auto_ptr����
	using YXP_Utility::auto_ptr;
	auto_ptr<Son> ps(new Son);
	//auto_ptr<Parent> pp(ps); //֧����ʽת����
	auto_ptr<Parent> pp1 = auto_ptr<Son>(new Son()); //֧����ʽת����

	auto_ptr<Son> ps1 = auto_ptr<Parent>(new Parent); //�������ͻᱨ����ʾparent* ����ת����Son*


	system("pause");
    return 0;
}

