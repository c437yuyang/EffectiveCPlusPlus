// 07_virtual��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class TimeKeeper{
public:

	virtual ~TimeKeeper() { cout << "~TimeKeeper" << endl; }
};

class AtomicClock:public TimeKeeper{
public:
	~AtomicClock(){ cout << "~AtomicClock" << endl; }
};

class WaterClock:public TimeKeeper {};


int main()
{
	TimeKeeper *ac = new AtomicClock(); //��̬
	delete ac; 
	// delete�����ָ�뱾���жϵ����ĸ����������������������������������virtual�ģ�
	// �ͻ�ֱ��ֻ���û����������ɾ������ȫ�����ಿ��ûɾ��������ڴ�й¶
	// �������Ϊvirtual�����Ļ����Ż���������������������Ȼ����Ļ��ǻ����


    return 0;
}

