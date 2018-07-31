/*
  Position.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga
  Contains the Position class
*/

#ifndef POSITION_HPP
#define POSITION_HPP

#include <SFML/System/Vector2.hpp>
#include <string>

#include "../objects/Enums.hpp"

#define SQUARES_SIZE 32
#define SQUARES *SQUARES_SIZE

namespace OpMon {
    namespace Model {

        class Map;

        class Position {
          public:
            Position(bool event = false);

            Position(sf::Vector2i position, bool event = false, Side dir = Side::TO_UP);
            Position(sf::Vector2f position, bool event = false, Side dir = Side::TO_UP);

            sf::Vector2i getPosition() {
                return sf::Vector2i(posX, posY);
            }

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

            void stopMove() {
                anim = false;
                movement = false;
            }

            void stopAnim() {
                anim = false;
            }

            void lockMove() {
                moveLock = true;
            }

            void unlockMove() {
                moveLock = false;
            }

            bool isLocked() { return moveLock; }

            void setPosition(int x, int y);

            void tp(sf::Vector2i position);

            bool move(Side dir, Map *map);

            static void setPlayerPos(Position *pos);

          private:
            bool checkPass(Side dir, Map *map);

            static Position *playerPos;

            int posX = 0;
            int posY = 0;
            Side dir;
            bool anim = false;
            bool movement = false;
            bool moveLock = false;
            bool event = false;
        };
    } // namespace Model
} // namespace OpMon

#endif
