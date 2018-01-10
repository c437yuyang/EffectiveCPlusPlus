// 12_01_���ƶ���ʱ������ÿһ���ɷ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>

class Customer
{
public:
	Customer(const Customer&other) /*:_name(other._name)*/ { copy(other); }
	Customer& operator=(const Customer&other)
	{
		//_name = other._name;
		copy(other);
	}

private:
	void copy(const Customer&other) //ʵ��һ��������������copy
	{
		_name = other._name;
		_last_transaction = other._last_transaction;
	}

private:
	std::string _name;
	std::string _last_transaction; //����һ����������Ҫ�ı�
};

class PriorityCustomer :public Customer
{
public:
	PriorityCustomer(const PriorityCustomer&other) :Customer(other) //�ȵ��ø���copying����һ��Ҫ��
	{
		copy(other);
	}

	PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer&rhs)
	{
		Customer::operator=(rhs);//�ȵ��ø���
		copy(rhs);
		return *this;
	}
private:
	void copy(const PriorityCustomer&rhs)
	{
		_priority = rhs._priority;
	}
private:
	int _priority;
};

int main()
{
	return 0;
}

