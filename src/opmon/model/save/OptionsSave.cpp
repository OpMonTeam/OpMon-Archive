#include "OptionsSave.hpp"
#include "../../start/main.hpp"
#include "../../start/Core.hpp"
#include "../../../utils/log.hpp"

UNS

namespace OpMon{
  namespace Model{
    namespace OptionsSave {

      int searchParam(string const &name);

      Param::Param(string name, string value) {
	this->paramName = name;
	this->value = value;
      }

      string Param::getName() const {
	return this->paramName;
      }

      string Param::getValue() const {
	return this->value;
      }

      void Param::setValue(string value) {
	this->value = value;
      }

      std::vector<Param> paramList;

      Param getParam(string const &name) {
	if(searchParam(name) != -1) {
	  return paramList[searchParam(name)];
	} else {
	  return Param("NULL", "NULL");
	}

      }

      void addOrModifParam(string const &name, string const &value) {
	if(searchParam(name) == -1) { //Add Param (No Exist)
	  paramList.push_back(Param(name, value));
	} else { //Param Exist
	  paramList[searchParam(name)].setValue(value);
	}
      }

      Param deleteParam(string const &name) {
	if(searchParam(name) == -1) {
	  return Param("NULL", "NULL");
	} else {
	  Param toReturn = paramList[searchParam(name)];
	  paramList.erase(paramList.begin() + searchParam(name));
	  return toReturn;
	}
      }

      int searchParam(string const &name) {
	for (size_t i = 0; i < paramList.size(); ++i) {
	  if (paramList[i].getName() == name) {
	    return i;
	  }
	}
	return -1;
      }

      void initParams(string const& file) {
	oplog("Settings loading");
	ifstream stream(file.c_str());
	if(!stream) { //Si le fichier ne peut etre ouvert, il est crée et sera ouvert lors de la sauvegarde.
	  ofstream strm(file.c_str());
	  strm.close();
	  ifstream cpy(file.c_str());
	  handleError("Unable to open the settings file. If the file was only non-existent, it was created. It will therefore be opened correctly when rebooting.", false);

	}
	string read;
	int i = 0;
	for(i = 0; i < 100000; i++) { //Empecher une boucle infinie (Donne du coup un maximum de 100000 paramètres, y'a de quoi faire.)
	  getline(stream, read);
	  if(!(read.substr(0, read.size() - (read.size() - 3)) == "pm|")) { //Vérifie si le préfixe pm| est bien présent, sinon arrête la boucle.
	    break;
	  }
	  string noPm = StringKeys::sfStringtoStdString(StringKeys::split(read, '|', 1));//Ne prend que la partie après le pm|
	  Param newParam = Param(StringKeys::sfStringtoStdString(StringKeys::split(noPm, '=', 0)), StringKeys::sfStringtoStdString(StringKeys::split(noPm, '=', 1)));//Splitte ensuite en deux parties, le name et la valeur du paramètre.
	  if(!checkParam(newParam.getName())) {
	    paramList.push_back(newParam);
	  }
	}
	if(i >= 100000) {
	  handleError("initParams : Endless loop stopped", true);
	}

	stream.close();


      }

      void saveParams(string const& file) {
	ofstream stream(file.c_str());
	string toGo;
	for (auto &currentObj : paramList) {
	  //cout << objActuel->getName() << endl;
	  toGo += ("pm|" + currentObj.getName() + "=" + currentObj.getValue() + '\n');//Ajoute le pm| puis écrit le paramètre dans le fichier.
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
  }
}
