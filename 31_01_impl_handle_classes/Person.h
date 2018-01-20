#pragma once

#pragma region ԭʼ�汾
#include "Address.h"
#include "Date.h"
#include <string>

class Person
{
public:
	Person(const std::string& name, const Date& birthray, const Address&addr);
	std::string name() const;
	std::string birthday() const;
	std::string address() const;
private:
	std::string _name;
	Date _birthday;
	Address _addr;
};

//�����Personͨ�����������������û��ȡ��string,date,address��ʵ�ִ���
//�����γ���������ϵ
#pragma endregion


#pragma region �޸ĺ�汾
#include <string>
#include <memory>
class PersonImpl; //ʹ��impl���Լ�ǰ������
class Date;
class Address;
class   Person
{
public:
	Person(const std::string& name, const Date& birthray, const Address&addr);
	std::string name() const;
	std::string birthday() const;
	std::string address() const;

private:
	std::shared_ptr<PersonImpl> _pImpl; //�����ʵ��������������ָ�뱳���������������
};


#pragma endregion


#pragma region MyRegion

#pragma endregion
