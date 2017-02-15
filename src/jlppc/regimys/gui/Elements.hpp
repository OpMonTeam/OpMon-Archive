/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Fichier contenant... je sais pas trop.
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <SDL/SDL.h>
#include <iostream>


struct Text{
    SDL_Texture *toPrint;
    std::string text;
};

struct Coordonnees{
    int x;
    int y;
    int h;
    int w;
};

namespace Elements{
    Coordonnees initCoordonnees();

}

typedef struct Coordonnees Coordonnees;
typedef struct Text Text;

#endif // ELEMENTS_HPP
