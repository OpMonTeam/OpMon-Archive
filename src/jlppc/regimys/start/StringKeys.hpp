/*
StringKeys.hpp
Auteur : Jlppc
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
sf::String& get(std::string key);
void initialize(std::string file);
sf::String split(sf::String str, char splitter, int part);
}

#endif // STRINGKEYS_HPP
