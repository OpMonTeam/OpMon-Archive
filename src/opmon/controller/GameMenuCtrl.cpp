/*
GameMenuCtrl.cpp
Author : Cyriel
File under GNU GPL v3.0 license
*/

#include "GameMenuCtrl.hpp"
#include "OptionsMenuCtrl.hpp"

#define LOAD_OPTIONS 1

namespace OpMon {
    namespace Controller {

	GameMenuCtrl::~GameMenuCtrl(){
	    
	}
	
	GameMenuCtrl::GameMenuCtrl(Model::GameMenuData &data, Model::Player &player)
	  : data(data),
	view(data),
	player(player){
	    
	}

	GameStatus GameMenuCtrl::checkEvent(sf::Event const& event) {
	    switch(event.type) {
	    case sf::Event::KeyPressed:
			if(event.key.code == sf::Keyboard::M){
				return GameStatus::PREVIOUS_NLS;
			}
			if(event.key.code == sf::Keyboard::Up){
				curPos -= 2;
			}
			if(event.key.code == sf::Keyboard::Down){
				curPos += 2;
			}
			if(event.key.code == sf::Keyboard::Left){
				curPos--;
			}
			if(event.key.code == sf::Keyboard::Right){
				curPos++;
			}
			if(event.key.code == sf::Keyboard::Return){
				switch(curPos.getValue()){
					case 5:
						loadNext = LOAD_OPTIONS;
						return GameStatus::NEXT_NLS;
					default:
						data.getUiDataPtr()->getJukebox().playSound("nope");
						break;
				}
			}
			view.setCurPos(curPos.getValue());
	    default:
			break;
	    }

	    return GameStatus::CONTINUE;
	}

	GameStatus GameMenuCtrl::update(sf::RenderTexture &frame) {
	    return view(frame);
	}

	void GameMenuCtrl::loadNextScreen() {
	   switch(loadNext){
		   case LOAD_OPTIONS:
                _next_gs = std::make_unique<OptionsMenuCtrl>(data.getUiDataPtr());
                break;
           default:
                handleError("Error : Unknown view to load in MainMenuCtrl.", true);
	   }
	}

	void GameMenuCtrl::suspend() {
	    
	}

	void GameMenuCtrl::resume() {
	    
	}
	
    }
}
