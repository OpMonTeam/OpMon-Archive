#include "StartSceneCtrl.hpp"

namespace OpMon{
  namespace Controller{
    namespace StartSceneCtrl{
      GameStatus checkEvents(Event& event, StartScene& startscene){
	switch(event.type){
	case sf::Event::KeyPressed:
	  if(event.key.code == sf::Keyboard::Space){
	    startscene.getDialog()->pass();
	  }
	  if(event.key.code == sf::Keyboard::Return && startscene.getPart() == 1){
	    sf::String& pName = startscene.getpName();
	    if(pName.isEmpty()){
	      pName = "Player";
	    }
	    startscene.delLoop1();
	  }
	  break;
	case sf::Event::TextEntered:
	  if(startscene.getPart() == 1){
	    if(event.text.unicode == 8) { //Backspace
	      sf::String& pName = startscene.getpName();
	      if(!pName.isEmpty()){
		pName = sf::String::fromUtf32(pName.begin(), pName.end() - 1);
	      } else if(event.text.unicode == '\n' || event.text.unicode <= 32) {//Do nothing
	      } else {
		if (pName.toUtf32().size() < 14) {//14 = Max name length
		  pName += Main::mainframe.events.text.unicode;
		}
	      }
	    }
	  }
	}
      }
    }
  }
}
