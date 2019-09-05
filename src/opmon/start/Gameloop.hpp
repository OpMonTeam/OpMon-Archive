/*
Gameloop.hpp
Author : Cyrielle
Contributor : Stelyus, BAKFR, Navet56
File under GNU GPL v3.0
*/

#pragma once

#include "../controller/AGameScreen.hpp"
#include "../model/storage/UiData.hpp"
#include "../view/Window.hpp"
#include "./GameStatus.hpp"
#include <memory>
#include <stack>

namespace OpMon {

    class GameLoop {
      public:
        GameLoop();
        ~GameLoop() = default;

        GameStatus operator()();

        /**
         * Checks the event to know if the game must be stopped.
         * Returns GameStatus::STOP if escape is pressed or if the game is closed.
         * Returns GameStatus::CONTINUE if the game must continue.
         */
        GameStatus _checkQuit(const sf::Event &event);

        /**
         * Checks the event for window resize, and updates the window view if it's the case.
         * @param event The native SFMl event
         * @param window A reference to the window in case an update is necessary
         */
        void _checkWindowResize(const sf::Event &event, View::Window &window) const;

        std::unique_ptr<Model::UiData> uidata;
        std::stack<std::unique_ptr<Controller::AGameScreen>> _gameScreens;

        bool frameByFrame = false;
        sf::Keyboard::Key fbfType = sf::Keyboard::F3;
        bool hasBeenReleased = true;
    };

} // namespace OpMon
