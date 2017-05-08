#include "main.hpp"

#if !defined(__cplusplus)
#error Mais quel cr�tin! Il est en C++ ce programme!
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
    //Chargement des fichiers du log
    if (!rlog) {
        cout << "Erreur d'initialisation du log" << endl;

    }
    if (!rerrLog) {
        cout << "Erreur d'ouverture du log d'erreur" << endl;

    }
    if(!rerrLog && !rlog) {//Verification de leur ouverture
        system("mkdir logs");
        exit(-1);
    }
    //Chargement des param�tres
    OptionsSave::initParams(optSave);
    if(!OptionsSave::checkParam("lang")){//Si le param�tre "lang" n'existe pas
        OptionsSave::addParam("lang", "eng");
    }
    rlog << PRINT_TICKS << "Initialisation du log termin�e." << endl;
    //Initialisation des objets
    Initializer::init();
    //Ouverture de la fenetre
    MainFrame::open();

    return quit(0);
}

}

void gererErreur(string errorName, bool fatal) {
    rerrLog << "Erreur : " << errorName << endl;
    if (fatal) {//Si besoin d'un crash
        rerrLog << "Erreur fatale." << endl;
        rlog << PRINT_TICKS << "Crash." << endl;
        quit(1);
    }
}

int quit(int returne) {
    if (MainFrame::init) {//Fermeture de SDL
        Mix_CloseAudio();
        Mix_Quit();
        TTF_Quit();
        atexit(IMG_Quit);
        SDL_Quit();
    }
    for (unsigned int i = 0; i < OP_NUMBER; i++) {//Suppression des OpMon
        if(Initializer::listeOp[i] != NULL) {
            delete(Initializer::listeOp[i]);
        }

    }
    OptionsSave::saveParams(optSave);//Sauvegarde des param�tres
    rlog << PRINT_TICKS << "Fermeture du jeu. Return " << returne << endl;
    //Fermeture des log
    rlog.close();
    rerrLog.close();


#ifdef DEBUG//Outdated : Unused
    system("pause");
#endif // DEBUG
    if(Main::reboot){//reboot si indiqu�
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
    //Cr�ation de la chaine de caract�re de version
    Main::oss << "Alpha " << Main::version << "." << Main::sousVers;
    Main::versionS = Main::oss.str();
    //Traitement des arguments
    if(argc >= 2){
        FOR_EACH(char*, argv, argc, {)
            string str = string(*objActuel);
            if(str == "--version"){//Affichage de la version
                cout << "OpMon Regimys version " << Main::versionS << endl;
                exit(0);
            }else if(str == "--opt"){//Changement de l'emplacement du fichier de sauvegarde des param�tres
                if(itor + 1 == argc){//Si pas d'arguments a l'option --opt
                    exit(2);
                }else{
                    optSave = string(argv[itor + 1]);
                }
            }
        }
    }
    return Main::starts();//Lancement du jeu
}
