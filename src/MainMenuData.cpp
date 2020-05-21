/*
  MainMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "MainMenuData.hpp"

#include "ResourceLoader.hpp"

namespace OpMon {
class GameData;

    MainMenuData::MainMenuData(GameData *ptr)
        : gamedata(ptr) {
        Utils::ResourceLoader::load(arrChoice, "sprites/misc/arrChoiceScale.png");
    }
} // namespace OpMon
