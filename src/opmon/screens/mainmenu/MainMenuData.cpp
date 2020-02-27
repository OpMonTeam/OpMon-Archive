/*
  MainMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "MainMenuData.hpp"

#include "src/opmon/core/system/ResourceLoader.hpp"

namespace OpMon {
class UiData;

    MainMenuData::MainMenuData(UiData *ptr)
        : uidata(ptr) {
        System::ResourceLoader::load(arrChoice, "sprites/misc/arrChoiceScale.png");
    }
} // namespace OpMon
