#include "main.hpp"

#if !defined(__cplusplus)
#error Mais quel crétin! Il est en C++ ce programme!
#endif

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../objects/item/Item.hpp"
#include "../objects/item/itemInclude.hxx"
#include "../playercore/Player.hpp"
#include "../playercore/Equipe.hpp"
#include "../evolution/evolutionInclude.hxx"
#include "../../utils/Class.hpp"
#include "../../utils/File.hpp"
#include "Initializer.hpp"
#include "StringKeys.hpp"
#include "../gui/MainFrame.hpp"
#include "../save/OptionsSave.hpp"

//#define DEBUG
UNS

#ifdef _WIN32
ofstream rlog("logs\\log.txt");
ofstream rerrLog("logs\\errLog.txt");
#else
#define UNIX
ofstream rlog("logs/log.txt");
ofstream rerrLog("logs/errLog.txt");
#endif // WINDOWS

string optSave("optSave.oparams");


namespace Main {

ostringstream oss;
bool connected = false;
string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Brahim"};
float version = 0.09;
int sousVers = 0;
string versionS;
extern Player joueur;
#ifdef _WIN32
string sep = "\\";
#else
string sep = "/";
#endif
bool reboot = false;

int starts() {

    if (!rlog) {
        cout << "Erreur d'initialisation du log" << endl;

    }
    if (!rerrLog) {
        cout << "Erreur d'ouverture du log d'erreur" << endl;

    }
    if(!rerrLog && !rlog) {
        system("mkdir logs");
        exit(-1);
    }

    OptionsSave::initParams(optSave);
    if(!OptionsSave::checkParam("lang")){
        OptionsSave::addParam("lang", "eng");
    }
    rlog << PRINT_TICKS << "Initialisation du log terminée." << endl;
    Initializer::init();

    MainFrame::open();

    return quit(0);
}

}

void gererErreur(string errorName, bool fatal) {
    rerrLog << "Erreur : " << errorName << endl;
    if (fatal) {
        rerrLog << "Erreur fatale." << endl;
        rlog << PRINT_TICKS << "Crash." << endl;
        quit(1);
    }
}

int quit(int returne) {
    if (MainFrame::init) {
        TTF_Quit();
        atexit(IMG_Quit);
        SDL_Quit();
    }
    for (unsigned int i = 0; i < OP_NUMBER; i++) {
        if(Initializer::listeOp[i] != NULL) {
            delete(Initializer::listeOp[i]);
        }

    }
    OptionsSave::saveParams(optSave);
    rlog << PRINT_TICKS << "Fermeture du jeu. Return " << returne << endl;
    rlog.close();
    rerrLog.close();


#ifdef DEBUG
    system("pause");
#endif // DEBUG
    if(Main::reboot){
        #ifdef _WIN32
            system(".\\OpMon.exe");
        #else
            system("./OpMon");
        #endif
    }
    exit(returne);
    return returne;
}

#include "../objects/Attaques.hpp"
#include "../save/Save.hpp"
int main(int argc, char *argv[]) {

    Main::oss << "Alpha " << Main::version << "." << Main::sousVers;
    Main::versionS = Main::oss.str();
    if(argc >= 2){
        FOR_EACH(char*, argv, argc, {)
            string str = string(*objActuel);
            if(str == "--version"){
                cout << "OpMon Regimys version " << Main::versionS << endl;
                exit(0);
            }else if(str == "--opt"){
                if(itor + 1 == argc){
                    exit(2);
                }else{
                    optSave = string(argv[itor + 1]);
                }
            }
        }
    }
    return Main::starts();
}
