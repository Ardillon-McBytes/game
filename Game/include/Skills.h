#pragma once
#include<string>
#include "actionRange.h"
using namespace std;
class skill
{
public:
	skill();
	~skill();

private:
	string _name;
	//texture = _img
	range  _range;
	int _dmg;
	//Sprite = _action
};

skill::skill()
{
}

skill::~skill()
{
}