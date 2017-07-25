// 43_01_BaseClassTemplates.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class CompanyA {
public:
	void sendClearText(const std::string &msg) {}
	void sendEncrypText(const std::string &msg) {}
};

class CompanyB {
public:
	void sendClearText(const std::string &msg) {}
	void sendEncrypText(const std::string &msg) {}
};

class CompanyZ {
public:
	void sendClearText(const std::string &msg) {}
};

class MsgInfo {};


template <typename Company>
class MsgSender 
{
public:
	void sendClear(const std::string &msg) 
	{
		Company c;
		c.sendClearText(msg);
	}
	void sendEncryp(const std::string &msg) 
	{
		Company c;
		c.sendEncrypText(msg);
	}

};

int main()
{

	MsgSender<CompanyA> msgSenderA;
	MsgSender<CompanyZ> msgSenderZ; //vs里面这一句也是可以直接过编译的

	msgSenderZ.sendEncryp("AA"); //但是这里会报错，提示不是CompanyZ的成员。。，VS太智能了

	return 0;
}

