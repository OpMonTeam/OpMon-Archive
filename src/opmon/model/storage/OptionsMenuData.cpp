/*
  OptionsMenuData.cpp
  Author : Cyrion
  File under GNU GPL v3.0 license
*/
#include "OptionsMenuData.hpp"
#include "ResourceLoader.hpp"

namespace OpMon {
    namespace Model {
        OptionsMenuData::OptionsMenuData(UiData *data)
          : uidata(data) {
            ResourceLoader::load(background, "backgrounds/options.png");
            ResourceLoader::load(selectBar, "sprites/misc/selectBar.png");
            ResourceLoader::load(langBg, "backgrounds/lang.png");
            ResourceLoader::load(yesTx, "sprites/misc/yes.png");
            ResourceLoader::load(creditsBg, "backgrounds/credits.png");
            ResourceLoader::load(volumeCur, "sprites/misc/cursor.png");
        }
    } // namespace Model
} // namespace OpMon
