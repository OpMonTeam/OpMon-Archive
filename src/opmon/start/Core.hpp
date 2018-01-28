/**
  Core.hpp
  Author : Jlppc
  File under licence GNU GPL-3.0
  http://opmon-game.ga
  Core.hpp : Contains the main function and variables of the program.
*/
#ifndef CORE_HPP
#define CORE_HPP

#include "GameStatus.hpp"

namespace OpMon{

  
  /**Path to the options save file*/
  extern std::string optSave;

  //#define TEST
  /**
     Function that handles errors on the program
  */
  void handleError(std::string const& errorName, bool fatal);
  /**
     Function quitting the game, deleting the resources
  */
  int quit(int const& returns);

  extern bool debugMode;
  
  /*
    Useful operators for strings
  */
  std::string& operator<<(std::string &str, std::string const& thing);
  std::string& operator<<(std::string &str, int const& nbre);
  std::string& operator<<(std::string &str, char nbre[]);

  extern int* frames;

  int getFrames();
  

  template<typename Base, typename T>
  bool instanceOf(const Base *toTest);
}


#endif
