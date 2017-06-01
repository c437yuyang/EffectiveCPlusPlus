#include "stdafx.h"
#include "GamePlayer.h"
#include <iostream>
using namespace std;

const int GamePlayer::NumTruns; //测试发现不定义也可以

GamePlayer::GamePlayer()
{

	cout << "构造函数里面访问静态成员:" << NumTruns << endl;

}


GamePlayer::~GamePlayer()
{
}
