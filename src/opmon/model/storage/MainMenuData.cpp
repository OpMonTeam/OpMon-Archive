/*
MainMenuData.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#include "MainMenuData.hpp"
#include "ResourceLoader.hpp"

namespace OpMon {
    namespace Model {
        MainMenuData::MainMenuData(UiData *ptr)
          : uidata(ptr) {
            ResourceLoader::load(arrChoice, "sprites/misc/arrChoiceScale.png");
        }
    } // namespace Model
} // namespace OpMon
