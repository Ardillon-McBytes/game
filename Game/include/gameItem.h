#pragma once
#include "actionEffect.h"
#include "actionRange.h"
#include <string>
#include <list>
using namespace std;

struct listItem
{
	item _item;
	int _quantity;
};

class item
{
public:
	item();
	~item();

private:
	
	class typeItem
	{
	public:
		typeItem();
		~typeItem();

	private:
		int _type;				//ex : 1 pour equipement, 2 pour consumable, 3 pour trap, etc
		actionEffect _affect;
		int dmg,
			cooldown;
		range _range;
		int _rarity;			//ex: 1 normal, 2 rare, 3 epic
	};

	string _nom;
	typeItem _typeItem;
	int _lvlMin;

};
item::typeItem::typeItem()
{
}

item::typeItem::~typeItem()
{
}
item::item()
{
}

item::~item()
{
}