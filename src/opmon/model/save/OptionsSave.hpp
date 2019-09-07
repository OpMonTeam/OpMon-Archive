/*
OptionsSave.hpp
Author : Cyrielle
Contributor : Navet56
File under GNU GPL v3.0 license
*/
#ifndef OPTIONSSAVE_HPP
#define OPTIONSSAVE_HPP

#include "../../../utils/StringKeys.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

/**
   Macros to explicit the use of addOrModifParam when calling it in the code
*/
#define addParam addOrModifParam
#define modifyParam addOrModifParam

namespace OpMon::Model::OptionsSave {
    /**
				Class defining a parameter
			*/
    class Param {
      private:
        std::string paramName;
        std::string value;

      public:
        Param(std::string name, std::string value);
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::string getValue() const;
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

} // namespace OpMon::Model::OptionsSave
#endif // OPTIONSSAVE_HPP
