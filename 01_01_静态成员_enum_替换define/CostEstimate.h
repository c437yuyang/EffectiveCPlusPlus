#pragma once
class CostEstimate
{
public:
	CostEstimate();
	~CostEstimate();

private:
	enum //�����������֧��in-class������ʼֵ�趨���ɲ���enum
	{
		NumTurns = 5
	};

	int socres[NumTurns];


};

