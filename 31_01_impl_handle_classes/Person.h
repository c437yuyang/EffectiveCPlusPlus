#pragma once

#pragma region 原始版本
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

//这里的Person通不过编译如果编译器没有取得string,date,address的实现代码
//这样形成了依赖关系
#pragma endregion


#pragma region 修改后版本
#include <string>
#include <memory>
class PersonImpl; //使用impl类以及前置声明
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
	std::shared_ptr<PersonImpl> _pImpl; //具体的实现隐藏起来放在指针背后用来解除依赖性
};


#pragma endregion


#pragma region MyRegion

#pragma endregion
