// 00_01_�������캯���Ϳ�����ֵ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget{
public:
	Widget(); //����Ϊpublic������ʵ�֣�����ᱨ������Ϊprivate����û��ʵ�֣�����ɾ���������
	Widget(const Widget& rhs); //��������
	Widget& operator=(const Widget& rhs); //������ֵ
};

bool hasAcceptableQuality(Widget w);

int main()
{

	//��׼:
	//1.���¶���������������õĵȺţ�Ҳ�ǿ������캯����������ֵ�����
	//2.û���¶�������������õĿ�����ֵ


	Widget w1;
	Widget w2(w1); //copy constructor����
	w2 = w1; //copy assignment
	Widget w3 = w1;//copy constructor

	Widget aWidget;
	if(hasAcceptableQuality(aWidget)){} ////copy constructor,��ֵ��ʱ��������¶���
	

	system("pause");
	return 0;
}