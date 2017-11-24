#pragma once
#include "Skills.h"
#include "statEntiter.h"
#include <list>
#include "bestScore.h"
#include "gameItem.h"
struct heroes
{
	entiter _info;
	bestScore _bestScore;
};

struct boss
{
	entiter _info;
	int _size;
};

class entiter
{
public:
	entiter();
	~entiter();

private:
	int _lvl;
	string _nom;
	list<skill> _skills;
	statEntiter _statEntiter;
	list<item> _itemEquip;
	//Texture _img
	
	
};

entiter::entiter()
{
}

entiter::~entiter()
{
}