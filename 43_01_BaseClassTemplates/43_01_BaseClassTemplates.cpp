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

class CompanyZ { //Z不提供加密发送
public:
	void sendClearText(const std::string &msg) {}
};


//通过一个工具类在编译期决定调用哪一个国家的送信来实现调用
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

//现在需要在每次送信的时候做一些记录(log),通过derivedclass来实现
template<typename Company>
class LoggingMsgSender :public MsgSender<Company>
{
public:
	void sendClearMsg(const std::string &info)
	{
		//做log操作
		sendClear(info); //调用父类函数实现send,但是却会提示找不到函数,因为这个类继承的是MsgSender<Company>
		//这个Company是个模板参数，无法确定class MsgSender<Company>看起来像什么，不能知道它是否有SendClear函数。
		//但是VS里面也是可以通过编译的，只要调用的时候template的参数有指定的函数即可。

		//log后操作
	}
};


int main()
{

	MsgSender<CompanyA> msgSenderA;
	MsgSender<CompanyZ> msgSenderZ; //vs里面这一句也是可以直接过编译的

	//msgSenderZ.sendEncryp("AA"); //但是这里编译的时候会报错，提示不是CompanyZ的成员
	LoggingMsgSender<CompanyA> logSender;
	LoggingMsgSender<CompanyZ> logSender1;
	logSender.sendClearMsg("aaa");
	logSender1.sendClearMsg("aaa");
	logSender1.sendEncryp("aaa"); //这里就会报错
	return 0;
}

