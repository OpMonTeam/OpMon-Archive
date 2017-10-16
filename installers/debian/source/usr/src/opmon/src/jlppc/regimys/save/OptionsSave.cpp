#include "OptionsSave.hpp"
#include "../start/main.hpp"
#include <cstdlib>

UNS

namespace OptionsSave {

    int searchParam(string const &nom);

    Param::Param(string nom, string valeur) {
        this->paramName = nom;
        this->valeur = valeur;
    }

    string Param::getName() const {
        return this->paramName;
    }

    string Param::getValue() const {
        return this->valeur;
    }

    void Param::setValue(string value) {
        this->valeur = value;
    }

    std::vector<Param> paramList;

    Param getParam(string const &nom) {
        if(searchParam(nom) != -1) {
                return paramList[searchParam(nom)];
            }
        else {
                return Param("NULL", "NULL");
            }

    }

    void addOrModifParam(string const &nom, string const &value) {
        if(searchParam(nom) == -1) { //Add Param (No Exist)
                paramList.push_back(Param(nom, value));
            }
        else {//Param Exist
                paramList[searchParam(nom)].setValue(value);
            }
    }

    Param deleteParam(string const &nom) {
        if(searchParam(nom) == -1) {
                return Param("NULL", "NULL");
            }
        else {
                Param toReturn = paramList[searchParam(nom)];
                paramList.erase(paramList.begin() + searchParam(nom));
                return toReturn;
            }
    }

    int searchParam(string const &nom) {
      FOR_EACH(Param, paramList, (int) paramList.size(), {)
        if(objActuel->getName() == nom) {
            return itor;
        }
            }
    return -1;
}

void initParams(string const& file) {
        rlog << PRINT_TICKS << "Chargement des paramètres" << endl;
        ifstream stream(file.c_str());
        if(!stream) { //Si le fichier ne peut etre ouvert, il est crée et sera ouvert lors de la sauvegarde.
                ofstream strm(file.c_str());
                strm.close();
                ifstream cpy(file.c_str());
                handleError("Impossible d'ouvrir le fichier des paramètres. Si le fichier était seulement inexistant, il a été crée. Il sera ouvert donc correctement au redemmarage.", false);

            }
        string read;
        int i = 0;
        for(i = 0; i < 100000; i++) { //Empecher une boucle infinie (Donne du coup un maximum de 100000 paramètres, y'a de quoi faire.)
                getline(stream, read);
                if(!(read.substr(0, read.size() - (read.size() - 3)) == "pm|")) { //Vérifie si le préfixe pm| est bien présent, sinon arrête la boucle.
                        break;
                    }
                string noPm = StringKeys::split(read, '|', 1);//Ne prend que la partie après le pm|
                Param newParam = Param(StringKeys::split(noPm, '=', 0), StringKeys::split(noPm, '=', 1));//Splitte ensuite en deux parties, le nom et la valeur du paramètre.
                if(!checkParam(newParam.getName())) {
                        paramList.push_back(newParam);
                    }
            }
        if(i == 100000) {
                handleError("initParams : Boucle infinie stoppée", true);
            }

        stream.close();


    }

    void saveParams(string const& file) {
        ofstream stream(file.c_str());
        string toGo;
        FOR_EACH(Param, paramList, (int) paramList.size(), {)
                 //cout << objActuel->getName() << endl;
                 toGo+=("pm|" + objActuel->getName() + "=" + objActuel->getValue() + '\n');//Ajoute le pm| puis écrit le paramètre dans le fichier.
                 //cout << toGo;
                 stream << toGo;
                 toGo = string("");
                }
        stream.close();
    }

    bool checkParam(string const &name) {
        return searchParam(name) != -1;
    }

}
