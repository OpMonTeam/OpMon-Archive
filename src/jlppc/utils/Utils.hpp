/*
Utils.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Définit le namespace Utils
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>
/**
Namespace contenant des fonctions utiles
*/
namespace Utils {
int randU(int limit);
unsigned int randUI(unsigned int limit);
void wait(int ticks);
long hash(std::string str);
}

#endif // UTILS_HPP
