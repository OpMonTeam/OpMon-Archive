#include "OptionsSave.hpp"
#include "../../../utils/log.hpp"
#include "../../start/Core.hpp"

  namespace OpMon {
    namespace Model {
        namespace OptionsSave {

            int searchParam(std::string const &name);

            Param::Param(std::string name, std::string value) {
                this->paramName = name;
                this->value = value;
            }

            std::string Param::getName() const {
                return this->paramName;
            }

            std::string Param::getValue() const {
                return this->value;
            }

            void Param::setValue(std::string value) {
                this->value = value;
            }

            std::vector<Param> paramList;

            Param getParam(std::string const &name) {
                if(searchParam(name) != -1) {
                    return paramList[searchParam(name)];
                } else {
                    return Param("NULL", "NULL");
                }
            }

            void addOrModifParam(std::string const &name, std::string const &value) {
                if(searchParam(name) == -1) { //Add Param (No Exist)
                    paramList.push_back(Param(name, value));
                } else { //Param Exist
                    paramList[searchParam(name)].setValue(value);
                }
            }

            Param deleteParam(std::string const &name) {
                if(searchParam(name) == -1) {
                    return Param("NULL", "NULL");
                } else {
                    Param toReturn = paramList[searchParam(name)];
                    paramList.erase(paramList.begin() + searchParam(name));
                    return toReturn;
                }
            }

            int searchParam(std::string const &name) {
                for(size_t i = 0; i < paramList.size(); ++i) {
                    if(paramList[i].getName() == name) {
                        return i;
                    }
                }
                return -1;
            }

            void initParams(std::string const &file) {
                Utils::Log::oplog("Settings loading");
                std::ifstream stream(file.c_str());
                if(!stream) { //Si le fichier ne peut etre ouvert, il est crée et sera ouvert lors de la sauvegarde.
                    std::ofstream strm(file.c_str());
                    strm.close();
                    std::ifstream cpy(file.c_str());
                    handleError(
                      "Unable to open the settings file. If the file was only non-existent, it was created. It will therefore be opened correctly when rebooting.",
                      false);
                }
                std::string read;
                int i = 0;
                for(i = 0; i <
                           100000;
                    i++) { //Empecher une boucle infinie (Donne du coup un maximum de 100000 paramètres, y'a de quoi faire.)
                    getline(stream, read);
                    if(!(read.substr(0, read.size() - (read.size() - 3)) ==
                         "pm|")) { //Vérifie si le préfixe pm| est bien présent, sinon arrête la boucle.
                        break;
                    }
                    std::string noPm = Utils::StringKeys::sfStringtoStdString(Utils::StringKeys::split(read, '|')[1]); //Ne prend que la partie après le pm|
                    std::vector<sf::String> splitted = Utils::StringKeys::split(noPm, '=');
                    Param newParam = Param(Utils::StringKeys::sfStringtoStdString(splitted[0]),
                                           Utils::StringKeys::sfStringtoStdString(splitted[1])); //Splitte ensuite en deux parties, le name et la valeur du paramètre.
                    if(!checkParam(newParam.getName())) {
                        paramList.push_back(newParam);
                    }
                }
                if(i >= 100000) {
                    handleError("initParams : Endless loop stopped", true);
                }

                stream.close();
            }

            void saveParams(std::string const &file) {
                std::ofstream stream(file.c_str());
                std::string toGo;
                for(auto &currentObj : paramList) {
                    //cout << objActuel->getName() << endl;
                    toGo += ("pm|" + currentObj.getName() + "=" + currentObj.getValue() +
                             '\n'); //Ajoute le pm| puis écrit le paramètre dans le fichier.
                    //cout << toGo;
                    stream << toGo;
                    toGo = std::string("");
                }
                stream.close();
            }

            bool checkParam(std::string const &name) {
                return searchParam(name) != -1;
            }

        } // namespace OptionsSave
    }     // namespace Model
}
