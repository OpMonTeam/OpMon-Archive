#include "StringKeys.hpp"
#include "main.hpp"
#include <cstdio>
UNS

namespace StringKeys {
vector<string> keys = vector<string>();
vector<sf::String> strings = vector<sf::String>();

sf::String readLine(ifstream &input) {
    string toReturn;
    for(unsigned int i = 0; i < 1024; i++) {
        int got = input.get();
        // char traded = got;
        if(got == '\n' || got < 31) {
            break;
        } else {
            char truc = got;
            toReturn+=truc;
        }
    }
    sf::String toReelReturn;
    toReelReturn = sf::String::fromUtf8(toReturn.begin(), toReturn.end());
    return toReelReturn;
}

std::string sfStringtoStdString(sf::String const &str) {
    string toReelReturn;
    basic_string<unsigned int> bs = str.toUtf32();
    for(unsigned int i = 0; i < bs.size(); i++) {
        toReelReturn+=bs.at(i);
    }
    return toReelReturn;
}

void initialize(string keysFileS) {
    //Ouverture du fichier de clées, initialisation des vectors
    keysFileS = getPath(keysFileS);
    ifstream keysFile(keysFileS.c_str());
    keys = vector<string>();
    strings = vector<sf::String>();
    oplog("Keys initialization");
    if (!keysFile) {//Si ouverture du fichier échouée.
        handleError("Keys initialization error", true);
    }
    //Récupération des clées
    while (true) {
        sf::String read;
        read = readLine(keysFile);
        if (!(read.toUtf32().substr(0, read.toUtf32().size() - (read.toUtf32().size() - 3)) == sf::String("key"))) {//Vérifie si la ligne lue est correcte
            break;//Sinon arrête de lire
        }
        //Splittage de la ligne en deux parties
        keys.push_back(sfStringtoStdString(split(read, '=', 0)));
        strings.push_back(split(read, '=', 1));

    }
}
sf::String voi;
sf::String &get(string key) {
    key = string("key.") + key;//Ajout du préfixe key.
    for (unsigned int i = 0; i < keys.size(); i++) {//Scanne les clées
        if (keys[i] == key) {
            return strings[i];
        }
    }
    return voi;//Si rien trouvé, retourne une chaine vide.
}

int getIndex(string key) {
    key = string("key.") + key;//Ajout du préfixe key.
    for (unsigned int i = 0; i < keys.size(); i++) {//Scanne les clées
        if (keys[i] == key) {
            return i;
        }
    }
    return -1;//Si rien trouvé, retourne -1
}

sf::String split(sf::String const& str, char const& splitter, int const& part) {
    int instances = 0;//Compte le nombre d'instances du splitter
    for (unsigned int i = 0; i < str.toUtf32().size(); i++) {//Scanne la chaine pour récuperer le nombre d'instances du splitter
        if ((char) str.toUtf32()[i] == splitter) {
            instances++;
        }
    }
    sf::String toReturn[instances + 1];//Crée un tableau contenant tous les splits
    for (unsigned int i = 0, enCours = 0; i < str.toUtf32().size(); i++) {//Parcours la chaine pour la séparer
        if ((char) str.toUtf32()[i] == splitter) {
            enCours++;
        } else {
            toReturn[enCours] += str.toUtf32()[i];
        }
    }
    return toReturn[part];
}

std::vector<sf::String> split(sf::String const& str, char const& splitter) {
    int instances = 0;//Compte le nombre d'instances du splitter
    for (unsigned int i = 0; i < str.toUtf32().size(); i++) {//Scanne la chaine pour récuperer le nombre d'instances du splitter
        if ((char) str.toUtf32()[i] == splitter) {
            instances++;
        }
    }
    std::vector<sf::String> toReturn(instances + 1);//Crée un tableau contenant tous les splits
    for (unsigned int i = 0, enCours = 0; i < str.toUtf32().size(); i++) {//Parcours la chaine pour la séparer
        if ((char) str.toUtf32()[i] == splitter) {
            enCours++;
        } else {
            toReturn[enCours] += str.toUtf32()[i];
        }
    }
    return toReturn;
}

int countInstances(sf::String const& str, char const& toSearch) {
    int instances = 0;
    for (unsigned int i = 0; i < str.toUtf32().size(); i++) {
        if ((char) str.toUtf32()[i] == toSearch) {
            instances++;
        }
    }
    return instances;
}

}
