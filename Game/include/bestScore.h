#pragma once
#include<string>
using namespace std;
class bestScore
{
public:
	bestScore();
	~bestScore();

private:
	int _score;
	string _map;
	string _difficulty;
};

bestScore::bestScore()
{
}

bestScore::~bestScore()
{
}