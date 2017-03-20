/*
main.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
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

#define PRINT_TICKS "[T = " << SDL_GetTicks() << "] - "
/**Le log principal*/
extern std::ofstream rlog;
/**Le log d'erreur*/
extern std::ofstream rerrLog;
/**
Methode a appeler lorsqu'une erreur peut intervenir dans le programme
fatal : si true, �teint le programme
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

}
/**
Methode permettant de demmarer le jeu
*/
int main(int argc, char *argv[]);


#endif // MAIN_HPP
