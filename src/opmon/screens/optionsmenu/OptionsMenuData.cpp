/*
  OptionsMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "OptionsMenuData.hpp"

#include "src/utils/ResourceLoader.hpp"

namespace OpMon {
class UiData;

    OptionsMenuData::OptionsMenuData(UiData *data)
        : uidata(data) {
        Utils::ResourceLoader::load(selectBar, "sprites/misc/selectBar.png");
        Utils::ResourceLoader::load(creditsBg, "backgrounds/credits.png");
        Utils::ResourceLoader::load(controlsBg, "backgrounds/controls.png");
        Utils::ResourceLoader::load(volumeCur, "sprites/misc/cursor.png");
        Utils::ResourceLoader::load(keyChange, "sprites/misc/keyChange.png");
    }
} // namespace OpMon
