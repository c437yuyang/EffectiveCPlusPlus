// 43_01_BaseClassTemplates.cpp : �������̨Ӧ�ó������ڵ㡣
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
	MsgSender<CompanyZ> msgSenderZ; //vs������һ��Ҳ�ǿ���ֱ�ӹ������

	msgSenderZ.sendEncryp("AA"); //��������ᱨ����ʾ����CompanyZ�ĳ�Ա������VS̫������

	return 0;
}

