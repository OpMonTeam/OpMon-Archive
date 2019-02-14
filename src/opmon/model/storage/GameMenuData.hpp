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

	    sf::Texture selectionTexture[6];
	    sf::Vector2f selectionPos[6];
	    
	    UiData* uidata;
	    Player* player;
	    
	    GameMenuData(GameMenuData const&);
	    
	public:
	    GameMenuData(UiData* data, Player *player);

	    sf::Texture &getMenuTexture()  { return menuTexture; }
	    sf::Texture &getBackground()  { return background; }
	    void setBackground(sf::Texture const& bg) { background = bg; } 

	    sf::Texture& getSelectionTexture(int index) {return selectionTexture[index];}
	    sf::Vector2f& getSelectionPos(int index) {return selectionPos[index];}
	    
	    
	    UiData* getUiDataPtr() { return uidata; }
	    Player* getPlayerPtr() { return player; }
	    Player& getPlayer() { return *player; }
	};
	
    }
}
