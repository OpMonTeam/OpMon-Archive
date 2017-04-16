#include "StringKeys.hpp"
#include "main.hpp"
#include <SDL/SDL.h>
#include <cstdio>
UNS

namespace StringKeys {
#ifdef _WIN32
ifstream keysFile("ressources\\keys\\keys.rkeys");
#else
std::ifstream keysFile("ressources/keys/keys.rkeys");
#endif
vector<string> keys = vector<string>();
vector<string> strings = vector<string>();

void initialize() {
    rlog << "[T = " << SDL_GetTicks() << "] - Initialisation des cl�es" << endl;
    if (!keysFile) {
        gererErreur("Initialisation des cl�es impossible.", true);
    }
    bool fini = false;

    while (!fini) {
        string read;
        getline(keysFile, read);
        rerrLog << read << endl;
        if (!(read.substr(0, read.size() - (read.size() - 3)) == "key")) {
            break;
        }
        keys.push_back(split(read, '=', 0));
        strings.push_back(split(read, '=', 1));

    }
}

string get(string key) {
    key = string("key.") + key;
    for (unsigned int i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
            return strings[i];
        }
    }
    return string("");
}

int getIndex(string key) {
    key = string("key.") + key;
    unsigned int i = 0;
    for (i = 0; i < keys.size(); i++) {
        if (keys[i] == key) {
            return i;
        }
    }
    return -1;
}

string split(string str, char splitter, int part) {
    int instances = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str.c_str()[i] == splitter) {
            instances++;
        }
    }
    string toReturn[instances + 1];
    int enCours = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str.c_str()[i] == splitter) {
            enCours++;
        } else {
            toReturn[enCours] += str.c_str()[i];
        }
    }
    return toReturn[part];
}

}
