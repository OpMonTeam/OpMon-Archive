/*
  MainMenuData.hpp
  Author : Cyrion
  File under GNU GPL v3.0 license
*/
#pragma once

#include "UiData.hpp"

namespace OpMon {
    namespace Model {
        class MainMenuData {
          private:
            sf::Texture titlescreen;
            sf::Texture arrChoice;

            UiData *uidata;

            MainMenuData(MainMenuData const &);

          public:
            UiData *getUiDataPtr() const { return uidata; }
            sf::Texture const &getTitlescreen() const { return titlescreen; }
            sf::Texture const &getArrChoice() const { return arrChoice; }
            MainMenuData(UiData *ptr);
        };
    } // namespace Model
} // namespace OpMon
