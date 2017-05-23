#include "StringKeys.hpp"
#include "main.hpp"
#include <cstdio>
UNS

namespace StringKeys {
vector<string> keys = vector<string>();
vector<sf::String> strings = vector<sf::String>();

sf::String readLine(ifstream &input){
    string toReturn;
    for(unsigned int i = 0; i < 1024; i++){
        int got = input.get();
        char traded = got;
        if(got == '\n' || got < 31){
            break;
        }else{
            char truc = got;
            toReturn+=truc;
        }
    }
    sf::String toReelReturn;
    toReelReturn = sf::String::fromUtf8(toReturn.begin(), toReturn.end());
    return toReelReturn;
}

std::string sfStringtoStdString(sf::String &str){
    string toReelReturn;
    basic_string<unsigned int> bs = str.toUtf32();
    for(int i = 0; i < bs.size(); i++){
        toReelReturn+=bs.at(i);
    }
    return toReelReturn;
}

void initialize(string keysFileS) {
    //Ouverture du fichier de cl�es, initialisation des vectors
    ifstream keysFile(keysFileS.c_str());
    keys = vector<string>();
    strings = vector<sf::String>();
    rlog << PRINT_TICKS << "Initialisation des cl�es" << endl;
    if (!keysFile) {//Si ouverture du fichier �chou�e.
        gererErreur("Initialisation des cl�es impossible.", true);
    }
    bool fini = false;
    //R�cup�ration des cl�es
    while (!fini) {
        sf::String read = readLine(keysFile);
        if (!(read.toUtf32().substr(0, read.toUtf32().size() - (read.toUtf32().size() - 3)) == sf::String("key"))) {//V�rifie si la ligne lue est correcte
            break;//Sinon arr�te de lire
        }
        //Splittage de la ligne en deux parties
        keys.push_back(split(read, '=', 0));
        strings.push_back(split(read, '=', 1));

    }
}

sf::String& get(string key) {
    key = string("key.") + key;//Ajout du pr�fixe key.
    for (unsigned int i = 0; i < keys.size(); i++) {//Scanne les cl�es
        if (keys[i] == key) {
            return strings[i];
        }
    }
    sf::String voi = sf::String("");
    return voi;//Si rien trouv�, retourne une chaine vide.
}

int getIndex(string key) {
    key = string("key.") + key;//Ajout du pr�fixe key.
    unsigned int i = 0;
    for (i = 0; i < keys.size(); i++) {//Scanne les cl�es
        if (keys[i] == key) {
            return i;
        }
    }
    return -1;//Si rien trouv�, retourne -1
}

sf::String split(sf::String str, char splitter, int part) {
    int instances = 0;//Compte le nombre d'instances du splitter
    for (unsigned int i = 0; i < str.toUtf32().size(); i++) {//Scanne la chaine pour r�cuperer le nombre d'instances du splitter
        if (str.toUtf32()[i] == splitter) {
            instances++;
        }
    }
    sf::String toReturn[instances + 1];//Cr�e un tableau contenant tous les splits
    int enCours = 0;
    for (unsigned int i = 0; i < str.toUtf32().size(); i++) {//Parcours la chaine pour la s�parer
        if (str.toUtf32()[i] == splitter) {
            enCours++;
        } else {
            toReturn[enCours] += str.toUtf32()[i];
        }
    }
    return toReturn[part];
}

}
