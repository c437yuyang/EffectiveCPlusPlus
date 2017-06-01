#pragma once
class GamePlayer
{
public:
	GamePlayer();
	~GamePlayer();

private:
	static const int NumTruns = 5;
	int scores[NumTruns];

};

