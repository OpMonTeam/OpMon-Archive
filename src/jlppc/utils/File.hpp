/*
File.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
D�finit la classe RFile
*/
#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include "Class.hpp"
/**
Permet de stocker une chaine de caract�re dans le but de r�cuperer un flux d'entr�e ou de sortie
*/
class RFile {
public:
    RFile(std::string path);
    std::ifstream *getIn() const;
    std::ofstream *getOut() const;
protected:

private:
    std::string path;
};

#endif // FILE_HPP
