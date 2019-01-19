/*
Position.cpp
Author : Cyrion
Contributors : BAKFR, Stelyus
File under GNU GPL v3.0 license
*/
#include "Position.hpp"
#include "../../start/Core.hpp"
#include "Events.hpp"
#include "Map.hpp"

namespace OpMon {
    namespace Model {
        Position::Position(bool event)
          : posX(0)
          , posY(0)
          , dir(Side::TO_UP)
          , anim(false)
          , movement(false)
          , event(event) {}

        Position::Position(sf::Vector2i position, bool event, Side dir)
          : posX(position.x)
          , posY(position.y)
          , dir(dir)
          , anim(false)
          , movement(false)
          , event(event) {}

        Position::Position(sf::Vector2f position, bool event, Side dir)
          : posX(position.x)
          , posY(position.y)
          , dir(dir)
          , anim(false)
          , movement(false)
          , event(event) {}

        void Position::tp(sf::Vector2i position) {
            movement = false;
            anim = false;

            posX = position.x - 1;
            posY = position.y;
        }

        void Position::setPosition(int x, int y) {
            posX = x;
            posY = y;
        }

        //Just lasiness TODO : Remove this when Events::justTP will be removed.
#define UNLOCK_TP Events::justTP = false;

        bool Position::move(Side dir, Map *map) {
            if(!anim && !moveLock) {
                this->dir = dir;

                anim = true;

                if((!event && debugCol) /*Noclip mode in the debug*/ || checkPass(dir, map)) {
                    UNLOCK_TP
                    movement = true;
                    switch(dir) {
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
                    case Side::NO_MOVE:
                        this->dir = Side::STAY;
                        break;
                    case Side::STAY:
                        break;
                    }
                    return true;
                }
            }

            return false;
        }

        Position *Position::playerPos = nullptr;

        void Position::setPlayerPos(Position *pos) {
            if(playerPos == nullptr) {
                playerPos = pos;
            }
        }

        bool Position::checkPass(Side direction, Map *map) {

            std::vector<Event *> nextEvents;
            sf::Vector2i nextPos;
            sf::Vector2i nextPosPix;
            int exclusiveCol = 0;

            //Finds the next tile's position
            switch(direction) {
            case Side::TO_UP:
                nextPos = sf::Vector2i(posX, posY - 1);
                exclusiveCol = 8;
                break;
            case Side::TO_DOWN:
                nextPos = sf::Vector2i(posX, posY + 1);
                exclusiveCol = 7;
                break;
            case Side::TO_LEFT:
                nextPos = sf::Vector2i(posX - 1, posY);
                exclusiveCol = 6;
                break;
            case Side::TO_RIGHT:
                nextPos = sf::Vector2i(posX + 1, posY);
                exclusiveCol = 5;
                break;
            default:
                return true;
                break;
            }

            nextPosPix = nextPos SQUARES;

            if(nextPos.x >= 0 && nextPos.x < map->getW() && nextPos.y >= 0 && nextPos.y < map->getH()) { //Avoid checking in the void (Out of the map's bounds)
                int colLayer1 = map->getTileCollision(map->getCurrentTileCode(nextPos, 1));
                int colLayer2 = map->getTileCollision(map->getCurrentTileCode(nextPos, 2));
                if((colLayer1 == 0 || colLayer1 == exclusiveCol) && (colLayer2 == 0 || colLayer2 == exclusiveCol)) {           //Checks if the next tile is passable
                    if(event ? !(nextPos.y == playerPos->getPosition().y && nextPos.x == playerPos->getPosition().x) : true) { //Checks if the player is not in the way, but only if it's an event (A player can not interact with itself.)
                        nextEvents = map->getEvent(nextPos);                                                                   //Searches the events at this position
                        for(Event *nextEvent : nextEvents) {
                            if(!nextEvent->isPassable()) { //Checks if the event ahead of the player is passable
                                return false;
                            }
                        }
                        return true;
                    }
                }
            }

            return false;
        }

    } // namespace Model
} // namespace OpMon
