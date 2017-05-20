#include "StringKeys.hpp"
#include "main.hpp"
#include <cstdio>
UNS

namespace StringKeys {
vector<string> keys = vector<string>();
vector<string> strings = vector<string>();

void initialize(string keysFileS) {
    //Ouverture du fichier de clées, initialisation des vectors
    ifstream keysFile(keysFileS.c_str());
    keys = vector<string>();
    strings = vector<string>();
    rlog << PRINT_TICKS << "Initialisation des clées" << endl;
    if (!keysFile) {//Si ouverture du fichier échouée.
        gererErreur("Initialisation des clées impossible.", true);
    }
    bool fini = false;
    //Récupération des clées
    while (!fini) {
        string read;
        getline(keysFile, read);
        if (!(read.substr(0, read.size() - (read.size() - 3)) == "key")) {//Vérifie si la ligne lue est correcte
            break;//Sinon arrête de lire
        }
        //Splittage de la ligne en deux parties
        keys.push_back(split(read, '=', 0));
        strings.push_back(split(read, '=', 1));

    }
}

string get(string key) {
    key = string("key.") + key;//Ajout du préfixe key.
    for (unsigned int i = 0; i < keys.size(); i++) {//Scanne les clées
        if (keys[i] == key) {
            return strings[i];
        }
    }
    return string("");//Si rien trouvé, retourne une chaine vide.
}

int getIndex(string key) {
    key = string("key.") + key;//Ajout du préfixe key.
    unsigned int i = 0;
    for (i = 0; i < keys.size(); i++) {//Scanne les clées
        if (keys[i] == key) {
            return i;
        }
    }
    return -1;//Si rien trouvé, retourne -1
}

string split(string str, char splitter, int part) {
    int instances = 0;//Compte le nombre d'instances du splitter
    for (unsigned int i = 0; i < str.size(); i++) {//Scanne la chaine pour récuperer le nombre d'instances du splitter
        if (str.c_str()[i] == splitter) {
            instances++;
        }
    }
    string toReturn[instances + 1];//Crée un tableau contenant tous les splits
    int enCours = 0;
    for (unsigned int i = 0; i < str.size(); i++) {//Parcours la chaine pour la séparer
        if (str.c_str()[i] == splitter) {
            enCours++;
        } else {
            toReturn[enCours] += str.c_str()[i];
        }
    }
    return toReturn[part];
}

}
