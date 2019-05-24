/*
Gameloop.hpp
Author : Cyriel
Contributor : Stelyus, BAKFR, Navet56, PyroFlareX
File under GNU GPL v3.0
*/

#pragma once

#include "../controller/AGameScreen.hpp"
#include "../model/storage/UiData.hpp"
#include "../view/Window.hpp"
#include "./GameStatus.hpp"
#include <memory>
#include <stack>
#include <functional>

namespace OpMon {

    class GameLoop {
      public:
        GameLoop();
        ~GameLoop() = default;

        GameStatus runLoop();

        /**
         * Checks the event to know if the game must be stopped.
         * Returns GameStatus::STOP if escape is pressed or if the game is closed.
         * Returns GameStatus::CONTINUE if the game must continue.
         */
        GameStatus CheckforClose(sf::Event &event);

        std::unique_ptr<Model::UiData> uidata;
        std::stack<std::unique_ptr<Controller::AGameScreen>> _gameScreens;
    };

} // namespace OpMon
