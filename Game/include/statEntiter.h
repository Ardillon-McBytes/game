#pragma once

class statEntiter
{

private:
	int _hp,
		_xp,
		_dmg,
		_atckSpeed,
		_mouvSpeed;

public:
	statEntiter();
	~statEntiter();
};

statEntiter::statEntiter()
{
	_hp = _xp = 0;
	_dmg = _atckSpeed = _mouvSpeed = 1;
}

statEntiter::~statEntiter()
{
	_hp = _xp = 0;
	_dmg = _atckSpeed = _mouvSpeed = 1;
}