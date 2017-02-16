#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../objects/item/Item.hpp"
#include "../playercore/Player.hpp"
#include "../playercore/Equipe.hpp"
#include "../evolution/evolutionInclude.hxx"
#include "../../utils/Class.hpp"
#include "../../utils/File.hpp"
#include "../objects/item/itemInclude.hxx"
#include <string>
#include "Initializer.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "main.hpp"
#include "../gui/MainFrame.hpp"
#include "StringKeys.hpp"
#include <ctime>
#define WINDOWS
using namespace std;

 #ifdef WINDOWS
        ofstream rlog("logs\\log.txt");
        ofstream rerrLog("logs\\errLog.txt");
    #else
        #define UNIX
        ofstream rlog = ofstream("logs/log.txt");
        ofstream rerrLog = ofstream("logs/errLog.txt")
    #endif // WINDOWS
namespace Main{

ostringstream oss;
    int starts();
    bool connected = false;
    string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal", "Brahim"};
    float version = 0.07;
    int sousVers = 1;
    string versionS;
    extern Player joueur;
    extern RFile playerSave;
    extern RFile params;
    long startTime = time(NULL);

#ifdef WINDOWS
    string sep = "\\";
#else
    string sep = "/";
#endif

int starts(){
       if(!rlog){
            cout << "Erreur d'initialisation du log" << endl;
           exit(-1);
       }
       if(!rerrLog){
           cout << "Erreur d'ouverture du log d'erreur" << endl;
            exit(-2);
       }
        startTime = time(NULL);
       rlog << "[T = " << time(NULL) - startTime << "] - Initialisation du log terminée." << endl;
        StringKeys::initialize();
       MainFrame::open();

       return quit(0);
   }

}

void gererErreur(string errorName, bool fatal){
    rerrLog << "Erreur : " << errorName << endl;
    if(fatal){
        rerrLog << "Erreur fatale." << endl;
        rlog.close();
        rerrLog.close();
        quit(1);
    }
}

int quit(int returne){
	if(MainFrame::init){
		SDL_Quit();
		atexit(IMG_Quit);
	}
	rlog << "[T = " << time(NULL) - Main::startTime << "] - Fermeture du jeu." << endl;
	rlog.close();
    rerrLog.close();
    exit(returne);
    for(unsigned int i = 0; i < POKE_NUMBER;i++){
        delete(Initializer::listePoke[i]);
    }
    return returne;
}


int main(int argc, char *argv[])
{

    Main::oss << "Alpha " << Main::version << "." << Main::sousVers;
    Main::versionS = Main::oss.str();
    if(argc >= 2){
            string str = argv[1];
        if(str == "--version"){
            cout << "Pokémon Regimys version " << Main::versionS << endl;
            exit(0);
        }else{
            cout << "Arguments ignorés, passage a la suite." << endl;
        }
    }
    return Main::starts();
}
