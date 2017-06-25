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
#include "../start/main.hpp"
#include "../objects/item/Item.hpp"
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
    sf::Vector2f position;
    bool passable;
    public:
    Event(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, bool passable);
    virtual ~Event();
    /**Methode appelée chaque frame*/
    virtual void update(Player &player) = 0;
    /**Methode appellée lors du contact avec l'event (voir eventTrigger)*/
    virtual void action(Player &player) = 0;

    sf::Sprite getSprite(){return *sprite;}
    int getEventTrigger(){return eventTrigger;}

    virtual sf::Vector2f getPosition(){return position;}
};

/**
Contient tout ce qui est en rapport avec les evenements
*/
namespace Events {
    /**
    Contient les variables utiles sur le déroulement des events
    */
    namespace EventsVars{

    }

    namespace EventTrigger{
        const int PRESS = 0, TOUCH = 1, ZONE = 2, BE_IN = 3;
    }

    class TPEvent : public virtual Event{
        protected:
        sf::Vector2i tpCoord;
        int mapID;
        public:
        TPEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, sf::Vector2i tpPos, int mapID, bool passable);
        virtual void update(Player &player);
        virtual void action(Player &player);
    };
    namespace DoorType{
        const int NORMAL = 0, SHOP = 1;
    }
    class DoorEvent : public TPEvent{
        protected:
        //WaitEvent->DoorType
        int doorType;
        sf::Texture& selectDoorType(int doorType);
        std::vector<sf::Texture> selectDoorTypeOther(int doorType);
        public:
        DoorEvent(int doorType, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int eventTrigger = 3, bool passable = true);
        virtual void action(Player &player);
        virtual void update(Player &player);
    };

    class TalkingEvent : public virtual Event{
        private:
        std::vector<std::string> dialogKeys;
        protected:
        std::vector<sf::String> dialogs;
        public:
        TalkingEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, sf::Vector2f position, std::vector<std::string> dialogKeys, int eventTrigger = 0, bool passable = false);
        void reloadKeys();
        virtual void update(Player &player);
        virtual void action(Player &player);
    };

    class LockedDoorEvent : public DoorEvent, TalkingEvent{
        protected:
            Item *needed;
            bool consumeItem;
            static std::vector<std::string> keysLock;
        public:
        virtual void action(Player &player);
        virtual void update(Player &player);
        LockedDoorEvent(int doorType, Item* needed, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int eventTrigger = 0, bool consumeItem = false, bool passable = false);
    };

    namespace MoveStyle{
        const int NO_MOVE = 0, PREDEFINED = 1, RANDOM = 2, FOLLOWING = 3;
    }

    class CharacterEvent : public virtual Event{
        protected:
        //WaitEnum->MoveStyle
        int moveStyle;
        public:
        CharacterEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, int moveStyle = 0, int eventTrigger = 0, bool passable = false);
        virtual void update(Player &player);
        virtual void action(Player &player) = 0;
        virtual void setPredefinedMove(std::vector<int> movement);
    };



    class TalkingCharaEvent : public TalkingEvent, CharacterEvent{
        public:
        TalkingCharaEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, std::vector<std::string> dialogKeys, int eventTrigger = 0, int moveStyle = 0, bool passable = false);
        public:
        virtual void update(Player &player);
        virtual void action(Player &player);
    };
}

#endif // EVENTS_HPP
