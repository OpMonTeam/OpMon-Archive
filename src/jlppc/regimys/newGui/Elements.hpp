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

#include "Events.hpp"
#include "../playercore/Player.hpp"

class Event;

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
    sf::Texture* couche1;
    sf::Texture* couche2;
    sf::Music *fond;
    //Event events;
    int w;
    int h;
    sf::Texture* couche3;
    int **passTab;
    /**Le constructeur de copie ne doit pas etre utilsé.
    Il est donc en privé. Si tout de meme cette protection est inéfficace,
    aucune definition n'est fournise de ce constructeur.*/
    Plan(Plan const& toCopy);

    std::vector<Event*> events;

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
    void addEvent(Event *event){
        events.push_back(event);
    }
    std::vector<Event*> getEvent(sf::Vector2i position);
    std::vector<Event*> getEvents(){return events;};
    void updateEvents(Player &player);
};


#endif // ELEMENTS_HPP
