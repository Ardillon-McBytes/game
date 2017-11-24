/* En-tête du programme
====================
Programme:        map.hpp
Auteur:           Jean-Alain Sainton
Date création:    31/01/2017
Description  : ce Fichier la classe map, qui contient une map, un nom, et une taille.
Contient aussi les getteur, setteur des méthode pour lire un fichier.
//*******************************************************************/
#pragma once
#include <string>
#include <cassert>
#include <iostream>
#include "point.h"
using namespace std;

template <class TYPE>
class map
{
private:
	char *_name;			//pointeur sur le nom de la map
	TYPE **_map;			//La map dynamique en ligne et colonne
	int  _nbLine, 			//nombre de ligne pour la matrice
		_nbCol;				//nombre de colonne pour la matrice
	point _start,
		_end;

public:
	map();										//constructeur par défault
	map(const char* name, int line, int col);   //constructeur avec 3 parametres
	map(const map<TYPE>& map);					//constructeur de copie
	~map();										//destructeur

	void clear();								//vide toute les valeurs
												//getteurs 
	point getStart()const;
	point getEnd() const;
	int getStartX() const;
	int getStartY() const;
	int getEndX() const;
	int getEndY() const;
	int nbLine()const; 							//retourne le nb de ligne
	int nbCol()const; 							//retourne le nb de colonne
	const char* getName()const; 	  			//retourne le nom de la map

												// setteurs
	void resize(int nbLine, int nbCol);			//resize la matrice avec nouv dims
	char* & map<TYPE>::setName(const char * name);  			//modifie le nom de la map
	TYPE& at(int posI, int posJ)const;			//retourne une référence à l’élément 
												//à la position i,j pour accéder ou modifier
												//autres
	void print(ostream& sortie)const;  			//print la matrice (sans le nom)
	void read(istream& entree);					//lit la matrice de la map ds le flux
	
												//opérateur
	const map<TYPE>& operator=(const map<TYPE>& map); //opérateur =
	TYPE* operator[] (int line);					//opérateur []

};

//opérateur << pour afficher le contenue de map
template <class TYPE>
ostream& operator<<(ostream& sortie, const map<TYPE>& x)
{
	x.print(sortie);
	return sortie;

}

//opérateur >> pour lire les valeurs a mettre dans la map
template <class TYPE>
istream& operator >> (istream& entree, map<TYPE>& x)
{
	x.read(entree);
	return entree;
}

//Constructeur par défaut
template<class TYPE>
map<TYPE>::map()
{


	_nbLine = 0;
	_nbCol = 0;
	_name = nullptr;
	_map = nullptr;
}

//constructeur avec un nom et une taille
template<class TYPE>
map<TYPE>::map(const char * name, int line, int col)
{
	assert(line >= 0 && col >= 0);

	//vide la map
	_map = nullptr;
	_name = nullptr;

	//set la taillde de la map
	_nbLine = line;
	_nbCol = col;

	if (_nbLine > 0 && _nbCol > 0)
	{

		//set la taille du pointeur de ligne
		_map = new TYPE*[_nbLine];
		for (size_t i = 0; i < _nbLine; i++)
		{
			//set la taille du pointeur de col
			*(_map + i) = new TYPE[_nbCol];
			for (size_t j = 0; j < _nbCol; j++)
			{
				*(*(_map + i) + j) = NULL;
			}
		}
	}
	//copie et place le nom dans la map si il a un nom
	int nbrChar = strlen(name);
	if (nbrChar > 0)
	{
		_name = new char[nbrChar + 1];
		strcpy_s(_name, nbrChar + 1, name);
	}
}

//constructeur de copie
template<class TYPE>
map<TYPE>::map(const map<TYPE>& map)
{
	_nbCol = map._nbCol;
	_nbLine = map._nbLine;
	_start = map._start;
	_end = map._end;
	int nameSize;

	if (map._name != nullptr)
	{
		nameSize = strlen(map._name);
		if (nameSize > 0)
		{
			//resize le nom et copie le nom de l'autre map
			_name = new char[nameSize + 1];
			strcpy_s(_name, nameSize + 1, map._name);
		}
	}
	//si le nombre de ligne et le nombre ne sont pas = a 0 et que la map est valide
	if (_nbCol != 0 && _nbLine != 0)
	{
		//set la taille du pointeur de ligne
		_map = new TYPE*[_nbLine];

		//pour chaque ligne
		for (size_t i = 0; i < _nbLine; i++)
		{
			//set la taille du pointeur de collone
			*(_map + i) = new TYPE[_nbCol];
			//pour chaque collone, 
			for (size_t j = 0; j < _nbCol; j++)
			{
				//copie 
				*(*(_map + i) + j) = *(*(map._map + i) + j);
			}
		}
	}
}

//destructeur
template<class TYPE>
 map<TYPE>::~map()
{
	clear();
}

//met les valeurs a 0 et détruie les pointeurs
template<class TYPE>
 void map<TYPE>::clear()
{
	delete[] _name;
	_name = nullptr;

	//vide détruie les lignes 
	for (size_t i = 0; i < _nbLine; i++)
	{
		delete[] * (_map + i);
		*(_map + i) = nullptr;
	}
	//vide détruie la map
	delete[] _map;
	_map = nullptr;

	_nbLine = 0;
	_nbCol = 0;


}

template<class TYPE>
 point map<TYPE>::getStart() const
{
	return _start;
}

template<class TYPE>
 point map<TYPE>::getEnd() const
{
	return _end;
}
template<class TYPE>
 int map<TYPE>::getStartX() const
{
	
	int sizeX = getPosXMid() - (_nbCol / 2);
	return _start.getAbs() + sizeX;
}

template<class TYPE>
 int map<TYPE>::getStartY() const
{
	return _start.getOrd();
}

template<class TYPE>
 int map<TYPE>::getEndX() const
{
	return _end.getAbs();
}

template<class TYPE>
 int map<TYPE>::getEndY() const
{
	return _end.getOrd();
}

//retourne le nombre de ligne
template<class TYPE>
int map<TYPE>::nbLine() const
{
	return _nbLine;
}

//retourne le nombre de colonne
template<class TYPE>
int map<TYPE>::nbCol() const
{
	return _nbCol;
}

//modifie le nombre de ligne et de collone
template<class TYPE>
 void map<TYPE>::resize(int nbLine, int nbCol)
{


	assert(nbLine >= 0 && nbCol >= 0);
	if (nbLine == _nbLine && nbCol == _nbCol)
	{
		return;
	}
	if (nbLine == 0 || nbCol == 0)
	{
		clear();
		return;
	}
	// sauvegarde les données de _map
	TYPE **oldMap = new TYPE*[nbLine];
	for (size_t i = 0; i < nbLine; i++)
	{
		*(oldMap + i) = new TYPE[nbCol];

	}

	for (size_t i = 0; i < _nbLine; i++)
	{
		for (size_t j = 0; j < _nbCol; j++)
		{

			*(*(oldMap + i) + j) = *(*(_map + i) + j);

		}
	}

	//vide la map
	for (size_t i = 0; i < _nbLine; i++)
	{
		delete[] * (_map + i);
		*(_map + i) = nullptr;
	}
	delete[]_map;
	_map = nullptr;


	//recrée la map avec la taille voulu
	_nbCol = nbCol;
	_nbLine = nbLine;

	////recopie les données pour la taille de l'ancienne map
	//for (int i = 0; i < oldNbLine && i < _nbLine; i++)
	//{
	//	for (int j = 0; j < oldNbCol && j < _nbCol; j++)
	//	{
	//		*(*(_map + i) + j) = *(*(oldMap + i) + j);
	//	}

	//}
	_map = oldMap;
	oldMap = nullptr;



}

//retourne la valeur de la ligne I collone J
template<class TYPE>
 TYPE & map<TYPE>::at(int x, int y) const
{
	assert(y >= 0 && y < _nbLine && x >= 0 && x < _nbCol);
	return *(*(_map + y) + x);
}

//retourne la nom de la map
template<class TYPE>
 const char * map<TYPE>::getName() const
{
	if (_name == nullptr || _name == "")
	{
		return "\0";
	}
	return _name;
}

//modifie le nom de la map
template<class TYPE>
char* & map<TYPE>::setName(const char * name)
{
	//détruie l'ancien nom
	delete[] _name;
	_name = nullptr;


	//recrée un pointeur avec une nouvelle taille un nouveau nom
	if (name != nullptr)
	{
		int nbrChar = strlen(name);
		if (nbrChar > 0)
		{
			_name = new char[nbrChar + 1];
			strcpy_s(_name, nbrChar + 1, name);
		}
	}



	return _name;
}

//Affiche le contenue de la map
template<class TYPE>
 void map<TYPE>::print(ostream & sortie) const
{



	if (nbCol() > getTailleConsoleX())
	{
		setFontSize(15,15);
	}
	SetTailleMaxEcran();
	int	sizeX = getTailleConsoleX() / 2;
	sizeX = sizeX - (_nbCol / 2);


	int sizeY = 0;


	for (size_t i = 0; i < _nbLine; i++)				//pr ch ligne
	{
		gotoxy(sizeX, sizeY);
		for (size_t j = 0; j < _nbCol; j++)				//pr ch col
		{
			if (*(*(_map + i) + j) == 48)				//48 ASCII = 0
				sortie << '\0';
			else
				sortie << static_cast<char>(219);		//219 ASCII = BLOCK
		}
		sizeY++;
		sortie << endl;
	}
	gotoxy(sizeX + _start.getAbs(), _start.getOrd());
	cout << 'D';
	gotoxy(sizeX + _end.getAbs(), _end.getOrd());
	cout << 'F';
	gotoxy(0, 0);
}

	//lis un fichier texte contenant un nombre de ligne, un nombre de collone et une matrice
	//et place les valeurs dans la map
	template<class TYPE>
	 void map<TYPE>::read(istream & entree)
	{

		entree >> _nbLine;

		entree >> _nbCol;
		TYPE temp;

		assert(_map == nullptr && _nbLine > 0 && _nbCol > 0);
		_map = new TYPE*[_nbLine];
		for (size_t i = 0; i < _nbLine; i++)
		{
			*(_map + i) = new TYPE[_nbCol];
			for (size_t j = 0; j < _nbCol; j++)
			{
				entree >> temp;
				if (temp == '1')
					*(*(_map + i) + j) = '1';
				else
					*(*(_map + i) + j) = '0';
			}
		}

		int pointX, pointY;

		entree >> pointY;
		_start.setOrd(pointY);
		entree >> pointX;
		_start.setAbs(pointX);

		*(*(_map + pointY)+ pointX) = 1;
		entree >> pointY;
		_end.setOrd(pointY);
		entree >> pointX;
		_end.setAbs(pointX);
		
	}

	//opérateur =

	template<class TYPE>
	const map<TYPE>& map<TYPE>::operator=(const map<TYPE>& map)
	{
		if (this == &map)
			return *this;

		//clear la map et copie la taille
		clear();
		_nbCol = map._nbCol;
		_nbLine = map._nbLine;

		setName(map._name);

		if (_nbLine > 0 && _nbCol > 0)
		{
			//resize la map et copie les valeurs de l'autre map
			_map = new TYPE*[_nbLine];
			//pour chaque ligne
			for (size_t i = 0; i < _nbLine; i++)
			{
				//recrée un pointeur du nombre de collone
				*(_map + i) = new TYPE[_nbCol];
				//pour chaque collone
				for (size_t j = 0; j < _nbCol; j++)
				{
					//copie
					*(*(_map + i) + j) = *(*(map._map + i) + j);
				}
			}
		}
		return *this;
	}

	//opérateur []
	template<class TYPE>
	TYPE* map<TYPE>::operator[](int line)
	{
		assert(line >= 0);
		return *(_map + line);
	}
