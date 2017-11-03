#include "OverworldCtrl.hpp"

namespace OpMon{
  namespace Controller{
    GameStatus OverworldCtrl(sf::Event& events){
      switch(events){
	
      }
    }

    void move(Side direction){
      Model::Data::player.getPosition().move(direction);
      std::vector<Event *> nextEvents = Model::Data::World::maps.at(Model::Data::player.getPosition().getMapId()).getEvent(Model::Data::player.getPosition().getPositionPxel());
      if(nextEvents.size() > 0) {
	for(Event *nextEvent : nextEvents) {
	  if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN) {
	    nextEvent->action(Model::Data::player);
	  }
	}
      }
    }
  }
}
