/*
StringKeys.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la défnition du namespace StringKeys
*/
#ifndef STRINGKEYS_HPP
#define STRINGKEYS_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/System.hpp>

namespace StringKeys {
extern std::vector<std::string> keys;
extern std::vector<sf::String> strings;
sf::String &get(std::string key);
void initialize(std::string const& file);
sf::String split(sf::String const& str, char const& splitter, int const& part);
std::vector<sf::String> split(sf::String const& str, char const& splitter);
std::string sfStringtoStdString(sf::String const &str);
int countInstances(sf::String const& str, char const& toSearch);
}

#endif // STRINGKEYS_HPP
