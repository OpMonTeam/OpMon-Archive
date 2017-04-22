#ifndef OPTIONSSAVE_HPP
#define OPTIONSSAVE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../start/StringKeys.hpp"

//Ces deux lignes sont la pour faire apparaitre le contexte de l'utilisation de la methode dans le code.
#define addParam addOrModifParam
#define modifyParam addOrModifParam


namespace OptionsSave{

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

    bool checkParam(std::string name);

}

#endif // OPTIONSSAVE_HPP
