/*
File.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Définit la classe RFile
*/
#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include "Class.hpp"
/**
Permet de stocker une chaine de caractère dans le but de récuperer un flux d'entrée ou de sortie
*/
class RFile
{
    public:
        RFile(std::string path);
        std::ifstream* getIn() const;
        std::ofstream* getOut() const;
    protected:

    private:
        std::string path;
};

#endif // FILE_HPP
