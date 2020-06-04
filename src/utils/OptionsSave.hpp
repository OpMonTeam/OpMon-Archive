/*!
 * \file OptionsSave.hpp
 * \authors Cyrielle
 * \authors Navet56
 * \copyright GNU GPL v3.0
 */
#ifndef OPTIONSSAVE_HPP
#define OPTIONSSAVE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "StringKeys.hpp"

/*!
 * \brief Macro used to explicit the use of OptionsSave::addOrModifParam when calling it in the code.
 */
#define addParam addOrModifParam
/*!
 *\brief Macro used to explicit the use of OptionsSave::addOrModifParam when calling it in the code.
 */
#define editParam addOrModifParam

namespace Utils {
    /**
     * \brief Defines a parameter.
     */
    class Param {
      private:
        std::string paramName;
        std::string value;

      public:
        /*!
         * \param name The parameter's name. Alphanumeric characters only.
         * \param value The parameter's value.
         */
        Param(std::string name, std::string value);
        std::string getName() const;
        std::string getValue() const;
        void setValue(std::string value);
    };

    /*!
     *	\brief Contains the functions used to save the parameters.
     *  \todo Save the parameters in JSON.
     */
    class OptionsSave {
      public:
        /*!
         * \returns The parameter with this name in OptionsSave::paramList. Returns an empty parameter if none exists with the given name.
         * \param name The name of the parameter.
         */
        Param getParam(std::string const &name);

        /*!
         * \brief Sets the parameter with the given name to the given value.
         * \details If the parameters doesn't exist yet, it will be created.
         * \param name The name of the parameter.
         * \param value The value to set the parameter to.
         * \todo Change to addOrEditParam
         */
        void addOrModifParam(std::string const &name, std::string const &value);

        /*!
         * \brief Deletes a parameter.
         * \param name The name of the parameter.
         * \returns The deleted parameter. If none exists with this name, returns an empty parameter.
         */
        Param deleteParam(std::string const &name);

        /*!
         * \brief Saves the parameters.
         */
        void saveParams();

        /*!
         * \brief Loads the paramters.
         * \param file The file in which the parameters are stored.
         */
        OptionsSave(std::string const &file);

        /*!
         * \brief Checks if a parameters exists.
         * \param name The name of the parameter.
         * \returns `true` if the parameters exists, `false` otherwise.
         */
        bool checkParam(std::string const &name);

        ~OptionsSave();

      private:
        /*!
         * \brief The list of the different parameters.
         * \todo Change this to an std::list ?
         */
        std::vector<Param> paramList;

        /*!
         * \brief The file used to save the options.
         */
        std::string file;

        int searchParam(std::string const &name);
    };
} // namespace Utils
#endif // OPTIONSSAVE_HPP
