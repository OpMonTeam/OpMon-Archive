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

namespace OpMon {
    namespace View {

        void MainMenu::initStrings() {
            auto kget = Utils::StringKeys::get;

            int i{0};
            for(auto& optionVec : optionsVec) {
                optionVec.text.setString(kget("title." + std::to_string(i + 1)));
                ++i;
            }
        }

        MainMenu::MainMenu(Model::MainMenuData &data, const std::size_t totalView)
          : data(data)
          , totalView(totalView)
          , optionsVec(this->totalView) {
            int i{0};
            float j{175.0};
            for(auto& optionVec : optionsVec) {
                optionVec.pos.x = 10.0;
                optionVec.pos.y = j;

                optionVec.text.setPosition(60.0, j);

                j += 85.0;
                ++i;
            }

            bg.setTexture(data.getTitlescreen());
            cursor.setTexture(data.getArrChoice());

            initStrings();

            for(auto& optionVec : optionsVec) {
                optionVec.text.setSfmlColor(sf::Color::White);
                optionVec.text.setFont(data.getUiDataPtr()->getFont());
                optionVec.text.setCharacterSize(FONT_SIZE_DEFAULT);
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

            for(auto& optionVec : optionsVec) {
                frame.draw(optionVec.text);
            }

            cursor.setPosition(optionsVec[curPosI].pos);
            frame.draw(cursor);
        }

    } // namespace View
} // namespace OpMon
