#include "OverworldCtrl.hpp"

namespace OpMon{
  namespace Controller{
    void OverworldCtrl::checkEvents(sf::Event const& events, View::Overworld& overworld, bool dialog, Player& player){
      
      switch(events.type) {
      case sf::Event::KeyPressed:
	if(events.key.code == sf::Keyboard::Equal) {
	  debugMode = !debugMode;
	}
	if(debugMode) {
	  if(events.key.code == sf::Keyboard::F10) {
	    overworld.printlayer[0] = !overworld.printlayer[0];
	  }
	  if(events.key.code == sf::Keyboard::F11) {
	    overworld.printlayer[1] = !overworld.printlayer[1];
	  }
	  if(events.key.code == sf::Keyboard::F12) {
	    overworld.printlayer[2] = !overworld.printlayer[2];
	  }

	  
	}
      default:
	break;
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
	checkEventsNoDialog(events, player);
      }
      
            
    }
    

    void Overworld::checkEventsDialog(sf::Event const& events, View::Overworld& overworld){
      switch(events.type) {	  
      case sf::Event::KeyPressed:
	if(events.key.code == sf::Keyboard::Space) {
	  overworld.getDialog()->pass();
	}
	break;
      default:
	break;
      } 
    }

    void OverworldCtrl::checkEventsNoDialog(sf::Event const& event, Player& player){
      EventsCtrl::updateEvents(player.getMapID(), player);
      EventsCtrl::checkAction(event, player);
    }
  }
}
