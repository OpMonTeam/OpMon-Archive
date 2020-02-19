/*
StringKeys.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "StringKeys.hpp"
#include "../opmon/start/Core.hpp"
#include "./log.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <cstdio>
#include <fstream>
#include <queue>

#define DIALOG_LIMIT 33

namespace Utils {
    namespace StringKeys {
        std::vector<std::string> keys = std::vector<std::string>();
        std::vector<sf::String> strings = std::vector<sf::String>();
        /*!
         * \warning Source-only function.
         */
        sf::String readLine(std::ifstream &input) {
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

        std::string sfStringtoStdString(sf::String const &str) {
            std::string toReelReturn;
            std::basic_string<unsigned char> bs = str.toUtf8();
            for(unsigned int i = 0; i < bs.size(); i++) {
                toReelReturn += bs.at(i);
            }
            return toReelReturn;
        }

        bool initialize(const std::string &keysFileS) {
            std::ifstream keysFile(keysFileS);
            if(!keysFile) {
                OpMon::handleError(std::string("Keys initialization error: ") + keysFileS, true);
            }
            keys = std::vector<std::string>();
            strings = std::vector<sf::String>();
            Log::oplog("Keys initialization");
            if(!keysFile) {
                // Opening of th keys file failed
                return false;
            }
            //Keys recovering
            int itore = 0;
            while(true) {
                sf::String read;
                read = readLine(keysFile);
                if((sfStringtoStdString(read) == "end")) { //Checks if the line is not the ending line
                    break;                                 //Else, stops reading
                }
                //Splits the string in two parts
                if(read[0] != '#' || read[0] != ' ' || !read.isEmpty()) { //Checks if the string is valid
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
            return true;
        }

        /*!
         * \warning Source-only variable.
         */
        sf::String voi;

        sf::String &get(std::string key) {
            key = std::string("key.") + key;                //Adding "key" prefix
            for(unsigned int i = 0; i < keys.size(); i++) { //Scans keys
                if(keys[i] == key) {
                    return strings[i];
                }
            }
            Log::warn("Key " + key + " not found in the keys files.");
            return voi; //If nothing found, returns an empty string
        }

        /*!
         * \warning Source-only function.
         */
        int getIndex(std::string key) {
            key = std::string("key.") + key;                //Adding "key" prefix
            for(unsigned int i = 0; i < keys.size(); i++) { //Scans keys
                if(keys[i] == key) {
                    return i;
                }
            }
            return -1; //If nothing found, returns -1
        }

        sf::String split(sf::String const &str, char const &splitter, int const &part) {
            int instances = 0; //Counts splitter's instances
            for(unsigned int i = 0;
                i < str.toUtf32().size(); i++) { //Scans the string to find the number of splitter's intances
                if((char)str.toUtf32()[i] == splitter) {
                    instances++;
                }
            }
            std::vector<sf::String> toReturn(instances + 1);                      //Create an array containing all the splits
            for(unsigned int i = 0, enCours = 0; i < str.toUtf32().size(); i++) { //Browses the array to split it
                if((char)str.toUtf32()[i] == splitter) {
                    enCours++;
                } else {
                    toReturn[enCours] += str.toUtf32()[i];
                }
            }
            return toReturn[part];
        }
        //TODO : Factorize code to avoid copy-pasted code
        std::vector<sf::String> split(sf::String const &str, char const &splitter) {
            int instances = 0; //Counts splitter's instances
            for(unsigned int i = 0;
                i < str.toUtf32().size(); i++) { //Scans the string to find the number of splitter's intances
                if((char)str.toUtf32()[i] == splitter) {
                    instances++;
                }
            }
            std::vector<sf::String> toReturn(instances + 1);                      //Create an array containing all the splits
            for(unsigned int i = 0, enCours = 0; i < str.toUtf32().size(); i++) { //Browses the array to split it
                if((char)str.toUtf32()[i] == splitter) {
                    enCours++;
                } else {
                    toReturn[enCours] += str.toUtf32()[i];
                }
            }

            return toReturn;
        }

        int countInstances(sf::String const &str, char const &toSearch) {
            int instances = 0;
            for(unsigned int i = 0; i < str.toUtf32().size(); i++) {
                if((char)str.toUtf32()[i] == toSearch) {
                    instances++;
                }
            }
            return instances;
        }

        std::string getStd(std::string const &key) { return sfStringtoStdString(get(key)); }

        std::queue<sf::String> autoNewLine(sf::String str,
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

                if(str[i] != ' ' && str[i] != '|' && str[i] != '$') {
                    currentWord += str[i];
                } else {

                    sf::String currentLine = lines.back() + " " + currentWord;

                    // Calculate the width that a text with the given font and character size would
                    // have with the current string
                    testText.setString(currentLine);
                    float testTextWidth = testText.getLocalBounds().width;

                    // If this width is over the limit, generate a new line
                    if(testTextWidth > limit) {
                        lines.push(sf::String());
                    }

                    lines.back() += currentWord;

                    if(str[i] == ' ') {
                        lines.back() += " ";
                    }

                    currentWord.clear();

                    if(str[i] == '|' || str[i] == '$') {
                        lines.push(sf::String());
                    }
                    while(str[i] == '$' && (lines.size() % 3) != 1) {
                        lines.back() += " ";
                        lines.push(sf::String());
                    }
                }
            }
            if(lines.back().isEmpty()) {
                lines.back() += " ";
            }
            while((lines.size() % 3) != 0) {
                lines.push(sf::String(" "));
            }
            return lines;
        }
    } // namespace StringKeys
} // namespace Utils
