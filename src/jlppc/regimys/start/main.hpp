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
#define UNS using namespace std;
#define toStr(toStrP) #toStrP

#define FOR_EACH(tabType, tabName, sizeTab, acolade) for(unsigned int itor = 0; itor < (sizeTab); itor++) acolade \
tabType* objActuel = NULL;\
objActuel = &(tabName[itor]);\

#define VERS_DEV
#define PRINT_TICKS "[T = " << SDL_GetTicks() << "] - "



/**Le log principal*/
extern std::ofstream rlog;
/**Le log d'erreur*/
extern std::ofstream rerrLog;
/**Chemin vers la save des params*/
extern std::string optSave;
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
extern bool update;
#ifdef VERS_DEV
extern bool devUpdate;
#endif // VERS_DEV
void main();
//->Useless
extern long startTime;
extern std::string sep;
extern bool reboot;

}
/**
Methode permettant de demmarer le jeu
*/
int main(int argc, char *argv[]);


#endif // MAIN_HPP
