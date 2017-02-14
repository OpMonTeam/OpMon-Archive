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
#include "main.hpp"
#include "../gui/MainFrame.hpp"
#define WINDOWS
using namespace std;

namespace Main{

ostringstream oss;
    int starts();
    bool connected = false;
    string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal", "Brahim"};
    float version = 0.07;
    int sousVers = 0;
    string versionS;
    extern Player joueur;
    extern RFile playerSave;
    extern RFile params;
    #ifdef WINDOWS
    ofstream log("logs\\log.txt");
    ofstream errLog("logs\\errLog.txt");
    #else
    #define UNIX
    ofstream log = ofstream("logs/log.txt");
    ofstream errLog = ofstream("logs/errLog.txt")
    #endif // WINDOWS
#ifdef WINDOWS
    string sep = "\\";
#else
    string sep = "/";
#endif

int starts(){
       if(!log){
            cout << "Erreur d'initialisation du log" << endl;
           exit(-1);
       }
       if(!errLog){
           cout << "Erreur d'ouverture du log d'erreur" << endl;
            exit(-2);
       }

       MainFrame::open();

       return quit(0);
   }

}

void gererErreur(string errorName, bool fatal){
    Main::errLog << "Erreur : " << errorName << endl;
    if(fatal){
        Main::errLog << "Erreur fatale." << endl;
        Main::log.close();
        Main::errLog.close();
        quit(1);
    }
}

int quit(int returne){
	if(MainFrame::init){
		SDL_Quit();
	}
	Main::log.close();
    Main::errLog.close();
    exit(returne);
    for(unsigned int i = 0; i < POKE_NUMBER;i++){
        delete(Initializer::listePoke[i]);
    }
    return returne;
}


int main(int argc, char *argv[])
{
    Main::oss << "Alpha" << Main::version << "." << Main::sousVers;
    Main::versionS = Main::oss.str();
    return Main::starts();
}
