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
#include "../start/Initializer.hpp"
#include "../objects/item/Item.hpp"

#define SIDE_UP 0x0001
#define SIDE_DOWN 0x0002
#define SIDE_LEFT 0x0010
#define SIDE_RIGHT 0x0020
#define SIDE_ALL (SIDE_UP | SIDE_DOWN | SIDE_RIGHT | SIDE_LEFT)

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
  int sides;
    public:
  Event(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, int sides, bool passable);
    virtual ~Event();
    /**Methode appelée chaque frame*/
    virtual void update(Player &player) = 0;
    /**Methode appellée lors du contact avec l'event (voir eventTrigger)*/
    virtual void action(Player &player) = 0;
  int getSide(){return sides;}
    sf::Sprite* getSprite(){return sprite;}
    sf::Texture& getTexture(){return baseTexture;}
    int getEventTrigger(){return eventTrigger;}

    virtual sf::Vector2f getPosition(){return position;}
};

void initEnumsEvents();
/**
Contient tout ce qui est en rapport avec les evenements
*/
namespace Events {
  /**
     Le son des portes
  */
  extern sf::Sound doorSound;
    /**
    Contient les variables utiles sur le déroulement des events
    */
    namespace EventsVars{

    }

    namespace EventTrigger{
        const int PRESS = 0, GO_IN = 1, ZONE = 2, BE_IN = 3;
    }

    extern bool justTP;

    class TPEvent : public virtual Event{
        private:
        int frames = -1;
        protected:
        sf::Vector2i tpCoord;
        int mapID;
        int ppDir;
        public:
      TPEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, int eventTrigger, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int ppDir = -1, int sides = SIDE_ALL, bool passable = true);
        virtual void update(Player &player);
        virtual void action(Player &player);
    };
    namespace DoorType{
        extern std::vector<sf::Texture> NORMAL, SHOP;
    }
    class DoorEvent : public TPEvent{
        protected:
        //WaitEvent->DoorType
        int doorType;
        sf::Texture& selectDoorType(int doorType);
        int animStarted = -1;
        public:
      DoorEvent(std::vector<sf::Texture>& doorType, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int eventTrigger = 1, int ppDir = -1, int sides = SIDE_ALL, bool passable = true);
        virtual void action(Player &player);
        virtual void update(Player &player);
    };

    class TalkingEvent : public virtual Event{
        private:
        std::vector<std::string> dialogKeys;
        protected:
        std::vector<sf::String> dialogs;
        public:
      TalkingEvent(sf::Texture &baseTexture, std::vector<sf::Texture> otherTextures, sf::Vector2f position, std::vector<std::string> dialogKeys, int sides = SIDE_ALL, int eventTrigger = 0, bool passable = false);
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
      LockedDoorEvent(std::vector<sf::Texture>& doorType, Item* needed, sf::Vector2f position, sf::Vector2i tpPos, int mapID, int ppDir = -1, int eventTrigger = 0, bool consumeItem = false,int sides = SIDE_ALL, bool passable = false);
    };

    namespace MoveStyle{
        const int NO_MOVE = 0, PREDEFINED = 1, RANDOM = 2, FOLLOWING = 3;
    }

    class CharacterEvent : public virtual Event{
        protected:
        //WaitEnum->MoveStyle
        int moveStyle;
        public:
      CharacterEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, int moveStyle = 0, int eventTrigger = 0, bool passable = false, int sides = SIDE_ALL);
        virtual void update(Player &player);
        virtual void action(Player &player) = 0;
        virtual void setPredefinedMove(std::vector<int> movement);
    };



    class TalkingCharaEvent : public TalkingEvent, CharacterEvent{
        public:
      TalkingCharaEvent(std::vector<sf::Texture> charTextures, sf::Vector2f position, std::vector<std::string> dialogKeys, int eventTrigger = 0, int moveStyle = 0, bool passable = false, int side = SIDE_ALL);
        public:
        virtual void update(Player &player);
        virtual void action(Player &player);
    };
}

#endif // EVENTS_HPP
