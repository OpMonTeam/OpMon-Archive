/*
StringKeys.hpp
Author : Jlppc
File under GNU GPL 3.0 licence
http://opmon-game.ga
*/
#ifndef STRINGKEYS_HPP
#define STRINGKEYS_HPP

#include <iostream>
#include <vector>
#include <SFML/System/String.hpp>

#include "defines.hpp"

namespace Utils {
  namespace StringKeys {
    extern std::vector<std::string> keys;
    extern std::vector<sf::String> strings;

    sf::String &get(std::string key);

    void initialize(std::string file);

    OP_DEPRECATED sf::String split(sf::String const &str, char const &splitter, int const &part);

    std::vector<sf::String> split(sf::String const &str, char const &splitter);

    std::string sfStringtoStdString(sf::String const &str);

    int countInstances(sf::String const &str, char const &toSearch);
  }
}

#endif // STRINGKEYS_HPP
