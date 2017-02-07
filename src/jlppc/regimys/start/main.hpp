#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include "../../utils/File.hpp"
#include "../playercore/Player.hpp"
#include <sstream>

#define WINDOWS

using namespace std;
int main();
namespace Main{
    ostringstream oss;
    int main();
    bool connected = false;
    string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolaϯ", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal", "Brahim"};
    float version = 0.07;
    int preNbre = 0;
    bool pre = (preNbre != 0);
    int sousVers = 0;
    bool sousVersIs = (sousVers != 0);
    string versionS;
    Player joueur = Player("temp");
    RFile playerSave = RFile("temp");
    RFile params = RFile("temp");
    ofstream log;
    ofstream errLog;
#ifdef WINDOWS
    string sep = "\\";
#else
    string sep = "/";
#endif
    void gererErreur(string errorName, bool fatal);
    int quit(int retourne);
}

void initStatic(void);

#endif // MAIN_HPP
