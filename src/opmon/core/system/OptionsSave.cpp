/*
OptionsSave.cpp
Author : Cyrielle
Contributor : Stelyus, BAKFR
File under GNU GPL v3.0 license
*/
#include "OptionsSave.hpp"

#include <stddef.h>
#include <SFML/System/String.hpp>
#include <algorithm>
#include <fstream>
#include <memory>

#include "../../../utils/log.hpp"
#include "../Core.hpp"
#include "src/utils/StringKeys.hpp"

namespace OpMon {
    namespace System {
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
                if(!stream) { //If the file doesn't exist, it is created and opened when saving the parameters
                    std::ofstream strm(file.c_str());
                    strm.close();
                    std::ifstream cpy(file.c_str());
                    handleError("Unable to open the settings file. If the file was only non-existent, it was created. It will therefore be opened correctly when rebooting.", false);
                }
                std::string read;
                int i = 0;
                for(i = 0; i < 100000; i++) { //Prevents from a infinite loop (So, gives a miximum of 10000 parameters, I think there is enough room)
                    getline(stream, read);
                    if(!(read.substr(0, read.size() - (read.size() - 3)) == "pm|")) { //Checks if the pm| prefix is present, if not, stop the loop.
                        break;
                    }
                    std::string noPm = Utils::StringKeys::sfStringtoStdString(Utils::StringKeys::split(read, '|')[1]); //Only takes the part after the pm|
                    std::vector<sf::String> splitted = Utils::StringKeys::split(noPm, '=');
                    Param newParam = Param(Utils::StringKeys::sfStringtoStdString(splitted[0]),
                                           Utils::StringKeys::sfStringtoStdString(splitted[1])); //Splits the string in two parts : the name and the value of the parameter
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
                    toGo += ("pm|" + currentObj.getName() + "=" + currentObj.getValue() +
                             '\n'); //Adds the pm| and writes the parameter into the file
                    stream << toGo;
                    toGo = std::string("");
                }
                stream.close();
            }

            bool checkParam(std::string const &name) {
                return searchParam(name) != -1;
            }

        } // namespace OptionsSave
    }     // namespace System
} // namespace OpMon
