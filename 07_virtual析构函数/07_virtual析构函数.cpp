// 07_virtual��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class TimeKeeper {
public:

	virtual ~TimeKeeper() { cout << "~TimeKeeper" << endl; }
};

class AtomicClock :public TimeKeeper {
public:
	~AtomicClock() { cout << "~AtomicClock" << endl; }
};

class WaterClock :public TimeKeeper {};

class Widget {
public:
	virtual ~Widget() = 0 {}; //�������������Ļ������Ǳ�����ж��壬��Ϊ�϶��ᱻ�̳У�
	//�����ݼ̳У���һ������ø���ģ�����һ���ᱻ���ã����Ա����ж��塣
	//����ͨ��Ա��������Ҫ�ж��壬��Ϊ������Ҫ��д���Ͳ�����ø������
	virtual void printInfo() = 0;
};

class SpecialWidget :public Widget 
{
public:
	~SpecialWidget() {};
	void printInfo() {};
};

int main()
{
	TimeKeeper *ac = new AtomicClock(); //��̬
	delete ac;
	// delete�����ָ�뱾���жϵ����ĸ����������������������������������virtual�ģ�
	// �ͻ�ֱ��ֻ���û����������ɾ������ȫ�����ಿ��ûɾ��������ڴ�й¶
	// �������Ϊvirtual�����Ļ����Ż���������������������Ȼ����Ļ��ǻ����
	SpecialWidget sp;
	sp.printInfo();
	return 0;
}

