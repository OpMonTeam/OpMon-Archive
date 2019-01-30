/*
GameMenuData.hpp
Author : Cyriel
File under GNU GPL v3.0 license
*/
#pragma once

#include "UiData.hpp"
#include "../sysObjects/Player.hpp"
#include <SFML/Graphics/Texture.hpp>

namespace OpMon {
    namespace Model {

	class GameMenuData {
	private:
	    sf::Texture menuTexture;
	    sf::Texture background;

	    UiData* uidata;
	    Player* player;
	    
	    GameMenuData(GameMenuData const&);
	    
	public:
	    GameMenuData(UiData* data, Player *player);

	    sf::Texture &getMenuTexture()  { return menuTexture; }
	    sf::Texture &getBackground()  { return background; }
	    void setBackground(sf::Texture const& bg) { background = bg; } 
	    
	    
	    UiData* getUiDataPtr() { return uidata; }
	    Player* getPlayerPtr() { return player; }
	    Player& getPlayer() { return *player; }
	};
	
    }
}
