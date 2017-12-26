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
	  break;
	}
      }
    }
  }
}
