// 40_01_IsPrivateMemberCanBeModifiedByDerivedClasses.cpp : 定义控制台应用程序的入口点。
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

