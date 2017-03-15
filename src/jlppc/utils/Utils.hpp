/*
Utils.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
D�finit le namespace Utils
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <ctime>
#include <cstdlib>
/**
Namespace contenant des fonctions utiles
*/
namespace Utils {
	int randU(int limit);
	unsigned int randUI(unsigned int limit);
	void wait(int ticks);
}

#endif // UTILS_HPP
