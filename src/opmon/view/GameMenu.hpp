/*
GameMenu.hpp
Author : Cyriel
File under GNU GPL v3.0 license
*/
#pragma once

#include "../model/storage/GameMenuData.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace OpMon {
    namespace View {

	class GameMenu {
	private:
	    sf::Sprite background;
	    sf::Sprite menuBg;

	    Model::GameMenuData &data;
	public:
	    GameMenu(Model::GameMenuData &data);
	};
	
    }
}
