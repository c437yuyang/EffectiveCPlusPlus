#pragma once
#include <string> 
#include "Address.h"
#include "Date.h" //将依赖性转移到impl这里来

struct PersonImpl
{
	std::string _name;
	Date _birthday;
	Address _addr;
};