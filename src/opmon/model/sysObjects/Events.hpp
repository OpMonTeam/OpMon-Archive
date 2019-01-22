/*
  Events.hpp
  Author : Cyriel
  Contributors : BAKFR, Navet56
  File under GNU GPL v3.0 license.
*/
#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>

#include "../../../utils/OpString.hpp"
#include "../../../utils/defines.hpp"
#include "../../start/i18n/ATranslatable.hpp"
#include "../objects/Enums.hpp"
#include "Player.hpp"
#include "Position.hpp"

//Macros defining constants to know the side from where the events can be triggered.
//Inspired by SDL's system to initialize the different modules

#define SIDE_UP 0x0001
#define SIDE_DOWN 0x0002
#define SIDE_LEFT 0x0010
#define SIDE_RIGHT 0x0020
#define SIDE_ALL (SIDE_UP | SIDE_DOWN | SIDE_RIGHT | SIDE_LEFT)
//TODO : Disable it
#pragma GCC diagnostic ignored "-Wreorder"

namespace OpMon {

    namespace View {
        class Overworld;
    }

    namespace Model {

        namespace Events {
            //Used to know when the event must be triggered, relatively to the player
            enum class EventTrigger {
                PRESS = 0,
                GO_IN = 1,
                ZONE = 2,
                BE_IN = 3
            };
        } // namespace Events

        /**
          Defines an event
        */
        class Event {
          protected:
            std::vector<sf::Texture> &otherTextures;

            std::unique_ptr<sf::Sprite> sprite;

            std::vector<sf::Texture>::iterator currentTexture;
            Events::EventTrigger eventTrigger;
            sf::Vector2f position; //Sprite's position
            bool passable = false;
            int sides = SIDE_ALL;
            Position mapPos;

          public:
            Event(std::vector<sf::Texture> &otherTextures, Events::EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable);
            virtual ~Event() = default;
            /**This method is called at each frame*/
            virtual void update(Model::Player &player, View::Overworld &overworld) = 0;
            /**This method is called when the player interacts with the event*/
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
                return sprite.get();
            }
        };

        void initEnumsEvents();
        /**
	   Contains stuff in relation with the events, mostly different types of events.
	*/
        namespace Events {
            /**
	     Doors sounds (TODO : Move them)
	    */
            extern sf::Sound doorSound;
            extern sf::Sound shopdoorSound;

            //TODO : Move it
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

            class DoorEvent : public TPEvent {
              protected:
                std::string doorType;
                int animStarted = -1;

              public:
                /* Types of door (to put in doorType (TODO)) : "door" | "shop door"*/
                DoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, EventTrigger eventTrigger = EventTrigger::GO_IN, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
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
                virtual void changeDialog(std::vector<Utils::OpString> newDialog);
            };

            class LockedDoorEvent : public DoorEvent, TalkingEvent {
              protected:
                Item *needed;
                bool consumeItem;
                static std::vector<Utils::OpString> keysLock;

              public:
                virtual void action(Model::Player &player, View::Overworld &overworld);
                virtual void update(Model::Player &player, View::Overworld &overworld);
                LockedDoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, Item *needed, sf::Vector2f const &position, sf::Vector2i const &tpPos, std::string const &map, Side ppDir = Side::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, bool consumeItem = false, int sides = SIDE_ALL, bool passable = false);
            };

            //Ways to move for the npcs
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
                CharacterEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Side posDir = Side::TO_UP, MoveStyle moveStyle = MoveStyle::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int sides = SIDE_ALL);
                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &, View::Overworld &){};
                void setPredefinedMove(std::vector<Side> movement);
                OP_DEPRECATED void move(Side direction, Model::Player &player, View::Overworld &overworld);
                bool move(Side direction, Map *map);
            };

            class TalkingCharaEvent : public CharacterEvent, TalkingEvent {
              protected:
                bool talking = false;

              public:
                TalkingCharaEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, std::vector<Utils::OpString> const &dialogKeys, Side posDir = Side::TO_UP, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);

                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &player, View::Overworld &overworld);
                virtual void changeDialog(std::vector<Utils::OpString> newDialog) { TalkingEvent::changeDialog(newDialog); }
            };

            class TrainerEvent : public TalkingCharaEvent {
              private:
                OpTeam *team;
                bool defeated = false;
                bool triggerBattle = false;
                bool checkTalking = false;
                std::vector<Utils::OpString> defeatedDialog;

              public:
                TrainerEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, std::vector<Utils::OpString> const &dialogKeys, std::vector<Utils::OpString> const &defeatedDialog, Side posDir = Side::TO_UP, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);

                virtual void update(Model::Player &player, View::Overworld &overworld);
                virtual void action(Model::Player &player, View::Overworld &overworld);

                OpTeam *getOpTeam() {
                    return team;
                }

                void defeat();

                bool isDefeated() {
                    return defeated;
                }

                virtual ~TrainerEvent();
            };

            class TrainerEyesightEvent : public Event {
              public:
                TrainerEvent *trainer;
                bool checkTalking = false;
                bool triggerBattle = false;

              public:
                TrainerEyesightEvent(TrainerEvent *trainer, sf::Vector2f position);
#pragma GCC diagnostic ignored "-Wunused-parameter"
                virtual void update(Model::Player &player, View::Overworld &overworld){};
                virtual void action(Model::Player &player, View::Overworld &overworld){};
#pragma GCC diagnostic pop
            };

        } // namespace Events

    } // namespace Model
} // namespace OpMon
#endif // EVENTS_HPP
