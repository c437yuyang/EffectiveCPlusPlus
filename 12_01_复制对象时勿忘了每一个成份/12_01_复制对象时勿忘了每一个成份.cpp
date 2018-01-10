// 12_01_复制对象时勿忘了每一个成份.cpp : 定义控制台应用程序的入口点。
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
	void copy(const Customer&other) //实现一个公共函数负责copy
	{
		_name = other._name;
		_last_transaction = other._last_transaction;
	}

private:
	std::string _name;
	std::string _last_transaction; //增加一个变量则都需要改变
};

class PriorityCustomer :public Customer
{
public:
	PriorityCustomer(const PriorityCustomer&other) :Customer(other) //先调用父类copying函数一定要！
	{
		copy(other);
	}

	PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer&rhs)
	{
		Customer::operator=(rhs);//先调用父类
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

