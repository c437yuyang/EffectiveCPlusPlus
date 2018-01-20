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

class CompanyZ { //Z���ṩ���ܷ���
public:
	void sendClearText(const std::string &msg) {}
};


//ͨ��һ���������ڱ����ھ���������һ�����ҵ�������ʵ�ֵ���
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

//������Ҫ��ÿ�����ŵ�ʱ����һЩ��¼(log),ͨ��derivedclass��ʵ��
template<typename Company>
class LoggingMsgSender :public MsgSender<Company>
{
public:
	void sendClearMsg(const std::string &info)
	{
		//��log����
		sendClear(info); //���ø��ຯ��ʵ��send,����ȴ����ʾ�Ҳ�������,��Ϊ�����̳е���MsgSender<Company>
		//���Company�Ǹ�ģ��������޷�ȷ��class MsgSender<Company>��������ʲô������֪�����Ƿ���SendClear������
		//����VS����Ҳ�ǿ���ͨ������ģ�ֻҪ���õ�ʱ��template�Ĳ�����ָ���ĺ������ɡ�

		//log�����
	}
};


int main()
{

	MsgSender<CompanyA> msgSenderA;
	MsgSender<CompanyZ> msgSenderZ; //vs������һ��Ҳ�ǿ���ֱ�ӹ������

	//msgSenderZ.sendEncryp("AA"); //������������ʱ��ᱨ����ʾ����CompanyZ�ĳ�Ա
	LoggingMsgSender<CompanyA> logSender;
	LoggingMsgSender<CompanyZ> logSender1;
	logSender.sendClearMsg("aaa");
	logSender1.sendClearMsg("aaa");
	logSender1.sendEncryp("aaa"); //����ͻᱨ��
	return 0;
}

