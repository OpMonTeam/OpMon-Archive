/*
GameMenu.cpp
Author : Cyriel
File under GNU GPL v3.0 license
*/

#include "GameMenu.hpp"

namespace OpMon {
    namespace View {

	GameMenu::GameMenu(Model::GameMenuData &data)
	  : data(data){
	    background.setTexture(data.getBackground());
	    menuBg.setTexture(data.getMenuTexture());
	}
	
    }
}
