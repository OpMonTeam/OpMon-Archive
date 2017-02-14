/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Fichier contenant des définitions de structures d'élements
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <SDL/SDL.h>



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
typedef struct StartScene StartScene;
typedef struct Dialog Dialog;

#endif // ELEMENTS_HPP
