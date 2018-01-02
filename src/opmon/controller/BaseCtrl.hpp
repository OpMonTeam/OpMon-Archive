/*
BaseCtrl.hpp
Author : Jlppc
File under GNU-GPL 3.0 licence
http://opmon-game.ga
*/
#ifndef BASECTRL_HPP
#define BASECTRL_HPP


#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"



namespace OpMon{
  /**
     Namespace containing all the controllers
  */
  namespace Controller{
    /**
       Checks the event to know if the game must be stopped. 
       Returns GameStatus::STOP if escape is pressed or if the game is closed. 
       Returns GameStatus::CONTINUE if the game must continue.
    */
    GameStatus checkQuit(sf::Event& event);
  }
}

#endif
