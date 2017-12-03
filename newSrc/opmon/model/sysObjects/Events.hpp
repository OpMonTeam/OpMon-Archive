/*
  Events.hpp
  Author : Jlppc
  File under the license GPL-3.0
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
#include "../start/OpString.hpp"

#define SIDE_UP 0x0001
#define SIDE_DOWN 0x0002
#define SIDE_LEFT 0x0010
#define SIDE_RIGHT 0x0020
#define SIDE_ALL (SIDE_UP | SIDE_DOWN | SIDE_RIGHT | SIDE_LEFT)

namespace OpMon{
  namespace Model{

    namespace Events{
      enum class EventTrigger {
	PRESS = 0, GO_IN = 1, ZONE = 2, BE_IN = 3
      };
  
    }

    /**
       Defines a event
    */
    class Event {
    protected:
      std::vector<sf::Texture>& otherTextures;
      //ExpectEnum->EventTrigger
      std::vector::iterator currentTexture;
      Events::EventTrigger eventTrigger;
      sf::Vector2f position;
      bool passable;
      int sides;
      sf::Vector2f mapPos;
    public:
      Event(std::vector<sf::Texture>& otherTextures, Events::EventTrigger eventTrigger, sf::Vector2f const& position, int sides, bool passable);
      virtual ~Event();
      /**This method is called in each frame*/
      virtual void update(Player &player) = 0;
      /**This method is called when the players interacts with the event*/
      virtual void action(Player &player) = 0;
      int getSide() const {
        return sides;
      }
      const sf::Texture &getTexture() {
        return *currentTexture;
      }
      Events::EventTrigger getEventTrigger() const {
        return eventTrigger;
      }

      sf::Vector2f getPosition() const {
        return position;
      }

      sf::Vector2f getPositionMap() const {
	return mapPos;
      }

      bool isPassable() const {
        return passable;
      }
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
      extern sf::Sound shopdoorSound;
      /**
	 Contient les variables utiles sur le dÃ©roulement des events
      */
      namespace EventsVars {

      }


      extern bool justTP;

      class TPEvent : public virtual Event {
      private:
	int frames = -1;
      protected:
	sf::Vector2i tpCoord;
	std::string map;
	Side ppDir;
      public:
	TPEvent(std::vector<sf::Texture>& otherTextures, EventTrigger eventTrigger, sf::Vector2f const& position, sf::Vector2i const& tpPos, std::string const& map, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
	virtual void update(Player &player);
	virtual void action(Player &player);
      };
  
      namespace DoorType {
	extern std::vector<sf::Texture> NORMAL, SHOP;
      }
  
      class DoorEvent : public TPEvent {
      protected:
	int doorType;
	sf::Texture &selectDoorType(int doorType);
	int animStarted = -1;
      public:
	DoorEvent(std::vector<sf::Texture> &doorType, sf::Vector2f const& position, sf::Vector2i const& tpPos, std::string const& map, EventTrigger eventTrigger = EventTrigger::GO_IN, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
	virtual void action(Player &player);
	virtual void update(Player &player);
      };

      class TalkingEvent : public virtual Event {
      private:
	std::vector<OpString> dialogKeys;
      protected:
	std::vector<sf::String> dialogs;
      public:
	TalkingEvent(std::vector<sf::Texture>& otherTextures, sf::Vector2f const& position, std::vector<OpString> const& dialogKeys, int sides = SIDE_ALL, EventTrigger eventTrigger = EventTrigger::PRESS, bool passable = false);
	void reloadKeys();
	virtual void update(Player &player);
	virtual void action(Player &player);
      };

      class LockedDoorEvent : public DoorEvent, TalkingEvent {
      protected:
	Item *needed;
	bool consumeItem;
	static std::vector<OpString> keysLock;
      public:
	virtual void action(Player &player);
	virtual void update(Player &player);
	LockedDoorEvent(std::vector<sf::Texture> &doorType, Item *needed, sf::Vector2f const& position, sf::Vector2i const& tpPos, std::string const& map, Side ppDir = Side::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, bool consumeItem = false,int sides = SIDE_ALL, bool passable = false);
      };

      enum class MoveStyle : int {
	NO_MOVE = 0, PREDEFINED = 1, RANDOM = 2, FOLLOWING = 3
      };

      class CharacterEvent : public virtual Event {
      protected:
	MoveStyle moveStyle;
  
	Side charaDir = Side::TO_DOWN;
	Side anim = Side::NO_MOVE;
	Side moving = Side::NO_MOVE;

	unsigned int predefinedCounter = 0;
	int animsCounter = 0;
  
	std::vector<Side> movements;

	int startFrames = 0;
	bool anims = false;
	int frames = 0;

      public:
	CharacterEvent(std::string texturesKey, sf::Vector2f const& position, MoveStyle moveStyle = MoveStyle::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int sides = SIDE_ALL);
	virtual void update(Player &player);
	virtual void action(Player &player) {};
	void setPredefinedMove(std::vector<Side> movement);
	void move(Side direction, Player& player);
      };



      class TalkingCharaEvent : public CharacterEvent, TalkingEvent {

	bool talking = false;

      public:
	TalkingCharaEvent(std::string texturesKey, sf::Vector2f const& position, std::vector<OpString> const& dialogKeys, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);
      public:
	virtual void update(Player &player);
	virtual void action(Player &player);
      };
    }

  }
}
#endif // EVENTS_HPP
