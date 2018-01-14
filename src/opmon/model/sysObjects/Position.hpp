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
#define SQUARES * SQUARES_SIZE

namespace OpMon {
  namespace Model {
    class Position {
    public:
      Position();

      Position(std::string mapId, sf::Vector2i position, Side dir = Side::TO_UP);

      sf::Vector2i getPosition() {
        return sf::Vector2i(posX, posY);
      }

      sf::Vector2i getPositionPixel() {
        return sf::Vector2i(posX SQUARES, posY SQUARES);
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

      void tp(sf::Vector2i position);

      void move(Side dir);

    private:

      bool checkPass(Side dir);

      int posX;
      int posY;
      Side dir;
      bool anim;
      bool movement;
      bool moveLock;
      bool event;
    };
  }
}

#endif
