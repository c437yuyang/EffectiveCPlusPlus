#pragma once
class GamePlayer
{
public:
	GamePlayer();
	~GamePlayer();

private:
	static const int NumTruns = 5; //֧��Ԥ�ȶ���(��ֵ)������Ҳ���Բ������¶�����
	//static int NumTurns1 = 1; //�����������ʼֵ�ľ�̬��Ա�����ǳ���
	static int NumTurns1; //ֻ��֮���ٴζ����ʱ����ȥ��ֵ

	int NumTurns2 = 3; //��ͨ��ԱҲ����ֱ���г�ʼֵ C++11��ʼ
	int scores[NumTruns];

};

