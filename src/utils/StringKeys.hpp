/*
StringKeys.hpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef STRINGKEYS_HPP
#define STRINGKEYS_HPP

#include <SFML/System/String.hpp>
#include <iostream>
#include <queue>
#include <vector>

#include "defines.hpp"

namespace Utils {
    //TODO : Make this a class
    namespace StringKeys {
        extern std::vector<std::string> keys;
        extern std::vector<sf::String> strings;

        /**
	 * Return the characted string associated with the key.
	 * @param key
	 */
        sf::String &get(std::string key);

        /**
     * Load the key file and initialize the keys list.
     * @param file
     * @return `true` if everything is ok; `false` if there is an error.
     */
        bool initialize(const std::string &file);

        /**
	 * Split a character string and returns the part corresponding to the given index. Deprecated, use the function returning directly a vector.
	 * @param str The string to split
	 * @param splitter The character used as the limit between the different parts
	 * @param part The index to return
	 */
        OP_DEPRECATED sf::String split(sf::String const &str, char const &splitter, int const &part);

        /**
	 * Split a character string and returns an array.
	 * @param str The string to split
	 * @param splitter The character used as the limit between the different parts
	 */
        std::vector<sf::String> split(sf::String const &str, char const &splitter);

        /**
	 * Converts a sf::String to a std::string without encoding problems.
	 * @param str The sf::String to convert
	 */
        std::string sfStringtoStdString(sf::String const &str);

        /**
	 * Returns the string associated with the key in std::string format.
	 * @param key
	 */
        std::string getStd(std::string const &key);

        /**
	 * Count the number of instances of toSearch into str.
	 * @param str
	 * @param toSearch
	 */
        int countInstances(sf::String const &str, char const &toSearch);

        /*
	 * Splits a string into different strings according to the fixed limit of size while respecting the words.
         * Special characters used : | to make a new line manually, $ to go to the next dialog manually
	 * @param str The string to cut
	 * @param limit The character limit, 29 by default to fit in a standard OpMon dialog box.
         */
        std::queue<sf::String> autoNewLine(sf::String str, unsigned int limit = 29);

    } // namespace StringKeys
} // namespace Utils

#endif // STRINGKEYS_HPP
