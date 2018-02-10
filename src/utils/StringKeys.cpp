#include "StringKeys.hpp"
#include "../opmon/model/storage/ResourceLoader.hpp"
#include "./log.hpp"
#include <cstdio>
#include <fstream>

UNS

  namespace Utils {
    namespace StringKeys {
        vector<string> keys = vector<string>();
        vector<sf::String> strings = vector<sf::String>();

        sf::String readLine(ifstream &input) {
            basic_string<unsigned char> toReturn;
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
            string toReelReturn;
            basic_string<unsigned char> bs = str.toUtf8();
            for(unsigned int i = 0; i < bs.size(); i++) {
                toReelReturn += bs.at(i);
            }
            return toReelReturn;
        }

        bool initialize(const string &keysFileS) {
            //Ouverture du fichier de clées, initialisation des vectors
            ifstream keysFile = OpMon::Model::ResourceLoader::loadKeysFile(keysFileS.c_str());
            keys = vector<string>();
            strings = vector<sf::String>();
            Log::oplog("Keys initialization");
            if(!keysFile) {
                // Opening of th keys file failed
                return false;
            }
            //Récupération des clées
            int itore = 0;
            while(true) {
                sf::String read;
                read = readLine(keysFile);
                if((sfStringtoStdString(read) == "end")) { //Vérifie si la ligne lue est correcte
                    break;                                 //Sinon arrête de lire
                }
                //Splittage de la ligne en deux parties
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

        sf::String &get(string key) {
            key = string("key.") + key;                     //Ajout du préfixe key.
            for(unsigned int i = 0; i < keys.size(); i++) { //Scanne les clées
                if(keys[i] == key) {
                    return strings[i];
                }
            }
            return voi; //Si rien trouvé, retourne une chaine vide.
        }

        int getIndex(string key) {
            key = string("key.") + key;                     //Ajout du préfixe key.
            for(unsigned int i = 0; i < keys.size(); i++) { //Scanne les clées
                if(keys[i] == key) {
                    return i;
                }
            }
            return -1; //Si rien trouvé, retourne -1
        }

        sf::String split(sf::String const &str, char const &splitter, int const &part) {
            int instances = 0; //Compte le nombre d'instances du splitter
            for(unsigned int i = 0;
                i < str.toUtf32().size(); i++) { //Scanne la chaine pour récuperer le nombre d'instances du splitter
                if((char)str.toUtf32()[i] == splitter) {
                    instances++;
                }
            }
            std::vector<sf::String> toReturn(instances + 1);                      //Crée un tableau contenant tous les splits
            for(unsigned int i = 0, enCours = 0; i < str.toUtf32().size(); i++) { //Parcours la chaine pour la séparer
                if((char)str.toUtf32()[i] == splitter) {
                    enCours++;
                } else {
                    toReturn[enCours] += str.toUtf32()[i];
                }
            }
            return toReturn[part];
        }

        std::vector<sf::String> split(sf::String const &str, char const &splitter) {
            int instances = 0; //Compte le nombre d'instances du splitter
            for(unsigned int i = 0;
                i < str.toUtf32().size(); i++) { //Scanne la chaine pour récuperer le nombre d'instances du splitter
                if((char)str.toUtf32()[i] == splitter) {
                    instances++;
                }
            }
            std::vector<sf::String> toReturn(instances + 1);                      //Crée un tableau contenant tous les splits
            for(unsigned int i = 0, enCours = 0; i < str.toUtf32().size(); i++) { //Parcours la chaine pour la séparer
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
}