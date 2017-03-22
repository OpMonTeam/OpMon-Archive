/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Fichier contenant des éléments utiles
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <iostream>

class Case{
private:
    SDL_Texture *texture;
    public:
    Case(SDL_Texture *texture);
};

class Event : public Case{
private:
    int actionType;
    bool passable;
public:
    virtual void action() = 0;
    virtual void update() = 0;
    Event(SDL_Texture *texture, bool passable) : Case(texture) {this->passable = passable;}
};

class Plan{
private:
    Case *couche1[32][32];
    Case *couche2[32][32];
    Event *events[32][32];
    int playerX;
    int playerY;
    Case *couche3[32][32];
public:
    Plan();//TODO
    ~Plan();//TODO
};

namespace Elements {


}


#endif // ELEMENTS_HPP
