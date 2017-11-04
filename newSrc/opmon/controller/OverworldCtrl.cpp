#include "OverworldCtrl.hpp"

namespace OpMon{
  namespace Controller{
    void OverworldCtrl::checkEvents(sf::Event& events, View::Overworld& overworld, bool dialog){
	
      switch(Main::mainframe.events.type) {
      case sf::Event::KeyPressed:
	if(Main::mainframe.events.key.code == sf::Keyboard::Equal) {
	  debugMode = !debugMode;
	}
	if(debugMode) {
	  if(Main::mainframe.events.key.code == sf::Keyboard::F10) {
	    overworld.printlayer[0] = !overworld.printlayer[0];
	  }
	  if(Main::mainframe.events.key.code == sf::Keyboard::F11) {
	    overworld.printlayer[1] = !overworld.printlayer[1];
	  }
	  if(Main::mainframe.events.key.code == sf::Keyboard::F12) {
	    overworld.printlayer[2] = !overworld.printlayer[2];
	  }

	  if(Main::mainframe.events.key.code == sf::Keyboard::F5) {
	    tp("Mom's room", sf::Vector2i(0, 1), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F6) {
	    tp("Player's room", sf::Vector2i(0, 0), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F1) {
	    tp("Fauxbourg Euvi", sf::Vector2i(25, 28), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F2) {
	    tp("Player's home", sf::Vector2i(8, 14), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F3) {
	    tp("Laboratory", sf::Vector2i(15, 14), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F4) {
	    tp("Rival's house", sf::Vector2i(8, 14), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F7){
	    tp("Route 14", sf::Vector2i(0, 31), true);
	  } else if(Main::mainframe.events.key.code == sf::Keyboard::F8){
	    tp("MysteriouCity", sf::Vector2i(12, 0), true);
	  }
	}
      default:
	break;
      }

      if(!overworld.justTp) {
	if(isKeyPressed(sf::Keyboard::Up)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_UP);
	} else if(isKeyPressed(sf::Keyboard::Down)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_DOWN);
	} else if(isKeyPressed(sf::Keyboard::Left)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_LEFT);
	} else if(isKeyPressed(sf::Keyboard::Right)) {
	  gameloop.getPlayer().getPosition().move(Side::TO_RIGHT);
	}
      }
	  
      if(debugMode) {
	if(isKeyPressed(sf::Keyboard::Numpad2)) {
	  overworld.moveCamera(Side::TO_DOWN);
	}
	if(isKeyPressed(sf::Keyboard::Numpad4)) {
	  overworld.moveCamera(Side::TO_LEFT);
	}
	if(isKeyPressed(sf::Keyboard::Numpad8)) {
	  overworld.moveCamera(Side::TO_UP);
	}
	if(isKeyPressed(sf::Keyboard::Numpad6)) {
	  overworld.moveCamera(Side::TO_DOWN);
	}
      }

      if(dialog){
	checkEventsDialog(events, overworld);
      }else{
	checkEventsNoDialog(events, overworld);
      }
      
            
    }
    
    void OverworldCtrl::move(Side direction){
      gameloop.getPlayer().getPosition().move(direction);
      std::vector<Event *> nextEvents = Model::Data::World::maps.at(gameloop.getPlayer().getPosition().getMapId()).getEvent(gameloop.getPlayer().getPosition().getPositionPixel());
      if(nextEvents.size() > 0) {
	for(Event *nextEvent : nextEvents) {
	  if(nextEvent->getEventTrigger() == Events::EventTrigger::GO_IN) {
	    nextEvent->action(gameloop.getPlayer());
	  }
	}
      }
    }

    void Overworld::checkEventsDialog(sf::Event& events, View::Overworld& overworld){
      switch(Main::mainframe.events.type) {	  
      case sf::Event::KeyPressed:
	if(Main::mainframe.events.key.code == sf::Keyboard::Space) {
	  overworld.getDialog()->pass();
	}
	break;
      default:
	break;
      } 
    }

    void OverworldCtrl::checkEventsNoDialog(sf::Event& events, View::Overworld& overworld){
      if(!gameloop.getPlayer().getPosition().isAnim()) {
	if(isKeyPressed(sf::Keyboard::Return)) {
	  int lx = gameloop.getPlayer().getPosition().getPosition().x;
	  int ly = gameloop.getPlayer().getPosition().getPosition().y;
	  Side ppDir = gameloop.getPlayer().getPosition().getDir();
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
	  vector<Event *> events = Model::Data::World::map.at(gameloop.getPlayer().getMapID()).getEvent(sf::Vector2i(lx SQUARES, ly SQUARES));
	  
	  if(events.size() > 0) {
	    for(unsigned int i = 0; i < events.size(); i++) {
	      if(events[i]->getEventTrigger() == Events::EventTrigger::PRESS) {
		bool go = false;
		if(((events[i]->getSide() & SIDE_UP) == SIDE_UP) && ppDir == Side::TO_UP) {
		  go = true;
		} else if(((events[i]->getSide() & SIDE_DOWN) == SIDE_DOWN) && ppDir == Side::TO_DOWN) {
		  go = true;
		} else if(((events[i]->getSide() & SIDE_RIGHT) == SIDE_RIGHT) && ppDir == Side::TO_RIGHT) {
		  go = true;
		} else if(((events[i]->getSide() & SIDE_LEFT) == SIDE_LEFT) && ppDir == Side::TO_LEFT) {
		  go = true;
		}
		if(go) {
		  events[i]->action(Main::player);
		}
	      }
	    }
	  }
	}
      }

    }
  }
}
