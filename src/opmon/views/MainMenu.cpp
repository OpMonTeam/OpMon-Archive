/*
  MainMenu.cpp
  Author : Cyrielle
  Contributors : BAKFR, torq
  File under GNU GPL v3.0 license
*/
#include "MainMenu.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>
#include <memory>
#include <string>

#include "../../utils/StringKeys.hpp"
#include "ui/TextBox.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/opmon/views/MainMenuData.hpp"
#include "src/opmon/views/ui/Jukebox.hpp"

namespace OpMon {

    int MAIN_MENU_ITEM_HEIGHT = 64;
    int MAIN_MENU_ITEM_WIDTH = 504;
    int MAIN_MENU_ITEM_PADDING = 4;

    MainMenu::MainMenu(MainMenuData &data)
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

    void MainMenu::update(int curPosI){
        for(auto &mainMenuItem : mainMenuItems) {
            mainMenuItem.setActive(false);
        }

        mainMenuItems[curPosI].setActive(true);
    }

    void MainMenu::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
        frame.clear(sf::Color(74, 81, 148));

        for(auto &mainMenuItem : mainMenuItems) {
            frame.draw(mainMenuItem);
        }
    }

} // namespace OpMon
