/*
GameMenu.cpp
Author : Cyriel
File under GNU GPL v3.0 license
*/

#include "GameMenu.hpp"

namespace OpMon {
    namespace View {

        GameMenu::GameMenu(Model::GameMenuData &data)
          : data(data) {
            background.setTexture(data.getBackground());
            menuBg.setTexture(data.getMenuTexture());
            for(size_t i = 0; i < 6; i++) {
                selections[i].setTexture(data.getSelectionTexture(i));
                selections[i].setPosition(data.getSelectionPos(i));
            }
        }

        void GameMenu::setCurPos(int newCurPos) {
            if(newCurPos < 6 && newCurPos >= 0) {
                curPos = newCurPos;
            }
        }

        GameStatus GameMenu::operator()(sf::RenderTexture &frame) {
            frame.draw(background);
            frame.draw(menuBg);
            frame.draw(selections[curPos]);
            return GameStatus::CONTINUE;
        }

    } // namespace View
} // namespace OpMon
