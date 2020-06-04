/*
  MainMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "MainMenuData.hpp"

#include <memory>

#include "src/utils/ResourceLoader.hpp"
#include "src/utils/exceptions.hpp"

namespace OpMon {

    MainMenuData::MainMenuData(GameData *ptr): gamedata(ptr) {
        Utils::ResourceLoader::load(arrChoice,
                                    "sprites/misc/arrChoiceScale.png");
    }
} // namespace OpMon
