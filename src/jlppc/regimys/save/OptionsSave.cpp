#include "OptionsSave.hpp"
#include "../start/main.hpp"

UNS

namespace OptionsSave{

int searchParam(string nom);

Param::Param(string nom, string valeur){
    this->paramName = nom;
    this->valeur = valeur;
}

string Param::getName() const {return this->paramName;}

string Param::getValue() const {return this->valeur;}

void Param::setValue(string value){this->valeur = value;}

Param getParam(string const& nom){
    if(searchParam(nom) != -1){
        return paramList[searchParam(nom)];
    }else{
        return Param("NULL", "NULL");
    }

}

void addOrModifParam(string const& nom, string const& value){
    if(searchParam(nom) == -1){//Add Param (No Exist)
        paramList.push_back(Param(nom, value));
    }else{//Param Exist
        paramList[searchParam(nom)].setValue(value);
    }
}

Param deleteParam(string const& nom){
    if(searchParam(nom) == -1){
        return Param("NULL", "NULL");
    }else{
        Param toReturn = paramList[searchParam(nom)];
        paramList.erase(paramList.begin() + searchParam(nom));
        return toReturn;
    }
}

int searchParam(string nom){
    FOR_EACH(Param, paramList, paramList.size(), {)//{
        if(objActuel->getName() == nom){
            return itor;
        }
    }
    return -1;
}

}
