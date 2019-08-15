/*
GameMenu.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#pragma once

#include "../model/storage/GameMenuData.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace OpMon {
    namespace View {

        class GameMenu {
          private:
            sf::Sprite background;
            sf::Sprite menuBg;
            sf::Sprite selections[6];
            sf::Text selectxt[6];

            Model::GameMenuData &data;

            int curPos = 0;

          public:
            GameMenu(Model::GameMenuData &data);

            GameStatus operator()(sf::RenderTexture &frame);

            void setCurPos(int newCurPos);
        };

    } // namespace View
} // namespace OpMon
