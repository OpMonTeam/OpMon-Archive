/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Fichier contenant des �l�ments utiles
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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
Classe d�finissant une carte d'un lieu en particulier
*/
class Plan {
public:
    sf::Sprite* couche1;
    sf::Sprite* couche2;
    sf::Music *fond;
    //Event events;
    int w;
    int h;
    sf::Sprite* couche3;
    std::string musicPath;
    int **passTab;
public:
    Plan(sf::Texture couche1, sf::Texture couche2, sf::Texture couche3, int w, int h, std::string filename, std::string fondPath);
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
    sf::Sprite* getCouche1()  {
        return couche1;
    }
    sf::Sprite* getCouche2()  {
        return couche2;
    }
    sf::Sprite* getCouche3()  {
        return couche3;
    }
    sf::Music* getFond() {
        return fond;
    }

    std::string getMusicPath() const {
        return musicPath;
    }

    void setPos(sf::Vector2f const& vect);
    //Event* getEvent(int x, int y){return events[y][x];}
};
/*/**
Structure permettant de regrouper les SDL_Texture avec un SDL_Rect correspondant
*//*
struct J_Texture {
    SDL_Texture *texture;
    SDL_Rect rect;
};
/**
Permet d'afficher une J_Texture
*//*
int J_RenderCopy(SDL_Renderer *renderer, J_Texture *texture);

typedef struct J_Texture J_Texture;*/

#endif // ELEMENTS_HPP
