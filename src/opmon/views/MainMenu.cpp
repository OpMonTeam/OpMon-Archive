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
#include "ui/TextBox.hpp"

namespace OpMon {
    namespace View {

        int MAIN_MENU_ITEM_HEIGHT = 64;
        int MAIN_MENU_ITEM_WIDTH = 504;
        int MAIN_MENU_ITEM_PADDING = 4;

        MainMenu::MainMenu(Model::MainMenuData &data)
          : data(data) {

            for(int i = 0; i < 4; i++) {
                sf::Vector2f position(MAIN_MENU_ITEM_PADDING, MAIN_MENU_ITEM_PADDING + i * (MAIN_MENU_ITEM_HEIGHT + MAIN_MENU_ITEM_PADDING));
                TextBox mainMenuItem(data.getMenuframe(), position, MAIN_MENU_ITEM_WIDTH, MAIN_MENU_ITEM_HEIGHT);
                mainMenuItem.setFont(data.getUiDataPtr()->getFont());
                mainMenuItems.push_back(mainMenuItem);
            }

            initMainMenuItemsName();

            data.getUiDataPtr()->getJukebox().play("Title");
        }

        void MainMenu::initMainMenuItemsName() {
            auto kget = Utils::StringKeys::get;

            int i{0};
            for(auto &mainMenuItem : mainMenuItems) {
                mainMenuItem.setLeftContent(kget("title." + std::to_string(i + 1)));
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
            frame.clear(sf::Color(74, 81, 148));

            for(auto &mainMenuItem : mainMenuItems) {
                mainMenuItem.setActive(false);
            }

            mainMenuItems[curPosI].setActive(true);

            for(auto &mainMenuItem : mainMenuItems) {
                frame.draw(mainMenuItem);
            }
            
        }

    } // namespace View
} // namespace OpMon
