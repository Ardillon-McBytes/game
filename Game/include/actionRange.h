#pragma once
class range
{
public:
	range();
	~range();

private:
	int _distanceFromUser,
		_tailleEffect;
	bool _line;

};

range::range()
{
	_distanceFromUser = 1;
	_tailleEffect = 1;
	_line = false;
}

range::~range()
{
	_distanceFromUser = 1;
	_tailleEffect = 1;
	_line = false;
}