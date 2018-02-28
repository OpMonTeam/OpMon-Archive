/*
  Events.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga 
  Contains the Events namespace 
*/
#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../../../utils/OpString.hpp"
#include "../../../utils/defines.hpp"
#include "../../start/i18n/ATranslatable.hpp"
#include "../objects/Enums.hpp"
#include "Player.hpp"

#define SIDE_UP 0x0001
#define SIDE_DOWN 0x0002
#define SIDE_LEFT 0x0010
#define SIDE_RIGHT 0x0020
#define SIDE_ALL (SIDE_UP | SIDE_DOWN | SIDE_RIGHT | SIDE_LEFT)

namespace OpMon {

    namespace View {
        class Overworld;
    }

    namespace Model {

        namespace Events {
            enum class EventTrigger {
                PRESS = 0,
                GO_IN = 1,
                ZONE = 2,
                BE_IN = 3
            };
        }

        /**
       Defines an event
    */
        class Event {
          protected:
            std::vector<sf::Texture> &otherTextures;
            //ExpectEnum->EventTrigger

            sf::Sprite *sprite;

            std::vector<sf::Texture>::iterator currentTexture;
            Events::EventTrigger eventTrigger;
            sf::Vector2f position; //Sprite's position
            bool passable;
            int sides;
            Position mapPos;

          public:
            Event(std::vector<sf::Texture> &otherTextures, Events::EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable);
            virtual ~Event();
            /**This method is called in each frame*/
            virtual void update(Model::Player &player, View::Overworld &overworld) = 0;
            /**This method is called when the players interacts with the event*/
            virtual void action(Model::Player &player, View::Overworld &overworld) = 0;

            void updateTexture();

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

            Position getPositionMap() const {
                return mapPos;
            }

            bool isPassable() const {
                return passable;
            }
            const sf::Sprite *getSprite() const {
                return sprite;
            }
        };

        void initEnumsEvents();
        /**
       Contient tout ce qui est en rapport avec les evenements
    */
        namespace Events {
            /**
	 Doors sound
      */
            extern sf::Sound doorSound;
            extern sf::Sound shopdoorSound;
            /**
	 Contains useful variables on the running of the events
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
                TPEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &player, View::Overworld &overworld);
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
                DoorEvent(std::vector<sf::Texture> &doorType, sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, EventTrigger eventTrigger = EventTrigger::GO_IN, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
                virtual void action(Model::Player &player, View::Overworld &overworld);
                virtual void update(Model::Player &player, View::Overworld &overworld);
            };

            class TalkingEvent : public virtual Event, I18n::ATranslatable {
              private:
                std::vector<Utils::OpString> dialogKeys;

              protected:
                std::vector<sf::String> dialogs;

              public:
                TalkingEvent(std::vector<sf::Texture> &otherTextures, sf::Vector2f const &position, std::vector<Utils::OpString> const &dialogKeys, int sides = SIDE_ALL, EventTrigger eventTrigger = EventTrigger::PRESS, bool passable = false);
                void onLangChanged() override;
                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &player, View::Overworld &overworld);
            };

            class LockedDoorEvent : public DoorEvent, TalkingEvent {
              protected:
                Item *needed;
                bool consumeItem;
                static std::vector<Utils::OpString> keysLock;

              public:
                virtual void action(Model::Player &player, View::Overworld &overworld);
                virtual void update(Model::Player &player, View::Overworld &overworld);
                LockedDoorEvent(std::vector<sf::Texture> &doorType, Item *needed, sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, Side ppDir = Side::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, bool consumeItem = false, int sides = SIDE_ALL, bool passable = false);
            };

            enum class MoveStyle : int {
                NO_MOVE = 0,
                PREDEFINED = 1,
                RANDOM = 2,
                FOLLOWING = 3
            };

            class CharacterEvent : public virtual Event {
              protected:
                MoveStyle moveStyle;

                unsigned int predefinedCounter = 0;
                int animsCounter = 0;

                std::vector<Side> movements;

                int startFrames = 0;
                bool anims = false;
                int frames = 0;

              public:
	      CharacterEvent(std::string texturesKey, sf::Vector2f const &position, Side posDir = Side::TO_UP, MoveStyle moveStyle = MoveStyle::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int sides = SIDE_ALL);
                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &, View::Overworld &){};
                void setPredefinedMove(std::vector<Side> movement);
                OP_DEPRECATED void move(Side direction, Model::Player &player, View::Overworld &overworld);
                void move(Side direction);
            };

            class TalkingCharaEvent : public CharacterEvent, TalkingEvent {

                bool talking = false;

              public:
                TalkingCharaEvent(std::string texturesKey, sf::Vector2f const &position, std::vector<Utils::OpString> const &dialogKeys, Side posDir = Side::TO_UP, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);

              public:
                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &player, View::Overworld &overworld);
            };
        } // namespace Events

    } // namespace Model
} // namespace OpMon
#endif // EVENTS_HPP
