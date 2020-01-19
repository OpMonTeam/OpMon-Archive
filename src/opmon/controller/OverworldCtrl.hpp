/*!
 * \file OverworldCtrl.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
*/
#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Player.hpp"
#include "../start/Core.hpp"
#include "../view/Overworld.hpp"
#include "AGameScreen.hpp"
#include "EventsCtrl.hpp"

namespace OpMon {
    namespace Controller {

        /*!
         * \brief Manages the overworld.
         *
         * This class checks for the different SFML events the player can trigger to interact with the overworld, like the directional keys to move the player, and then calls the associated methods/functions.
         * It also manages the two overworld states : the free state where the player can move and explore, and the dialog state, when a dialog is currently on screen.
         * Finally, it updates the Event objects and manages the debug mode.
         */
        class OverworldCtrl : public AGameScreen {
          private:
            Model::OverworldData data;

            View::Overworld view;
            Model::Player &player;

            /*!
             * \brief Determines which screen has to be loaded in loadNextScreen().
             *
             * This integer is filled with some special values determined by macros in GameMenuCtrl.cpp. Currently, there is
             * - LOAD_BATTLE : Loads BattleCtrl
             * - LOAD_MENU_OPEN : Loads the opening animation for the menu. Called when the player presses the menu key.
             * - LOAD_MENU_CLOSE : Loads the closing animation for the menu. Called when OverworldCtrl::checkEvent is called right after the end of GameMenuCtrl.
             * - LOAD_MENU : Loads GameMenuCtrl. Called when OverworldCtrl::checkEvent is called right after the end of the opening animation.
             * Then, loadNextScreen() loads in _next_gs a game screen according the value of this variable.
             */
            int loadNext = 0;

            /*!
             * \brief Contains a screenshot.
             * \details A screenshot of the frame is taken in update(sf::RenderTexture&). It used as a background in GameMenu and its opening/closing animations.
             */
            sf::Texture screenTexture;

          public:
            OverworldCtrl(Model::Player &player, Model::UiData *uidata);

            GameStatus checkEvent(sf::Event const &event) override;
            /*!
             * \brief Checks the necessary events when a dialog is currently playing.
             */
            GameStatus checkEventsDialog(sf::Event const &events, View::Overworld &overworld);
            /*!
             * \brief Checks the necessary events when no dialog is currently playing.
             */
            GameStatus checkEventsNoDialog(sf::Event const &events, Model::Player &player);
            GameStatus update(sf::RenderTexture &frame) override;

            virtual void loadNextScreen();
            virtual void suspend();
            virtual void resume();
        };

    } // namespace Controller
} // namespace OpMon

#endif
