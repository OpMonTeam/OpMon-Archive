/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Fichier contenant... des trucs useless. :T
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <SDL/SDL.h>
#include <iostream>

//->Useless
struct Text {

};
//->Useless
struct Coordonnees {
	int x;
	int y;
	int h;
	int w;
};
//->Useless
namespace Elements {
	Coordonnees initCoordonnees();

}

typedef struct Coordonnees Coordonnees;
typedef struct Text Text;

#endif // ELEMENTS_HPP
