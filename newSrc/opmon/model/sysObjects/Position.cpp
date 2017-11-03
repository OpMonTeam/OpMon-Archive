#include "Position.hpp"

namespace OpMon{
  namespace Model{
    Position::Position()
      : mapId("Player's room"), posX(0), posY(0), dir(Side::TO_UP), anim(false), movement(false){}
    Position::Position(std::string mapId, sf::Vector2i position, Side dir = Side::TO_UP)
      : mapId(mapId), posX(position.x), posY(position.y), dir(dir), anim(false), movement(false){}

    void Position::tp(std::string mapToTp, sf::Vector2i position){
      if(!movement || !anim) {
        moving = false;
        anim = false;
      }
      mapId = toTp;

      posX = position.x - 1;
      posY = position.y;
      //To do in view
      /*
	*/
      Events::justTp = true;
    }

    #define UNLOCK_TP  Events::justTP = false;
    
    void Position::move(Side dir){
      if(!anim && !moveLock){
	this->dir = dir;
	//To do in overworld
	//startFrames = frames;
	anim = true;

	if(debugMode){
	  UNLOCK_TP
	    moving = true;
	  switch(direction){
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
	if(checkPass(direction)){
	  UNLOCK_TP
	    moving = true;
	  switch(dir){
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
	  //To do in overworld
	  /*std::vector<Event *> nextEvents = actual->getEvent(sf::Vector2i(ppPosX CASES, ppPosY CASES));
	  if(nextEvents.size() > 0) {
	    for(Event *nextEvent : nextEvents) {
	      if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN && ((nextEvent->getSide() & SIDE_UP) == SIDE_UP)) {
		nextEvent->action(Main::player);
	      }
	    }
	    }*/
	}
    
      }
    }

    bool Position::checkPass(Side dir){
      switch(direction){
      case Side::TO_UP:
	if(posY - 1 >= 0) {
	  if(Data::World::maps.at(mapId).getPassArr()[(posY - 1)][posX] == 0) {
	    std::vector<Event *> nextEvents = Data::World::maps.at(mapId).getEvent(sf::Vector2i(posX SQUARES, (posY - 1) SQUARES));
	    for(Event *nextEvent : nextEvents) {
	      if(!nextEvent->isPassable()) {
		return false;
	      }
	    }	
	    return true;
	  }
	}
	return false;
      case Side::TO_DOWN:
	if(posY + 1 < Data::World::maps.at(mapId).getH()) {
	  if(Data::World::maps.at(mapId).getPassArr()[(posY + 1)][posX] == 0) {
	    std::vector<Event *> nextEvents = Data::World::maps.at(mapId).getEvent(sf::Vector2i(posX SQUARES, (posY + 1) SQUARES));
	    for(Event *nextEvent : nextEvents) {
	      if(!nextEvent->isPassable()) {
		return false;
	      }
	  
	    }
	    return true;
	  }
	}
	return false;
      case Side::TO_LEFT:
	if(posX - 1 >= 0) {
	  if(Data::World::maps.at(mapId).getPassArr()[ posY][ (posX - 1)] == 0) {
	    std::vector<Event *> nextEvents = Data::World::maps.at(mapId).getEvent(sf::Vector2i((posX - 1) SQUARES, posY SQUARES));
	    for(Event *nextEvent : nextEvents) {
	      if(!nextEvent->isPassable()) {
		return false;
	      }

	    }
	    return true;
	  }
	}
	return false;
      case Side::TO_RIGHT:
	if(posX + 1 < Data::World::maps.at(mapId).getW()) {
	  if(Data::World::maps.at(mapId).getPassArr()[posY][(posX + 1)] == 0 || Data::World::maps.at(mapId).getPassArr()[posY][(posX + 1)] == 5) {
	    std::vector<Event *> nextEvents = Data::World::maps.at(mapId).getEvent(sf::Vector2i((posX + 1) SQUARES, posY SQUARES));
	    for(Event *nextEvent : nextEvents) {
	      if(!nextEvent->isPassable()) {
		return false;
	      }
	    }	
	    return true;
	  }
	}
	return false;
      }
      return false;
    }
  }
}
