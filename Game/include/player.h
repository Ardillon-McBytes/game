#pragma once
#include "Skills.h"
#include "statEntiter.h"
#include "Entiter.h"

class player
{
public:
	player();
	~player();

private:
	string _nom;
	list<entiter> _listHeroe;
	int _bestScore;
	int _lvl;
	list<listItem> _inventory;
};

player::player()
{
}

player::~player()
{
}