/*
main.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient des fonctions necessaires au programme
*/
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include "../../utils/File.hpp"
#include "../playercore/Player.hpp"
#include <sstream>
#include <SFML/System.hpp>
#define UNS using namespace std;
#define toStr(toStrP) #toStrP

#define FOR_EACH(tabType, tabName, sizeTab, acolade) for(unsigned int itor = 0; itor < (sizeTab); itor++) acolade \
        tabType* objActuel = NULL;\
    objActuel = &(tabName[itor]);\

#define LOCAL_TEST

#define GET_TICKS ticks.getElapsedTime().asMilliseconds()
#ifndef _WIN32
#ifdef LOCAL_TEST
#define RESSOURCES_PATH std::string("ressources/")
#define LOG_PATH std::string("logs/")
#define SAVE_PATH std::string("saves/")
#else
#define RESSOURCES_PATH std::string("/usr/share/OpMon/ressources/")
#define LOG_PATH std::string("/usr/share/OpMon/logs/")
#define SAVE_PATH std::string("/usr/share/OpMon/saves/")
#endif
#else
#define RESSOURCES_PATH std::string("ressources\\")
#define LOG_PATH std::string("logs\\")
#define SAVE_PATH std::string("saves\\")
#endif // _WIN32
#define PRINT_TICKS "[T = " << ticks.getElapsedTime().asMilliseconds() << "] - "
/**Le log principal*/
extern std::ofstream rlog;
/**Le log d'erreur*/
extern std::ofstream rerrLog;
/**Chemin vers la save des params*/
extern std::string optSave;

extern sf::Clock ticks;

//#define TEST


/**
Methode a appeler lorsqu'une erreur peut intervenir dans le programme
fatal : si true, éteint le programme
*/
void gererErreur(std::string errorName, bool fatal);
/**
Methode qui quitte le programme en fermant toutes les ressources
retourne : ce que le programme retournera
*/
int quit(int retourne);
/**
Namespace contenant des variables utiles au fonctionnement du jeu
*/
namespace Main {
    void main();
//->Useless
    extern long startTime;
  //  extern std::string sep;
  // extern bool reboot;
    extern Player player;

}

int main(int argc, char *argv[]);

typedef unsigned int p_int;


#endif // MAIN_HPP
