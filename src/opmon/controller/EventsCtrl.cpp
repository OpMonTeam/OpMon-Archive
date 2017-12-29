#include "EventsCtrl.hpp"

namespace OpMon{
  namespace Controller{
    void EventsCtrl::checkAction(sf::Event const& event, Player& player){
      if(!player.getPosition().isAnim()) {
	if(isKeyPressed(sf::Keyboard::Return)) {
	  int lx = player.getPosition().getPosition().x;
	  int ly = player.getPosition().getPosition().y;
	  switch(ppDir) {
	  case Side::TO_UP:
	    ly--;
	    break;
	  case Side::TO_DOWN:
	    ly++;
	    break;
	  case Side::TO_LEFT:
	    lx--;
	    break;
	  case Side::TO_RIGHT:
	    lx++;
	    break;
	  default:
	    break;
	  }
	  actionEvent(Model::Data::World::map.at(player.getMapID()).getEvent(sf::Vector2i(lx SQUARES, ly SQUARES)), player, Events::EventTrigger::PRESS);
	  
	  
	}
      }


      
      if(!player.getPosition().isMoving()) {
	actionEvent(Model::Data::World::map.at(player.getMapID()).getEvent(sf::Vector2i(ppPosX SQUARES, ppPosY SQUARES)), player, Events::EventTrigger::BE_IN);
      }

      
      
    }

    void EventsCtrl::actionEvent(std::vector<Event*>& events, Player& player, EventTrigger toTrigger){
      Side ppDir = player.getPosition().getDir();
      for(unsigned int i = 0; i < events.size(); i++) {
	if(events[i]->getEventTrigger() == toTrigger) {
	  bool go = false;
	  if(((events[i]->getSide() & SIDE_UP) == SIDE_UP) && ppDir == Side::_UP) {
	    go = true;
	  } else if(((events[i]->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == Side::TO_DOWN) {
	    go = true;
	  } else if(((events[i]->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == Side::TO_RIGHT) {
	    go = true;
	  } else if(((events[i]->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == Side::TO_LEFT) {
	    go = true;
	  }
	  if(go) {
	    events[i]->action(player);
	  }
	}
      }
    }

    void EventsCtrl::updateEvent(std::vector<Event*>& events, Player& player){
      for(Event* event : events) {
        event->update(player);
      }
    }
  }
}
