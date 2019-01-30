/**
GameMenuCtrl.hpp
Author : Cyriel
File under GNU GPL v3.0 license
*/
#pragma once

#include "AGameScreen.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../model/storage/GameMenuData.hpp"
#include "../view/GameMenu.hpp"

namespace OpMon {
    namespace Controller {

	class GameMenuCtrl : public AGameScreen {
	private:
	    Model::GameMenuData &data;

	    View::GameMenu view;
	    Model::Player &player;

	public:
	    ~GameMenuCtrl();
	    
	    GameMenuCtrl(Model::GameMenuData &data, Model::Player &player);

	    GameStatus checkEvent(sf::Event const &event) override;
	    GameStatus update(sf::RenderTexture &frame) override;
	    
            virtual void loadNextScreen();
            virtual void suspend();
            virtual void resume();
	};
	
    }
}
