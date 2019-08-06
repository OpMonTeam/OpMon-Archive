/*
  StartSceneData.hpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#pragma once

#include "../sysObjects/Player.hpp"
#include "UiData.hpp"
#include <SFML/Graphics/Texture.hpp>

namespace OpMon {
    namespace Model {

        class StartSceneData {
          private:
            sf::Texture background;
            sf::Texture prof;
            sf::Texture nameBg;

            UiData *uidata;

            Player *player;

            StartSceneData(StartSceneData const &);

          public:
            Player &getPlayer() { return *player; }
            Player *getPlayerPtr() { return player; }
            UiData *getUiDataPtr() { return uidata; }
            sf::Texture &getBackground() { return background; }
            sf::Texture &getProf() { return prof; }
            sf::Texture &getNameBg() { return nameBg; }

            StartSceneData(UiData *data);
        };

    } // namespace Model
} // namespace OpMon
