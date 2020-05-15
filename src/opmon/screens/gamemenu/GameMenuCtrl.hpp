/*!
 * \file GameMenuCtrl.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "src/utils/CycleCounter.hpp"
#include "GameMenu.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"

namespace sf {
class Event;
class RenderTexture;
}  // namespace sf

namespace OpMon {
class GameMenuData;
class Player;

    /*!
     * \brief Controller of the in-game menu.
     */
    class GameMenuCtrl : public AGameScreen {
    private:
        GameMenuData &data;

        GameMenu view;
        Player &player;

        /*!
         * \brief Determines which screen has to be loaded in loadNextScreen().
         *
         * This integer is filled with some special values determined by macros in GameMenuCtrl.cpp. Currently, there is LOAD_OPTIONS. Then, loadNextScreen() loads in _next_gs a game screen according the value of this variable.
         */
        SubMenu submenuToLoadNext = SubMenu::SAVE_MENU;

        /*!
         * \brief The position of the cursor on the menu.
         */
        Utils::CycleCounter curPos = Utils::CycleCounter(6);

    public:
        ~GameMenuCtrl();

        GameMenuCtrl(GameMenuData &data, Player &player);

        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus update(sf::RenderTexture &frame) override;

        void loadNextScreen() override;
        void suspend() override;
        void resume() override;
    };

} // namespace OpMon
