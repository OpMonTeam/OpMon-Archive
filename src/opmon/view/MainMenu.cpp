/*
MainMenu.cpp
Author : Cyrielle
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

        MainMenu::MainMenu(Model::MainMenuData &data, const std::size_t totalView)
          : data(data)
          , totalView(totalView)
          , mainMenuItems(this->totalView) {
            int i{0};
            float j{175.0};
            for(auto &mainMenuItem : mainMenuItems) {
                mainMenuItem.pos.x = 10.0;
                mainMenuItem.pos.y = j;

                mainMenuItem.text.setPosition(60.0, j);

                j += 85.0;
                ++i;
            }

            background.setTexture(data.getTitlescreen());
            cursor.setTexture(data.getArrChoice());

            initMainMenuItemsName();

            for(auto &mainMenuItem : mainMenuItems) {
                mainMenuItem.text.setSfmlColor(sf::Color::White);
                mainMenuItem.text.setFont(data.getUiDataPtr()->getFont());
                mainMenuItem.text.setCharacterSize(FONT_SIZE_DEFAULT);
            }

            data.getUiDataPtr()->getJukebox().play("Title");
        }

        void MainMenu::initMainMenuItemsName() {
            auto kget = Utils::StringKeys::get;

            int i{0};
            for(auto &mainMenuItem : mainMenuItems) {
                mainMenuItem.text.setString(kget("title." + std::to_string(i + 1)));
                ++i;
            }
        }

        void MainMenu::onLangChanged() {
            initMainMenuItemsName();
        }

        void MainMenu::pause() {
        }

        void MainMenu::play() {
            data.getUiDataPtr()->getJukebox().play("Title");
        }

        void MainMenu::draw(sf::RenderTexture &frame, int curPosI) {
            frame.clear(sf::Color::Black);

            frame.draw(background);

            for(auto &mainMenuItem : mainMenuItems) {
                frame.draw(mainMenuItem.text);
            }

            cursor.setPosition(mainMenuItems[curPosI].pos);
            frame.draw(cursor);
        }

    } // namespace View
} // namespace OpMon
