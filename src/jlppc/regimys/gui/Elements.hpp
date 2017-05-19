/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
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

/*class Event{
private:
    //->WaitEnum->ActionType
    int actionType;
    bool passable;
    SDL_Texture *apparence;
public:
    virtual void action() = 0;
    virtual void update() = 0;
    Event(SDL_Texture *texture, bool passable, int actionType) : apparence(texture) {this->passable = passable;this->actionType = actionType;}
    bool isPassable(){return passable;}
    int getActionType(){return actionType;}
    SDL_Texture* getApparence() {return apparence;}
};*/

/**
Classe définissant une carte d'un lieu en particulier
*/
class Plan {
private:
    SDL_Texture *couche1;
    SDL_Texture *couche2;
    Mix_Music *fond;
    //Event events;
    int w;
    int h;
    SDL_Texture *couche3;
    int **passTab;
public:
    Plan(SDL_Texture *couche1, SDL_Texture *couche2, SDL_Texture *couche3, int w, int h, std::string filename, std::string fondPath);
    ~Plan();
    int getH() const {
        return h;
    }
    int getW() const {
        return w;
    }
    int** getPassTab() const {
        return passTab;
    }
    SDL_Texture* getCouche1() const {
        return couche1;
    }
    SDL_Texture* getCouche2() const {
        return couche2;
    }
    SDL_Texture* getCouche3() const {
        return couche3;
    }
    Mix_Music* getFond() const {
        return &fond;
    }
    //Event* getEvent(int x, int y){return events[y][x];}
};
/**
Structure permettant de regrouper les SDL_Texture avec un SDL_Rect correspondant
*/
struct J_Texture {
    SDL_Texture *texture;
    SDL_Rect rect;
};
/**
Permet d'afficher une J_Texture
*/
int J_RenderCopy(SDL_Renderer *renderer, J_Texture *texture);

typedef struct J_Texture J_Texture;

#endif // ELEMENTS_HPP
