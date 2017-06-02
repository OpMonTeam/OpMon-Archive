/*
OptionsSave.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace OptionsSave
*/
#ifndef OPTIONSSAVE_HPP
#define OPTIONSSAVE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../start/StringKeys.hpp"

//Ces deux macros sont la pour faire apparaitre le contexte de l'utilisation de la methode addOrModifyParam dans le code (et pour faire plus court aussi ;-)  )
#define addParam addOrModifParam
#define modifyParam addOrModifParam

/**
Namespace permettant de sauvegarder les paramètres
*/
namespace OptionsSave{
    /**
    Classe définissant un paramètre
    */
    class Param{
        private:
        std::string paramName;
        std::string valeur;
        public:
        Param(std::string name, std::string valeur);
        std::string getName() const;
        std::string getValue() const;
        void setValue(std::string value);

    };

    extern std::vector<Param> paramList;

    Param getParam(std::string const& nom);

    void addOrModifParam(std::string const& nom, std::string const& value);

    Param deleteParam(std::string const& nom);

    //CPP ONLY :
    //int searchParam(string nom);

    void saveParams(std::string file);

    void initParams(std::string file);

    bool checkParam(std::string const& name);

}

#endif // OPTIONSSAVE_HPP
