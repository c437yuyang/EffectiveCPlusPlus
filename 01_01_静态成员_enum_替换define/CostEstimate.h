#pragma once
class CostEstimate
{
public:
	CostEstimate();
	~CostEstimate();

private:
	enum //如果编译器不支持in-class常量初始值设定，可采用enum
	{
		NumTurns = 5
	};

	int socres[NumTurns];


};

