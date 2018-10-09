/**
  Core.hpp
  Author : Cyrion
  Contributor : BAKFR
  File under GNU GPL v3.0 license
*/
#ifndef CORE_HPP
#define CORE_HPP

#include "GameStatus.hpp"
#include <string>
#pragma GCC diagnostic ignored "-Wreorder"
#pragma GCC diagnostic ignored "-Wcomment"

namespace OpMon {

    /**
     Function that handles errors on the program
    */
    void handleError(std::string const &errorName, bool fatal = false);
    /**
     Function which quits the game, deleting the resources
    */
    int quit(int const &returns);

    extern bool debugMode;
    extern bool debugCol;

    extern bool reboot;

    /*
    Useful operators for strings
  */
    std::string &operator<<(std::string &str, std::string const &thing);
    std::string &operator<<(std::string &str, int nbre);
    std::string &operator<<(std::string &str, char nbre[]);

  OP_DEPRECATED template <typename Base, typename T>
    bool instanceOf(const Base *toTest);
} // namespace OpMon

#endif
