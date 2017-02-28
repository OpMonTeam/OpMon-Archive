/*
StringKeys.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la défnition du namespace StringKeys
*/
#ifndef STRINGKEYS_HPP
#define STRINGKEYS_HPP

#include <iostream>
#include <vector>
#include <fstream>

namespace StringKeys {
	extern std::ifstream keysFile;
	extern std::vector<std::string> keys;
	extern std::vector<std::string> strings;
	std::string get(std::string key);
	void initialize();
	std::string split(std::string str, char splitter, int part);
}

#endif // STRINGKEYS_HPP
