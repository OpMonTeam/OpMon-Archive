/*
GameMenuData.cpp
Author : Cyriel
File under GNU GPL v3.0 license
*/

#include "GameMenuData.hpp"

namespace OpMon {
    namespace Model {

	GameMenuData::GameMenuData(UiData* data, Player *player)
	  : uidata(data)
	, player(player) {
	    ResourceLoader::load(menuTexture, "backgrounds/menu.png");  
	}
	
    }
}
