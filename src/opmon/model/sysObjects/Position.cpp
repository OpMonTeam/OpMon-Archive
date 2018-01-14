
#include "Position.hpp"
#include "../../start/Core.hpp"
#include "Events.hpp"
#include "Map.hpp"
#include "../storage/Data.hpp"


namespace OpMon {
    namespace Model {
      Position::Position(bool event = false)
	  : mapId("Player's room"), posX(0), posY(0), dir(Side::TO_UP), anim(false), movement(false), event(event) {}

      Position::Position(std::string mapId, sf::Vector2i position, Side dir = Side::TO_UP, bool event = false)
	  : mapId(mapId), posX(position.x), posY(position.y), dir(dir), anim(false), movement(false), event(event) {}

        void Position::tp(sf::Vector2i position) {
          if (!movement || !anim) {
            moving = false;
            anim = false;
          }

          posX = position.x - 1;
          posY = position.y;
          //To do in view
          /*
           */
          Events::justTp = true;
        }

#define UNLOCK_TP  Events::justTP = false;

        void Position::move(Side dir) {
          if (!anim && !moveLock) {
            this->dir = dir;
            //To do in overworld
            //startFrames = frames;
            anim = true;

            if (debugMode || checkPass(dir)) {
              UNLOCK_TP
              movement = true;
              switch (dir) {
                case Side::TO_UP:
                  posY--;
                  break;
                case Side::TO_DOWN:
                  posY++;
                  break;
                case Side::TO_LEFT:
                  posX--;
                  break;
                case Side::TO_RIGHT:
                  posX++;
                  break;
              }
              return;
            }
          }

        }

        bool Position::checkPass(Side direction) {
          bool colPass = false;
          std::vector<Event *> nextEvents;
          Map &map = Data::World::maps.at(mapId);
          auto passArr = map.getPassArr();

          switch (direction) {
            case Side::TO_UP:
              if (posY - 1 >= 0) {
                if (passArr[(posY - 1)][posX] == 0) {
                  nextEvents = map.getEvent(sf::Vector2i(posX SQUARES, (posY - 1) SQUARES));
                  colPass = true;
                }
              }
            case Side::TO_DOWN:
              if (posY + 1 < Data::World::maps.at(mapId).getH()) {
                if (passArr[(posY + 1)][posX] == 0) {
                  nextEvents = map.getEvent(sf::Vector2i(posX SQUARES, (posY + 1) SQUARES));
                  colPass = true;
                }
              }
            case Side::TO_LEFT:
              if (posX - 1 >= 0) {
                if (passArr[posY][(posX - 1)] == 0) {
                  nextEvents = map.getEvent(sf::Vector2i((posX - 1) SQUARES, posY SQUARES));
                  colPass = true;
                }
              }
            case Side::TO_RIGHT:
              if (posX + 1 < Data::World::maps.at(mapId).getW()) {
                if (passArr[posY][(posX + 1)] == 0 || passArr[posY][(posX + 1)] == 5) {
                  nextEvents = map.getEvent(sf::Vector2i((posX + 1) SQUARES, posY SQUARES));
                  colPass = true;
                }
              }
          }
          if (colPass) {
            for (Event *nextEvent : nextEvents) {
              if (!nextEvent->isPassable()) {
                return false;
              }
            }
            return true;
          } else {
            return false;
          }
        }
    }
}
