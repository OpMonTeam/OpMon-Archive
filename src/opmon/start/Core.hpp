/**
  /*
  Core.hpp
  Author : Jlppc
  File under licence GNU GPL-3.0
  http://opmon-game.ga
  Core.hpp : Contains the main function and variables of the program.
*/
#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <SFML/System.hpp>



namespace OpMon{

  
  enum class GameStatus{
    CONTINUE, STOP, NEXT, PREVIOUS
  };


  
  /**Path to the options save file*/
  extern std::string optSave;
  /**
     sf::Clock counting the number of milliseconds passed since the beginning of the program
  */
  extern sf::Clock ticks;
  /**
     Returns the path depending of the system.
     By default, please use the "/" separator.
     Then, if the os is Windows, this function will change the "/" by "\".
     If you use the "\" separator in the path given,
     nothing will change, on unix systems and on Windows systems.
  */
  std::string getPath(std::string const& path);

  //#define TEST
  /**
     Function that handles errors on the program
  */
  void handleError(std::string const& errorName, bool fatal);
  /**
     Function quitting the game, deleting the resources
  */
  int quit(int const& returns);
  /*
  void bgTask();

  extern std::thread* bgtask;
  */

  extern bool debugMode;
  
  /*
    Useful operators for strings
  */
  std::string& operator<<(std::string &str, std::string const& thing);
  std::string& operator<<(std::string &str, int const& nbre);
  std::string& operator<<(std::string &str, char nbre[]);
  
  sf::Vector2i vec2fTo2i(sf::Vector2f const &toTrans);

  template<typename T>
  bool instanceof(auto toTry);
  
}

#include "Gameloop.hpp"

namespace OpMon{
    extern GameLoop gameloop;
}

#endif
