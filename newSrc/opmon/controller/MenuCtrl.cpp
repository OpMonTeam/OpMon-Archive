#include "MenuCtrl.hpp"

namespace OpMon{
	namespace Controller{
		namespace MenuCtrl{
			Interface* chackEvents(sf::Events& event, View::MainMenu& menu){
				switch(event) {

				  case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Return) {
					  switch(curPosI) {
					  case 0:
						bgMusTitle.stop();
						return (View::Interface*) new View::StartScene();
					  case 3:
						bgMusTitle.stop();
						return nullptr;
					  case 2:
						return (View::Interface*) new View::OptionsMenu();
						break;
					  case 1:
						Model::Data::Sounds::nopeSound.play();
						return &menu;
					  }
					}else if(event.key.code == sf::Keyboard::Up){
						menu.moveArrow(true);
					}else if(event.key.code == sf::Keyboard::Down){
						menu.moveArrow(false);
					}
					break;
				default:
					break;

				}
			}
		}
	}
}