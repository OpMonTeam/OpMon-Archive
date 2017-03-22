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
#include <vector>



class Case{
private:
    SDL_Texture *texture;
    public:
    Case(SDL_Texture *texture);
    SDL_Texture* getTexture(){return texture;}
};

class Event : public Case{
private:
    //->WaitEnum->ActionType
    int actionType;
    bool passable;
public:
    virtual void action() = 0;
    virtual void update() = 0;
    Event(SDL_Texture *texture, bool passable, int actionType) : Case(texture) {this->passable = passable;this->actionType = actionType;}
    bool isPassable(){return passable;}
    int getActionType(){return actionType;}
};

typedef std::vector<std::vector<Case> > Couche;
typedef std::vector<std::vector<Event*> > EventMap;

class Plan{
private:
    Couche couche1;
    Couche couche2;
    EventMap events;
    int playerX;
    int playerY;
    Couche couche3;
public:
    Plan(Couche couche1, Couche couche2, EventMap events, Couche couche3);
    ~Plan();
    Case getCouche1(int x, int y){return couche1[y][x];}
    Case getCouche2(int x, int y){return couche2[y][x];}
    Event* getEvent(int x, int y){return events[y][x];}
    Case getCouche3(int x, int y){return couche3[y][x];}
};

namespace Elements {


}


#endif // ELEMENTS_HPP
