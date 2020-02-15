/*!
 * \file StringKeys.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \date 11/10/17
 * \copyright GNU GPL v3.0 license
 */
#ifndef STRINGKEYS_HPP
#define STRINGKEYS_HPP

#include <SFML/System/String.hpp>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

#include "defines.hpp"

/*! \namespace Utils
 *  \brief Contains different utilities.
 */
namespace Utils {
	/*! \namespace Utils::StringKeys
     *  \brief Contains functions to manage game strings.
     *  \todo Make the namespace into a class.
     */
    namespace StringKeys {
        /*!
         * \brief The array containing the keys.
         * \todo Replace it by one map.
         */
        extern std::vector<std::string> keys;
        /*!
         * \brief The array containing the strings.
         * \todo Repace it by one map.
         */
        extern std::vector<sf::String> strings;

        /*!
         * \return The character string associated with the key.
         * \param key The key corresponding to the wanted string.
         */
        sf::String &get(std::string key);

        /*!
         * \brief Loads the file containing the keys and initializes the list of them.
         * \param file The file to load, containing the keys.
         * \return `true` if everything is ok; `false` if there is an error.
         */
        bool initialize(const std::string &file);

        /*!
         * \brief Splits a character string.
         * \deprecated Use split(sf::String const &str, char const &splitter)
         * \return The part of the string corresponding corresponding to the given index.
         * \param str The string to split.
         * \param splitter The character used as the limit between the different parts.
         * \param part The index to return.
         */
        OP_DEPRECATED sf::String split(sf::String const &str, char const &splitter, int const &part);

        /*!
         * \brief Splits a character string.
         * \return An array containing the different parts of the string.
         * \param str The string to split.
         * \param splitter The character used as the limit between the different parts.
         */
        std::vector<sf::String> split(sf::String const &str, char const &splitter);

        /*!
         * \brief Converts a sf::String to a std::string without encoding problems.
         * \param str The sf::String to convert.
         */
        std::string sfStringtoStdString(sf::String const &str);

        /*!
         * \brief A shortcut for sfStringtoStdString(get(key)).
         * \return The string associated with the key in std::string format.
         * \param key The key corresponding to the wanted string.
         */
        std::string getStd(std::string const &key);

        /**
         * \brief Counts the number of instances of a character into a string.
         * \param str The string in which to search.
         * \param toSearch The character to search for.
         */
        int countInstances(sf::String const &str, char const &toSearch);

        /*!
         * \brief Splits a string into different strings according to the fixed limit of size while respecting the words.
         * \details Special characters used : | to make a new line manually, $ to go to the next dialog manually.
         * \param str The string to cut.
         * \param limit The character limit, 29 by default to fit in a standard OpMon dialog box.
         */
        std::queue<sf::String> autoNewLine(sf::String str, unsigned int limit = 29);

    } // namespace StringKeys
} // namespace Utils

#endif // STRINGKEYS_HPP
