/*
  MainMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "MainMenuData.hpp"

#include "src/utils/ResourceLoader.hpp"

namespace OpMon {
class UiData;

    MainMenuData::MainMenuData(UiData *ptr)
        : uidata(ptr) {
        Utils::ResourceLoader::load(arrChoice, "sprites/misc/arrChoiceScale.png");
    }
} // namespace OpMon
