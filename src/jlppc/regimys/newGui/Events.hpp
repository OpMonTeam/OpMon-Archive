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
    virtual void update() = 0;
    /**Methode appellée lors du contact avec l'event (voir eventTrigger)*/
    virtual void action() = 0;
};

/**
Contient tout ce qui est en rapport avec les evenements
*/
namespace Events {
    namespace EventTrigger{
        const int PRESS = 0, TOUCH = 1, ZONE = 2, BE_IN = 3;
    }

    class TPEvent : public Event{
        protected:
        sf::Vector2i tpCoord;
        int mapID;
        public:
        TPEvent(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position, sf::Vector2i tpPos, int mapID);
        virtual void update();
        virtual void action();
    };
    namespace DoorType{
        const int NORMAL = 0, SHOP = 1;
    }
    class DoorEvent : public TPEvent{
        protected:
        //WaitEvent->DoorType
        int doorType;
        public:
        DoorEvent(int doorType, sf::Vector2i position, sf::Vector2i tpPos, int eventTrigger = 3);
        virtual void action();
    };

    namespace MoveStyle{
        const int NO_MOVE = 0, PREDEFINED = 1, RANDOM = 2, FOLLOWING = 3;
    }

    class CharacterEvent : public Event{
        protected:
        //WaitEnum->MoveStyle
        int moveStyle;
        public:
        CharacterEvent(std::vector<sf::Texture> charTextures, sf::Vector2i position, int moveStyle = 0, int eventTrigger = 0);
        virtual void update();
        virtual void action() = 0;
    };

    class TalkingEvent : public Event{
        private:
        std::vector<std::string> dialogKeys;
        protected:
        std::vector<std::string> dialogs;
        public:
        TalkingEvent(sf::Texture baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2i position, std::vector<std::string> dialogKeys);
        void reloadKeys();
        virtual void update();
        virtual void action();
    };

    class TalkingCharaEvent : public TalkingEvent, CharacterEvent{
        public:
        TalkingCharaEvent(std::vector<sf::Texture> charTextures, sf::Vector2i position, std::vector<std::string> dialogKeys, int eventTrigger = 0, int moveStyle = 0);
        public:
        virtual void update();
        virtual void action();
    };
}

#endif // EVENTS_HPP
