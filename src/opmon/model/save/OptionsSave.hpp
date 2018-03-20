/*
OptionsSave.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contains the OptionsSave namespace
*/
#ifndef OPTIONSSAVE_HPP
#define OPTIONSSAVE_HPP

#include "../../../utils/StringKeys.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/**
   Macros to explicit the use of addOrModifParam
*/
#define addParam addOrModifParam
#define modifyParam addOrModifParam

namespace OpMon {
    namespace Model {
        /**
       OptionsSave contains the functions used to save the parameters.
    */
        namespace OptionsSave {
            /**
	 Class defining a parameter
      */
            class Param {
              private:
                std::string paramName;
                std::string value;

              public:
                Param(std::string name, std::string value);
                std::string getName() const;
                std::string getValue() const;
                void setValue(std::string value);
            };

            extern std::vector<Param> paramList;

            Param getParam(std::string const &name);

            void addOrModifParam(std::string const &name, std::string const &value);

            Param deleteParam(std::string const &name);

            //.CPP ONLY :
            //int searchParam(string name);

            void saveParams(std::string const &file);

            void initParams(std::string const &file);

            bool checkParam(std::string const &name);

        } // namespace OptionsSave
    }     // namespace Model
} // namespace OpMon
#endif // OPTIONSSAVE_HPP
