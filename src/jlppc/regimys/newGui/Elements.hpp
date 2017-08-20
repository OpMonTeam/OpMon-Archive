/*
Elements.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Fichier contenant des Ã©lÃ©ments utiles
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../playercore/Player.hpp"

class Event;

/**
Classe définissant une carte d'un lieu en particulier
*/
class Map {
    private:
        sf::Texture *layer1;
        sf::Texture *layer2;
        sf::Music *bg;
        //Event events;
        int w;
        int h;
        sf::Texture *layer3;
        int **passTab;
        /**Le constructeur de copie ne doit pas etre utilsÃ©.
        Il est donc en privÃ©. Si tout de meme cette protection est inÃ©fficace,
        aucune definition n'est fournise de ce constructeur.*/
        Map(Map const &toCopy);

        std::vector<Event *> events;

        std::vector<std::vector<sf::Texture> > animatedElements;
        std::vector<sf::Vector2f> elementsPos;
        std::vector<sf::Sprite> elementsSprites;
        std::vector<int> elementsCount;

    public:
        Map(sf::Texture const& layer1, sf::Texture const& layer2, sf::Texture const& layer3, int w, int h, std::string const& filename, sf::Music *bg, std::vector<std::vector<sf::Texture> > const& animatedElements = std::vector<std::vector<sf::Texture> >(), std::vector<sf::Vector2f> const& elementsPos = std::vector<sf::Vector2f>());
        ~Map();
        int getH() const {
            return h;
        }
        int getW() const {
            return w;
        }
        int **getPassTab() const {
            return passTab;
        }
        const sf::Texture *getLayer1() const {
            return layer1;
        }
        const sf::Texture *getLayer2() const {
            return layer2;
        }
        const sf::Texture *getLayer3() const {
            return layer3;
        }
        sf::Music *getBg() const {
            return bg;
        }
        void addEvent(Event *event) {
            events.push_back(event);
        }
        std::vector<Event *> getEvent(sf::Vector2i position);
        const std::vector<Event *> getEvents() const {
            return events;
        };
        void updateEvents(Player &player);
        void debugInfo();
        void updateElements(sf::RenderTexture &frame);
};


#endif // ELEMENTS_HPP
