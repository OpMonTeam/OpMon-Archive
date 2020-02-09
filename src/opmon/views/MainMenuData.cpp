/*
  MainMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "MainMenuData.hpp"
#include "../core/system/ResourceLoader.hpp"

namespace OpMon {
    MainMenuData::MainMenuData(UiData *ptr)
        : uidata(ptr) {
        System::ResourceLoader::load(menuframe, "backgrounds/menuframe.png");
        System::ResourceLoader::load(arrChoice, "sprites/misc/arrChoiceScale.png");
    }
} // namespace OpMon
