/*
MainMenu.cpp
Author : Cyrion
Contributors : BAKFR, torq
File under GNU GPL v3.0 license
*/
#include "MainMenu.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/log.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "OptionsMenu.hpp"
#include "Window.hpp"
#include <iostream>

namespace OpMon {
    namespace View {

        void MainMenu::initStrings() {
            auto kget = Utils::StringKeys::get;

            playtx.setString(kget("title.1"));
            charge.setString(kget("title.2"));
            options.setString(kget("title.3"));
            exit.setString(kget("title.4"));
        }

        MainMenu::MainMenu(Model::MainMenuData &data)
          : data(data) {
            sf::Text *textPos[4] = {&playtx, &charge, &options, &exit};
            for(int i = 0, j = 175; i < 4; i++) {
                curPos[i].x = 10;
                curPos[i].y = j;
                textPos[i]->setPosition(sf::Vector2f(60, j));
                j += 85;
            }
            bg.setTexture(data.getTitlescreen());
            cursor.setTexture(data.getArrChoice());

            initStrings();

            for(auto *text : textPos) {
                text->setSfmlColor(sf::Color::White);
                text->setFont(data.getUiDataPtr()->getFont());
                text->setCharacterSize(FONT_SIZE_DEFAULT);
            }

            data.getUiDataPtr()->getJukebox().play("Title");
        }

        void MainMenu::onLangChanged() {
            initStrings();
        }

        void MainMenu::pause() {
        }

        void MainMenu::play() {
            data.getUiDataPtr()->getJukebox().play("Title");
        }

        void MainMenu::draw(sf::RenderTexture &frame, int curPosI) {
            frame.clear(sf::Color::Black);
            frame.draw(bg);
            frame.draw(playtx),
            frame.draw(charge);
            frame.draw(options);
            frame.draw(exit);
            cursor.setPosition(curPos[curPosI]);
            frame.draw(cursor);
        }

    } // namespace View
} // namespace OpMon
