#pragma once
#include <string> 
#include "Address.h"
#include "Date.h" //��������ת�Ƶ�impl������

struct PersonImpl
{
	std::string _name;
	Date _birthday;
	Address _addr;
};