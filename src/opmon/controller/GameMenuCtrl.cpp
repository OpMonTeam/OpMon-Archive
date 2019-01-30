/*
GameMenuCtrl.cpp
Author : Cyriel
File under GNU GPL v3.0 license
*/

#include "GameMenuCtrl.hpp"

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
	    return GameStatus::CONTINUE;
	}

	GameStatus GameMenuCtrl::update(sf::RenderTexture &frame) {
	    return GameStatus::CONTINUE;
	}

	void GameMenuCtrl::loadNextScreen() {
	    
	}

	void GameMenuCtrl::suspend() {
	    
	}

	void GameMenuCtrl::resume() {
	    
	}
	
    }
}
