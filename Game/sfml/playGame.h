#pragma once
#include "player.h"
#include <map>
#include <fstream>
#include <iostream>
using namespace std;
class game
{
public:
	game();
	~game();

private:
	map<int> map;
	player joueur;
	heroes heroe;
	list<entiter> monster;
	list<item> item;
	int _difficulty;
};

game::game()
{
}

game::~game()
{
}

int playGame(player joueur,list<entiter> monster, map<int> map)
{
	int nbrItem = rand() % 5 + 1;
	list<entiter> mapMonster;
	list<item> mapItem;

	
	int deadMonster;
	iniMap(map);
	initMapEntity(monster);

	boss boss;
	int rdmMonster = rand() % monster.size() + 1;
	boss.size() = monster[i].size * 4;
	boss = monster[i];

	while (joueur.hp != 0 || map.complete == true)
	{
		joueur.action();
		//action a déterminer avec la SFML et les action voulu
		switch(event)
			case: bouge //déplace le joueur si possible
			case: attaque(mapMonstre)  //affiche l'action (attaque/spell). si un ou plusieur monstres sont présent dans le range, monstre hp -= dmg
			case: action(joueurs,map,monstre,item) //utiliser les objets, maybe ouvrir des portes, mettre des traps, pause, etc
			default : 

		for (size_t i = 0; i < mapItem.size(); i++)
		{
			
			if (joueur.pos == mapItem[i].pos);
			{
				switch (mapItem[i].type)
				{
				case:1 //consumable
					joueur.inventory.consumable.push(mapItem[i]);
					break;
				case:2 //equipement
					joueur.inventory.equipement.push(mapItem[i]);
					break;
				case:3 //trap
					joueur.actionTrap();
					break;
				default:
					break;
				}
				joueur.inventory.push(mapItem[i]);
				mapItem[i].erase();
			}
		}
		monster.action();

		for (size_t i = 0; i < monster.size(); i++)
		{
			if (monster[i].hp <= 0)
			{
				joueur.exp += monster[i].exp;
				monster[i].setDead; //image du monstre mort
				deadMonster++;
			}
		}
		if (map.objective == deadMonster )
		{
			map.at(monster[rdmMonster].posX, monster[rdmMonster].posY) = 4; //on va dire que boss = 4
			monster.push_back(boss);
			display(monster.back);
		}
		if (boss.hp <= 0)
		{
			map.complete == true;
		}
	}
	joueur.save(local);
	try
	{
		joueur.save(server);
	}
	catch (const std::exception&)
	{
		display("Can't save on server, try again later",error);
	}

	showEndScreen();
	
}
//list les fichier et initialise les heroes
bool initGame(player joueur)
{
	//initEntiter;

	joueur.getSave();
	if (joueur.nbrHeroe == 0)
		selectHeroes();
	else
		initPlayerItems();

	return true;
}

bool initEntier(list<heroes> heroes, list<entiter> monster)
{
	ifstream fichier;
	string name;

	// pour fichier heroe
	while (!fichier.eof())
	{

		fichier >> heroes.front()._info.nom;//lire info sur les heroe
		heroes++;
	}
	// pour fichier monster
	while (!fichier.eof())
	{

		fichier >> monster.front()._info.nom;//lire info sur les heroe
		heroes++;
	}
	return true;

}


bool initPlayerItems(player joueur)
{
	for (size_t i = 0; i < joueur.item.size(); i++)
	{
		joueur.item[i].search();
	}


}

bool initMapTexture(list<texture> textureMap)
{
	ifstream fichier;
	int i = 0;
	string textureName;

	while (dossierVide == false)
	{
		fichier  >> textureName;
		textureMap.add(textureName);
		i++;
	}
}

bool iniMap(string mapName)
{
//algo de création de map

}

void initMapEntity(list<TYPE> object, int qty)
{
	game.object.clear()
	for (size_t i = 0; i < object.size(); i++)
	{
		game.object.push(object.at(rand()% object.size()))
	}
	point pos;
	pos.x = rand() % map.nbrRow();
	pos.y = rand() % map.nbrLine();
	//place les item ou les monster a un endroit libre sur la map
	for (size_t i = 0; i < object.size(); i++)
	{
		while (map.at(pos.x,pos,y) != 0)
		{
			pos.x = rand() % map.nbrRow();
			pos.y = rand() % map.nbrLine();
		}
		map.at(pos.x,pos.y) == 3 //on va dire que 3 est un monstre pour l'instant;
	}

	return;

}