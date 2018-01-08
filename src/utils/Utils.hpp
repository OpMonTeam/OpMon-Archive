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
  void wait(int duration);
  long hash(std::string str);
  // Create a directory (if it doesn't exist yet)
  bool mkdir(const std::string &path);

  /**
   Returns the path depending of the system.
   By default, please use the "/" separator.
   Then, if the os is Windows, this function will change the "/" by "\".
   If you use the "\" separator in the path given,
   nothing will change, on unix systems and on Windows systems.
  */
  std::string getPath(std::string const& path);
}

#endif // UTILS_HPP
