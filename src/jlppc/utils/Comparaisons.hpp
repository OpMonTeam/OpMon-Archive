/*
Comparaisons.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Définit le namespace Comparaions
*/
#ifndef COMPARAISONS_HPP
#define COMPARAISONS_HPP

#include <cstdarg>
#include <iostream>
/**
Permet de comparer des choses plus facilement
*/
namespace Comparaisons {
	template<typename T, typename U> bool multiEgal(T const &object, U toCompare[]);
}

#endif // COMPARAISONS_HPP
