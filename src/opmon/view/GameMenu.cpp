/*
GameMenu.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/

#include "GameMenu.hpp"
#include "../../utils/StringKeys.hpp"

namespace OpMon {
    namespace View {

        GameMenu::GameMenu(Model::GameMenuData &data)
          : data(data) {
            background.setTexture(data.getBackground());
            menuBg.setTexture(data.getMenuTexture());
            for(size_t i = 0; i < 6; i++) {
                selections[i].setTexture(data.getSelectionTexture(i));
                selections[i].setPosition(data.getSelectionPos(i));
                selectxt[i].setFont(data.getUiDataPtr()->getFont());
                selectxt[i].setCharacterSize(22);
                selectxt[i].setSfmlColor(sf::Color::White);
            }
            selectxt[0].setString(Utils::StringKeys::get("gamemenu.save"));
            selectxt[1].setString(Utils::StringKeys::get("gamemenu.id"));
            selectxt[2].setString(Utils::StringKeys::get("gamemenu.bag"));
            selectxt[3].setString(Utils::StringKeys::get("gamemenu.opmons"));
            selectxt[4].setString(Utils::StringKeys::get("gamemenu.opdex"));
            selectxt[5].setString(Utils::StringKeys::get("gamemenu.settings"));

            selectxt[0].setPosition(150, 140);
            selectxt[1].setPosition(260, 140);
            selectxt[2].setPosition(115, 225);
            selectxt[3].setPosition(312, 225);
            selectxt[4].setPosition(150, 310);
            selectxt[5].setPosition(260, 310);


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
            for(size_t i = 0; i < 6; i++){
              frame.draw(selectxt[i]);
            }
            return GameStatus::CONTINUE;
        }

    } // namespace View
} // namespace OpMon
