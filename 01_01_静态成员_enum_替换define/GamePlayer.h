#pragma once
class GamePlayer
{
public:
	GamePlayer();
	~GamePlayer();

private:
	static const int NumTruns = 5; //支持预先定义(赋值)，后面也可以不用重新定义了
	//static int NumTurns1 = 1; //报错，带内类初始值的静态成员必须是常量
	static int NumTurns1; //只能之后再次定义的时候再去赋值

	int NumTurns2 = 3; //普通成员也可以直接有初始值 C++11开始
	int scores[NumTruns];

};

