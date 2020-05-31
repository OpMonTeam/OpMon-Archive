/*
  StringKeys.cpp
  Author : Cyrielle
  Contributor : BAKFR
  File under GNU GPL v3.0 license
*/
#include "StringKeys.hpp"

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <algorithm>
#include <cstdio>
#include <ext/alloc_traits.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>

#include "./log.hpp"
#include "exceptions.hpp"

namespace Utils {

    sf::String StringKeys::readLine(std::ifstream &input) {
        std::basic_string<unsigned char> toReturn;
        for(unsigned int i = 0; i < 1024; i++) {
            int got = input.get();
            // char traded = got;
            if(got == '\n' || got < 31) {
                break;
            } else {
                unsigned char truc = got;
                toReturn += truc;
            }
        }
        sf::String toReelReturn;
        toReelReturn = sf::String::fromUtf8(toReturn.begin(), toReturn.end());
        return toReelReturn;
    }

    std::string StringKeys::sfStringtoStdString(sf::String const &str) {
        std::string toReelReturn;
        std::basic_string<unsigned char> bs = str.toUtf8();
        for(unsigned int i = 0; i < bs.size(); i++) {
            toReelReturn += bs.at(i);
        }
        return toReelReturn;
    }

    StringKeys::StringKeys(const std::string &keysFileS) {
        std::ifstream keysFile(keysFileS);
        keys = std::vector<std::string>();
        strings = std::vector<sf::String>();
        Log::oplog("Keys initialization");
        if(!keysFile) {
            throw LoadingException(keysFileS, true);
        }
        // Keys recovering
        int itore = 0;
        while(true) {
            sf::String read;
            read = readLine(keysFile);
            if((sfStringtoStdString(read) ==
                "end")) { // Checks if the line is not the ending line
                break;    // Else, stops reading
            }
            // Splits the string in two parts
            if(read[0] != '#' || read[0] != ' ' ||
               !read.isEmpty()) { // Checks if the string is valid
                std::vector<sf::String> strSplit = split(read, '=');
                if(!strSplit.size() == 0 && strSplit[0] != "") {
                    keys.push_back(strSplit[0]);
                    if(strSplit.size() < 2) {
                        strings.push_back(" ");
                    } else {
                        strings.push_back(sf::String(strSplit[1]));
                        itore++;
                    }
                }
            }
        }
    }

    sf::String &StringKeys::get(std::string key) {
        key = std::string("key.") + key;                // Adding "key" prefix
        for(unsigned int i = 0; i < keys.size(); i++) { // Scans keys
            if(keys[i] == key) {
                return strings[i];
            }
        }
        Log::warn("Key " + key + " not found in the keys files.");
        return strings[getIndex(
            "void")]; // If nothing found, returns the empty string.
    }

    int StringKeys::getIndex(std::string key) {
        key = std::string("key.") + key;                // Adding "key" prefix
        for(unsigned int i = 0; i < keys.size(); i++) { // Scans keys
            if(keys[i] == key) {
                return i;
            }
        }
        return -1; // If nothing found, returns -1
    }

    sf::String StringKeys::split(sf::String const &str, char const &splitter,
                                 int const &part) {
        int instances = 0; // Counts splitter's instances
        for(unsigned int i = 0; i < str.toUtf32().size();
            i++) { // Scans the string to find the number of splitter's intances
            if((char)str.toUtf32()[i] == splitter) {
                instances++;
            }
        }
        std::vector<sf::String> toReturn(
            instances + 1); // Create an array containing all the splits
        for(unsigned int i = 0, enCours = 0; i < str.toUtf32().size();
            i++) { // Browses the array to split it
            if((char)str.toUtf32()[i] == splitter) {
                enCours++;
            } else {
                toReturn[enCours] += str.toUtf32()[i];
            }
        }
        return toReturn[part];
    }
    // TODO : Factorize code to avoid copy-pasted code
    std::vector<sf::String> StringKeys::split(sf::String const &str,
                                              char const &splitter) {
        int instances = 0; // Counts splitter's instances
        for(unsigned int i = 0; i < str.toUtf32().size();
            i++) { // Scans the string to find the number of splitter's intances
            if((char)str.toUtf32()[i] == splitter) {
                instances++;
            }
        }
        std::vector<sf::String> toReturn(
            instances + 1); // Create an array containing all the splits
        for(unsigned int i = 0, enCours = 0; i < str.toUtf32().size();
            i++) { // Browses the array to split it
            if((char)str.toUtf32()[i] == splitter) {
                enCours++;
            } else {
                toReturn[enCours] += str.toUtf32()[i];
            }
        }

        return toReturn;
    }

    int StringKeys::countInstances(sf::String const &str,
                                   char const &toSearch) {
        int instances = 0;
        for(unsigned int i = 0; i < str.toUtf32().size(); i++) {
            if((char)str.toUtf32()[i] == toSearch) {
                instances++;
            }
        }
        return instances;
    }

    std::string StringKeys::getStd(std::string const &key) {
        return sfStringtoStdString(get(key));
    }

    std::queue<sf::String> StringKeys::autoNewLine(sf::String str,
                                                   sf::Font font,
                                                   unsigned int characterSize,
                                                   float limit) {
        sf::String currentWord;
        std::queue<sf::String> lines;
        lines.push(sf::String());

        // Temporary text used to measure the size
        sf::Text testText;
        testText.setFont(font);
        testText.setCharacterSize(characterSize);

        for(unsigned int i = 0; i < str.getSize(); i++) {
            if(str[i] != ' ' && str[i] != '|' && str[i] != '$' &&
               i != (str.getSize() - 1)) {
                currentWord += str[i];
            } else {
                sf::String currentLine = lines.back() + " " + currentWord;

                // Calculate the width that a text with the given font and
                // character size would have with the current string
                testText.setString(currentLine);
                float testTextWidth = testText.getLocalBounds().width;

                // If this width is over the limit, generate a new line
                if(testTextWidth > limit) {
                    lines.push(sf::String());
                }

                if(i == str.getSize() - 1) {
                    currentWord += str[i];
                }

                lines.back() += currentWord;

                if(str[i] == ' ') {
                    lines.back() += " ";
                }

                currentWord.clear();

                if(str[i] == '|' || str[i] == '$') {
                    lines.push(sf::String());
                }
                while(str[i] == '$' && (lines.size() % 2) != 1) {
                    lines.back() += " ";
                    lines.push(sf::String());
                }
            }
        }
        if(lines.back().isEmpty()) {
            lines.back() += " ";
        }
        while((lines.size() % 2) != 0) {
            lines.push(sf::String(" "));
        }
        return lines;
    }
} // namespace Utils
