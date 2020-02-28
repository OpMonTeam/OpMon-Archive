/*
  OptionsMenuData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "OptionsMenuData.hpp"

#include "src/opmon/core/system/ResourceLoader.hpp"

namespace OpMon {
class UiData;

    OptionsMenuData::OptionsMenuData(UiData *data)
        : uidata(data) {
        System::ResourceLoader::load(selectBar, "sprites/misc/selectBar.png");
        System::ResourceLoader::load(creditsBg, "backgrounds/credits.png");
        System::ResourceLoader::load(controlsBg, "backgrounds/controls.png");
        System::ResourceLoader::load(volumeCur, "sprites/misc/cursor.png");
        System::ResourceLoader::load(keyChange, "sprites/misc/keyChange.png");
    }
} // namespace OpMon
