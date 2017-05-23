#include "StringKeys.hpp"
#include "main.hpp"
#include <cstdio>
UNS

namespace StringKeys {
vector<string> keys = vector<string>();
vector<string> strings = vector<string>();

void initialize(string keysFileS) {
    //Ouverture du fichier de cl�es, initialisation des vectors
    ifstream keysFile(keysFileS.c_str());
    keys = vector<string>();
    strings = vector<string>();
    rlog << PRINT_TICKS << "Initialisation des cl�es" << endl;
    if (!keysFile) {//Si ouverture du fichier �chou�e.
        gererErreur("Initialisation des cl�es impossible.", true);
    }
    bool fini = false;
    //R�cup�ration des cl�es
    while (!fini) {
        string read;
        getline(keysFile, read);
        if (!(read.substr(0, read.size() - (read.size() - 3)) == "key")) {//V�rifie si la ligne lue est correcte
            break;//Sinon arr�te de lire
        }
        //Splittage de la ligne en deux parties
        keys.push_back(split(read, '=', 0));
        strings.push_back(split(read, '=', 1));

    }
}

string get(string key) {
    key = string("key.") + key;//Ajout du pr�fixe key.
    for (unsigned int i = 0; i < keys.size(); i++) {//Scanne les cl�es
        if (keys[i] == key) {
            return strings[i];
        }
    }
    return string("");//Si rien trouv�, retourne une chaine vide.
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

string split(string str, char splitter, int part) {
    int instances = 0;//Compte le nombre d'instances du splitter
    for (unsigned int i = 0; i < str.size(); i++) {//Scanne la chaine pour r�cuperer le nombre d'instances du splitter
        if (str.c_str()[i] == splitter) {
            instances++;
        }
    }
    string toReturn[instances + 1];//Cr�e un tableau contenant tous les splits
    int enCours = 0;
    for (unsigned int i = 0; i < str.size(); i++) {//Parcours la chaine pour la s�parer
        if (str.c_str()[i] == splitter) {
            enCours++;
        } else {
            toReturn[enCours] += str.c_str()[i];
        }
    }
    return toReturn[part];
}

}
