/*!
 * \file Position.hpp
 * \authors Cyrielle
 * \authors Stelyus
 * \authors Navet56
 * \authors BAKFR
 * \copyright GNU GPL v3.0
*/

#ifndef POSITION_HPP
#define POSITION_HPP

#include <SFML/System/Vector2.hpp>
#include <string>

#include "../../objects/Enums.hpp"

/*!
 * \brief The size of one tile, in pixels.
 */
#define SQUARES_SIZE 32
/*!
 * \brief Shortcut to make the code more readable.
 */
#define SQUARES *SQUARES_SIZE

namespace OpMon {
    namespace Elements {

        class Map;

        /*!
         * \brief Class managing the position of an entity (player or event) and it's movement.
         */
        class Position {
          public:
            /*!
             * \brief Constructs a Position object with default position data.
             * \param event If `true`, the position is for an event. Else, it's for the player.
             */
            Position(bool event = false);

            /*!
             * \brief Constructs a Position object with predefined position data.
             * \param position The default position.
             * \param event If `true`, the position is for an event. Else, it's for the player.
             * \param dir The direction the entity is facing.
             */
            Position(sf::Vector2i position, bool event = false, Side dir = Side::TO_UP);
            /*!
             * \copydoc Position(sf::Vector2i position, bool event = false, Side dir = Side::TO_UP)
             */
            Position(sf::Vector2f position, bool event = false, Side dir = Side::TO_UP);

            /*!
             * \brief Returns the position in map coordinates.
             */
            sf::Vector2i getPosition() {
                return sf::Vector2i(posX, posY);
            }
            /*!
             * \brief Returns the position in pixels.
             */
            sf::Vector2i getPositionPixel() {
                return sf::Vector2i(posX SQUARES, posY SQUARES);
            }

            void setDir(Side dir) {
                this->dir = dir;
            }

            Side getDir() {
                return dir;
            }

            bool isAnim() {
                return anim;
            }

            bool isMoving() {
                return movement;
            }

            /*!
             * \brief Stops the current movement.
             */
            void stopMove() {
                anim = false;
                movement = false;
            }

            /*!
             * \brief Stops the current animation.
             */
            void stopAnim() {
                anim = false;
            }

            /*!
             * \brief Prevents the entity from moving.
             */
            void lockMove() {
                moveLock = true;
            }

            /*!
             * \brief Makes the entity able to move again.
             */
            void unlockMove() {
                moveLock = false;
            }

            bool isLocked() { return moveLock; }

            void setPosition(int x, int y);

            /*!
             * \brief Teleports the entity in a new position.
             */
            void tp(sf::Vector2i position);

            /*!
             * \brief Moves the entity.
             * \details This method checks for the current collisions, checks if the entity can move, and then activates the animation and the movement.
             * \return `false` if the entity can't move, `true` if the movement has been initiated.
             */
            bool move(Side dir, Map *map);

            /*!
             * \brief Sets the position of Position::playerPos
             */
            static void setPlayerPos(Position *pos);

          private:
            /*!
             * \brief Checks if the entity can go through an adjacent tile.
             * \return `true` if the entity can, `false` otherwise.
             */
            bool checkPass(Side dir, Map *map);

            /*!
             * \brief A pointer to the player's position.
             */
            static Position *playerPos;

            int posX = 0;
            int posY = 0;
            /*!
             * \brief Where the entity is facing.
             */
            Side dir;
            /*!
             * \brief If the movement animation has been launched (the animation only, not the movement).
             */
            bool anim = false;
            /*!
             * \brief If the movement has been lauched.
             */
            bool movement = false;
            /*!
             * \brief If the entity's movements are locked.
             */
            bool moveLock = false;
            /*!
             * \brief If the entity is an event.
             */
            bool event = false;
        };
    } // namespace Elements
} // namespace OpMon

#endif
