/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Fichier contenant des éléments utiles
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
Classe définissant une carte d'un lieu en particulier
*/
class Plan {
public:
    sf::Texture* couche1;
    sf::Texture* couche2;
    sf::Music *fond;
    //Event events;
    int w;
    int h;
    sf::Texture* couche3;
    int **passTab;
    /**Le constructeur ne doit pas etre utilsé.
    Il est donc en privé. Si tout de meme cette protection est inéfficace,
    aucune definition n'est fournise de ce constructeur.*/
    Plan(Plan const& toCopy);
public:
    Plan(sf::Texture couche1, sf::Texture couche2, sf::Texture couche3, int w, int h, std::string filename, sf::Music* fond);
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
    sf::Texture* getCouche1()  {
        return couche1;
    }
    sf::Texture* getCouche2()  {
        return couche2;
    }
    sf::Texture* getCouche3()  {
        return couche3;
    }
    sf::Music* getFond() {
        return fond;
    }

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
