/*!
  \file Events.hpp
  \authors Cyrielle
  \authors BAKFR
  \authors Navet56
  \copyright GNU GPL v3.0
*/
#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "src/utils/i18n/ATranslatable.hpp"
#include "../../core/Player.hpp"

namespace OpMon {
class Item;
class OpTeam;
class Player;
namespace Elements {
class Map;
}  // namespace Elements
}  // namespace OpMon

//Macros defining constants to know the side from where the events can be triggered.
#define SIDE_UP 0x0001
#define SIDE_DOWN 0x0002
#define SIDE_LEFT 0x0010
#define SIDE_RIGHT 0x0020
#define SIDE_ALL (SIDE_UP | SIDE_DOWN | SIDE_RIGHT | SIDE_LEFT)

#pragma GCC diagnostic ignored "-Wreorder"

namespace OpMon {

    class Overworld;

    namespace Elements {

        namespace Events {
            /*!
             * \brief Used to know when the event must be triggered, relatively from the player.
             */
            enum class EventTrigger {
                PRESS = 0,/*!< The event is triggered when the player presses the action key.*/
                GO_IN = 1,/*!< The event is triggered when the player is moving to the tile.*/
                ZONE = 2,/*!< The event is triggered as soon as the player sees it.*/
                BE_IN = 3/*!< The event is triggered as long as the player is on its position.*/
            };
        } // namespace Events

        /*!
          \brief Defines an event
        */
        class Event {
          private:
            /*!
             * \brief How the event is triggered by the player.
             */
            Events::EventTrigger eventTrigger;
            /*!
             * \brief If the player can go through the even or not.
             */
            bool passable = false;
            /*!
             * \brief From which sides the player is able to interact with the event.
             */
            int sides = SIDE_ALL;

        protected:

            /*!
             * \brief The position of the event on the screen.
             */
            sf::Vector2f position;

            /*!
             * \brief The sprite of the event.
             */
            std::unique_ptr<sf::Sprite> sprite;
            /*!
             * \brief The position of the even of the map.
             */
            Position mapPos;
            /*!
             * \brief An iterator to the current texture in Event::otherTextures.
             */
            std::vector<sf::Texture>::iterator currentTexture;

            /*!
             * \brief Other textures used by the event.
             */
            std::vector<sf::Texture> &otherTextures;

          public:
            Event(std::vector<sf::Texture> &otherTextures, Events::EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable);
            virtual ~Event() = default;
            /*!
             * \brief Method called at each frame.
             */
            virtual void update(Player &player, Overworld &overworld) = 0;
            /**
             * \brief Method called when the player interacts with the event.
             */
            virtual void action(Player &player, Overworld &overworld) = 0;
            /*!
             * \brief Updates Event::sprite with Event::currentTexture and Event::position.
             */
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
        /*!
         * \brief Contains stuff in relation with the events, mostly different types of events.
         */
        namespace Events {
            /*!
             *  \brief Doors sound.
             *  \todo Move this elsewhere.
             */
            extern sf::Sound doorSound;
            /*!
             * \copydoc doorSound
             */
            extern sf::Sound shopdoorSound;

            /*!
             * \brief Defines an event that teleports the player.
             */
            class TPEvent : public virtual Event {

              private:
                int frames = -1;
                /*!
                 * \brief The coordinates of where the event will teleport the player.
                 */
                sf::Vector2i tpCoord;
                /*!
                 * \brief The id of he map where the event will teleport the player.
                 */
                std::string map;
                /*!
                 * \brief The direction in which the character will be looking after the teleportation.
                 */
                Side ppDir;

              public:
                TPEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
                virtual void update(Player &player, Overworld &overworld);
                virtual void action(Player &player, Overworld &overworld);
            };

            /*!
             * \brief An TPEvent doing an animation when the player enters it.
             */
            class DoorEvent : public TPEvent {
              private:
                /*!
                 * \brief The kind of door.
                 * \details There are two types of doors for now : "shop door" and "door"
                 */
                std::string doorType;
                /*!
                 * \brief Counter used in the animation of the door.
                 * \details If set to 0, the animation will start until it reaches beyond 10. In this case, the animation will be over and the counter will be back to -1.
                 */
                int animStarted = -1;

              public:
                DoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, EventTrigger eventTrigger = EventTrigger::GO_IN, Side ppDir = Side::NO_MOVE, int sides = SIDE_ALL, bool passable = true);
                virtual void action(Player &player, Overworld &overworld);
                virtual void update(Player &player, Overworld &overworld);
            };

            /*!
             * \brief An event starting a dialog.
             */
            class TalkingEvent : public virtual Event, public Utils::I18n::ATranslatable {
              private:
                /*!
                 * \brief The OpString containing the dialog to show.
                 */
                Utils::OpString dialogKey;

            protected:
                /*!
                 * \brief The dialog to show.
                 */
                sf::String dialog;

              public:
                TalkingEvent(std::vector<sf::Texture> &otherTextures, sf::Vector2f const &position, Utils::OpString const &dialogKey, int sides = SIDE_ALL, EventTrigger eventTrigger = EventTrigger::PRESS, bool passable = false);
                void onLangChanged() override;
                virtual void update(Player &player, Overworld &overworld);
                virtual void action(Player &player, Overworld &overworld);
                /*!
                 * \brief Changes the dialog shown by the event.
                 * \param newDialog An OpString containing the new dialog.
                 */
                virtual void changeDialog(Utils::OpString newDialog);
            };

            /*!
             * \brief A locked door (unimplemented yet).
             */
            class LockedDoorEvent : public DoorEvent, public TalkingEvent {
              private:
                /*!
                 * \brief The item needed to unlock the door.
                 */
                Item *needed;
                /*!
                 * \brief If `true`, the item has to be consumed after opening the door.
                 */
                bool consumeItem;
                /*!
                 * \brief The default dialog of the locked door.
                 */
                static Utils::OpString keysLock;

              public:
                virtual void action(Player &player, Overworld &overworld);
                virtual void update(Player &player, Overworld &overworld);
                LockedDoorEvent(std::vector<sf::Texture> &doorTextures, std::string doorType, Item *needed, sf::Vector2f const &position, sf::Vector2i const &tpCoord, std::string const &map, Side ppDir = Side::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, bool consumeItem = false, int sides = SIDE_ALL, bool passable = false);
            };

            /*!
             * \brief Defines different ways of moving of the npcs.
             */
            enum class MoveStyle : int {
                NO_MOVE = 0,/*!< The npc has to stay still.*/
                PREDEFINED = 1,/*!< The npc follows a predefined path.*/
                RANDOM = 2,/*!< The npc moves randomly.*/
                FOLLOWING = 3/*!< The npc follows the player (unimplemented yet).*/
            };

            /*!
             * \brief Defines a npc.
             */
            class CharacterEvent : public virtual Event {
              private:
                /*!
                 * \brief The way the npc moves.
                 */
                MoveStyle moveStyle;

                /*!
                 * \brief A counter used for the predefined movements.
                 */
                unsigned int predefinedCounter = 0;
                /*!
                 * \brief A counter for the movement animation.
                 */
                int animsCounter = 0;

                /*!
                 * \brief The predefined movements.
                 */
                std::vector<Side> movements;

                /*!
                 * \brief The frame number when the movement animation started.
                 */
                int startFrames = 0;
                /*!
                 * \brief If the npc is currently animated.
                 */
                bool anims = false;
                /*!
                 * \brief Counts the frames.
                 */
                int frames = 0;

              public:
                CharacterEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Side posDir = Side::TO_UP, MoveStyle moveStyle = MoveStyle::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int sides = SIDE_ALL);
                virtual void update(Player &player, Overworld &overworld);
                virtual void action(Player &, Overworld &){};
                /*!
                 * \brief Sets the predefined movement.
                 */
                void setPredefinedMove(std::vector<Side> movement);
                /*!
                 * \brief Moves the npc
                 * \deprecated Use directly move(Side direction, Map *map). This method searches in overworld for the map, which is completely useless.
                 */
                OP_DEPRECATED void move(Side direction, Player &player, Overworld &overworld);
                /*!
                 * \brief Moves the npc
                 */
                bool move(Side direction, Map *map);
            };

            /*!
             * \brief An npc that talks.
             */
            class TalkingCharaEvent : public CharacterEvent, public TalkingEvent {
              protected:
                /*!
                 * \brief If the npc is talking right now.
                 */
                bool talking = false;

              public:
                TalkingCharaEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Utils::OpString const &dialogKey, Side posDir = Side::TO_UP, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);

                virtual void update(Player &player, Overworld &overworld);
                virtual void action(Player &player, Overworld &overworld);
            };

            /*!
             * \brief A trainer.
             */
            class TrainerEvent : public TalkingCharaEvent {
              private:
                /*!
                 * \brief The trainer's team.
                 */
                OpTeam *team;
                /*!
                 * \brief Is the trainer has already been defeated.
                 */
                bool defeated = false;
                /*!
                 * \brief If the trainer has to be triggered.
                 */
                bool triggerBattle = false;
                /*!
                 * \brief If `true`, the npc is talking.
                 */
                bool checkTalking = false;
                /*!
                 * \brief The dialog the trainer says when he's defeated.
                 */
                Utils::OpString defeatedDialog;

              public:
                TrainerEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, Utils::OpString const &dialogKeys, Utils::OpString const &defeatedDialog, Side posDir = Side::TO_UP, EventTrigger eventTrigger = EventTrigger::PRESS, MoveStyle moveStyle = MoveStyle::NO_MOVE, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int side = SIDE_ALL);

                virtual void update(Player &player, Overworld &overworld);
                virtual void action(Player &player, Overworld &overworld);

                OpTeam *getOpTeam() {
                    return team;
                }

                /*!
                 * \brief Makes the trainer defeated.
                 */
                void defeat();

                bool isDefeated() {
                    return defeated;
                }

                virtual ~TrainerEvent();
            };

            /*!
             * \brief Work in progress class.
             */
            class TrainerEyesightEvent : public Event {
              private:
                TrainerEvent *trainer;
                bool checkTalking = false;
                bool triggerBattle = false;

              public:
                TrainerEyesightEvent(TrainerEvent *trainer, sf::Vector2f position);
#pragma GCC diagnostic ignored "-Wunused-parameter"
                virtual void update(Player &player, Overworld &overworld){};
                virtual void action(Player &player, Overworld &overworld){};
#pragma GCC diagnostic pop
            };

        } // namespace Events

    } // namespace Elements
} // namespace OpMon
#endif // EVENTS_HPP
