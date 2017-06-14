/*
Events.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace Events
*/
#ifndef EVENTS_HPP
#define EVENTS_HPP
#include "Elements.hpp"
#include "MainFrame.hpp"
#include "../enums/Enums.hpp"
/**
Contient la base de tous les types d'events
*/
class Event{
    protected:
    sf::Texture baseTexture;
    std::vector<sf::Texture> otherTextures;
    sf::Sprite *sprite;
    //WaitEnum->EventTrigger
    int eventTrigger = 0;
    sf::Vector2i position;
    public:
    Event(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position);
    virtual ~Event();
    /**Methode appelée chaque frame*/
    virtual update() = 0;
    /**Methode appellée lors du contact avec l'event (voir eventTrigger)*/
    virtual action() = 0;
}

/**
Contient tout ce qui est en rapport avec les evenements
*/
namespace Events {
    namespace EventTrigger{
        const int PRESS = 0, TOUCH = 1, ZONE = 2, IN = 3;
    }
}

#endif // EVENTS_HPP
