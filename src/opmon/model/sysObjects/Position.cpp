#include "Position.hpp"
#include "../../start/Core.hpp"
#include "Events.hpp"
#include "Map.hpp"
#include "../storage/Data.hpp"


namespace OpMon {
  namespace Model {
    Position::Position(bool event)
      : posX(0), posY(0), dir(Side::TO_UP), anim(false), movement(false), event(event) {}

    Position::Position(sf::Vector2i position, bool event, Side dir)
      : posX(position.x), posY(position.y), dir(dir), anim(false), movement(false), event(event) {}

    Position::Position(sf::Vector2f position, bool event, Side dir)
      : posX(position.x), posY(position.y), dir(dir), anim(false), movement(false), event(event) {}

    void Position::tp(sf::Vector2i position) {
      movement = false;
      anim = false;

      posX = position.x - 1;
      posY = position.y;
    }

    void Position::setPosition(int x, int y){
      posX = x;
      posY = y;
    }
     
#define UNLOCK_TP  Events::justTP = false;

    void Position::move(Side dir) {
      if (!anim && !moveLock) {
	this->dir = dir;
	//To do in overworld
	//startFrames = frames;
	anim = true;

	if ((!event && debugMode) || checkPass(dir)) {
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
	  case Side::NO_MOVE:
	    this->dir = Side::STAY;
	    break;
	  case Side::STAY:
	    break;
	  }
	  return;
	}
      }

    }

    bool Position::checkPass(Side direction) {
      auto &player = Data::player;
      bool colPass = false;
      std::vector<Event *> nextEvents;
      Map *map = Data::World::maps.at(player.getMapId());
      auto passArr = map->getPassArr();

      switch (direction) {
      case Side::TO_UP:
	if (posY - 1 >= 0) {
	  if (passArr[(posY - 1)][posX] == 0) {
	    if(event ? !(posY - 1 == player.getPosition().getPosition().y && posX == player.getPosition().getPosition().x) : true){
	      nextEvents = map->getEvent(sf::Vector2i(posX SQUARES, (posY - 1) SQUARES));
	      colPass = true;
	    }
	  }
	}
      case Side::TO_DOWN:
	if (posY + 1 < map->getH()) {
	  if (passArr[(posY + 1)][posX] == 0) {
	    if(event ? !(posY + 1 == player.getPosition().getPosition().y && posX == player.getPosition().getPosition().x) : true){
	      nextEvents = map->getEvent(sf::Vector2i(posX SQUARES, (posY + 1) SQUARES));
	      colPass = true;
	    }
	  }
	}
      case Side::TO_LEFT:
	if (posX - 1 >= 0) {
	  if (passArr[posY][(posX - 1)] == 0) {
	    if(event ? !(posY == player.getPosition().getPosition().y && posX - 1 == player.getPosition().getPosition().x) : true){
	      nextEvents = map->getEvent(sf::Vector2i((posX - 1) SQUARES, posY SQUARES));
	      colPass = true;
	    }
	  }
	}
      case Side::TO_RIGHT:
	if (posX + 1 < map->getW()) {
	  if (passArr[posY][(posX + 1)] == 0 || passArr[posY][(posX + 1)] == 5) {
	    if(event ? !(posY == player.getPosition().getPosition().y && posX - 1 == player.getPosition().getPosition().x) : true){
	      nextEvents = map->getEvent(sf::Vector2i((posX + 1) SQUARES, posY SQUARES));
	      colPass = true;
	    }
	  }
	}
        default:
          break;
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
