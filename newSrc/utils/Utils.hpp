/*
Utils.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Définit le namespace Utils
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
/**
Namespace contenant des fonctions utiles
*/
namespace Utils {
int randU(int limit);
unsigned int randUI(unsigned int limit);
void wait(int ticks);
long hash(std::string str);
  // Create a directory (if it doesn't exist yet)
bool mkdir(const std::string &path);
}

#endif // UTILS_HPP
