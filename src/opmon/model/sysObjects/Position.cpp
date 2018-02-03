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

	if ((!event && debugCol) || checkPass(dir)) {
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
      std::vector<Event *> nextEvents;
      Map *map = Data::World::maps.at(player.getMapId());

      sf::Vector2i nextPos;
      sf::Vector2i nextPosPix;
      int exclusiveCol = 0;
      
      switch (direction) {
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
	break;
      }
      
      nextPosPix = nextPos SQUARES;
      
      if(nextPos.x >= 0 && nextPos.x < map->getW() && nextPos.y >= 0 && nextPos.y < map->getH()){
	int colLayer1 = map->getTileCollision(map->getCurrentTileCode(nextPos, 1));
	int colLayer2 = map->getTileCollision(map->getCurrentTileCode(nextPos, 2));
	if((colLayer1 == 0 || colLayer1 == exclusiveCol) && (colLayer2 == 0 || colLayer2 == exclusiveCol)){
	  if(event ? !(nextPos.y == player.getPosition().getPosition().y && nextPos.x == player.getPosition().getPosition().x) : true){
	      nextEvents = map->getEvent(nextPos);
	      for (Event *nextEvent : nextEvents) {
		if (!nextEvent->isPassable()) {
		  return false;
		}
	      }
	      return true;
	    }
	  }
      }

      return false;
      
    }

  }
}
