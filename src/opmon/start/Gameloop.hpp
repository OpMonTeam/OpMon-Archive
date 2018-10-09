/*
Gameloop.hpp
Author : Cyrion
Contributor : Stelyus, BAKFR, Navet56
File under GNU GPL v3.0
*/

#pragma once

#include "../controller/AGameScreen.hpp"
#include "../view/Window.hpp"
#include "./GameStatus.hpp"
#include <stack>

namespace OpMon {

    class GameLoop {
      public:
        GameLoop();
        ~GameLoop();

        GameStatus operator()();

        /**
	 * Checks the event to know if the game must be stopped.
	 * Returns GameStatus::STOP if escape is pressed or if the game is closed.
	 * Returns GameStatus::CONTINUE if the game must continue.
	 */
        GameStatus _checkQuit(const sf::Event &event);

      private:
        View::Window window;

        std::stack<Controller::AGameScreen *> _gameScreens;
    };

} // namespace OpMon
