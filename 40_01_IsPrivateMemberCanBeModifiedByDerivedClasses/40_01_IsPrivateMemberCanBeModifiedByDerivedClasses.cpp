// 40_01_IsPrivateMemberCanBeModifiedByDerivedClasses.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


class Widget 
{
	

private:

	class WidgetTimer :public Timer

	int id;


};

class SpectialWidget :public Widget 
{
	
};

int main()
{



    return 0;
}

