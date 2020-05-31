/*!
 * \file MainMenuCtrl.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include "MainMenu.hpp"
#include "src/opmon/screens/base/AGameScreen.hpp"
#include "src/utils/CycleCounter.hpp"

namespace sf {
    class Event;
    class RenderTexture;
} // namespace sf

namespace OpMon {
    class GameData;

    /*!
     * \brief Manages the main menu of the game.
     */
    class MainMenuCtrl : public AGameScreen {
      private:
        MainMenuData data;
        MainMenu view;

        /*!
         * \brief Determines which screen has to be loaded in loadNextScreen().
         *
         * This integer is filled with some special values determined by macros
         * in GameMenuCtrl.cpp. Currently, there is LOAD_STARTSCENE and
         * LOAD_OPTIONS. Then, loadNextScreen loads in _next_gs a game screen
         * according the value of this variable().
         */
        MainMenuOption selectedOption = MainMenuOption::START_GAME;
        /*!
         * \brief The position of the cursor on the menu.
         */
        Utils::CycleCounter curPosI = Utils::CycleCounter(4);

      public:
        MainMenuCtrl(GameData *data);

        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus update(sf::RenderTexture &frame) override;

        void loadNextScreen() override;

        void suspend() override;
        void resume() override;
    };

} // namespace OpMon
