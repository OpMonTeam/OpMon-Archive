/*
StringKeys.cpp
Author : Cyrion
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "StringKeys.hpp"
#include "../opmon/model/storage/ResourceLoader.hpp"
#include "./log.hpp"
#include <cstdio>
#include <fstream>

namespace Utils {
    namespace StringKeys {
        std::vector<std::string> keys = std::vector<std::string>();
        std::vector<sf::String> strings = std::vector<sf::String>();

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
            //Ouverture du fichier de clÃ©es, initialisation des vectors
            std::ifstream keysFile;
	    OpMon::Model::ResourceLoader::loadKeysFile(keysFileS.c_str(), keysFile);
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

        sf::String voi;

        sf::String &get(std::string key) {
            key = std::string("key.") + key;                //Adding "key" prefix
            for(unsigned int i = 0; i < keys.size(); i++) { //Scans keys
                if(keys[i] == key) {
                    return strings[i];
                }
            }
            return voi; //If nothing found, returns an empty string
        }

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

    } // namespace StringKeys
} // namespace Utils
