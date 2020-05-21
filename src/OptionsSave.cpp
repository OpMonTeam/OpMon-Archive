/*
  OptionsSave.cpp
  Author : Cyrielle
  Contributor : Stelyus, BAKFR
  File under GNU GPL v3.0 license
*/
#include "OptionsSave.hpp"

#include <cstddef>
#include <SFML/System/String.hpp>
#include <algorithm>
#include <fstream>
#include <memory>

#include "log.hpp"
#include "StringKeys.hpp"

namespace Utils {

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

    Param OptionsSave::getParam(std::string const &name) {
        if(searchParam(name) != -1) {
            return paramList[searchParam(name)];
        } else {
            return Param("NULL", "NULL");
        }
    }

    void OptionsSave::addOrModifParam(std::string const &name, std::string const &value) {
        if(searchParam(name) == -1) { //Add Param (No Exist)
            paramList.push_back(Param(name, value));
        } else { //Param Exist
            paramList[searchParam(name)].setValue(value);
        }
    }

    Param OptionsSave::deleteParam(std::string const &name) {
        if(searchParam(name) == -1) {
            return Param("NULL", "NULL");
        } else {
            Param toReturn = paramList[searchParam(name)];
            paramList.erase(paramList.begin() + searchParam(name));
            return toReturn;
        }
    }

    int OptionsSave::searchParam(std::string const &name) {
        for(size_t i = 0; i < paramList.size(); ++i) {
            if(paramList[i].getName() == name) {
                return i;
            }
        }
        return -1;
    }

    OptionsSave::OptionsSave(std::string const &file)
    	: file(file) {
        Utils::Log::oplog("Loading of the settings.");
        std::ifstream stream(file.c_str());
        if(!stream) { //If the file doesn't exist, it is created and opened when saving the parameters
            std::ofstream strm(file.c_str());
            strm.close();
            std::ifstream cpy(file.c_str());
            Log::warn("Unable to open the settings file. If the file was only non-existent, it was created. It will therefore be opened correctly when rebooting.");
        }
        std::string read;
        int i = 0;
        while(!stream.eof()) {
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

        stream.close();
    }

    void OptionsSave::saveParams() {
        std::ofstream stream(file.c_str());
        std::string toGo;
        for(Param &currentObj : paramList) {
            toGo += ("pm|" + currentObj.getName() + "=" + currentObj.getValue() +
                     '\n'); //Adds the pm| and writes the parameter into the file
            stream << toGo;
            toGo = std::string("");
        }
        stream.close();
    }

    bool OptionsSave::checkParam(std::string const &name) {
        return searchParam(name) != -1;
    }

    OptionsSave::~OptionsSave(){
    	saveParams();
    }

} // namespace Utils
