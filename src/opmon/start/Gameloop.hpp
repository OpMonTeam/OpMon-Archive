/*
  Gameloop.hpp
  Author : Jlppc
  File under licence GNU GPL-3.0
  http://opmon-game.ga
  Contains
*/

#pragma once

#include <stack>
#include "./GameStatus.hpp"
#include "../controller/AGameScreen.hpp"


namespace OpMon{

  class GameLoop{
  public:
    GameLoop();
    GameStatus operator()();

    /**
     * Checks the event to know if the game must be stopped.
     * Returns GameStatus::STOP if escape is pressed or if the game is closed.
     * Returns GameStatus::CONTINUE if the game must continue.
     */
    GameStatus _checkQuit(const sf::Event &event);


  private:
    std::stack<Controller::AGameScreen*> _gameScreens;
  };

}
