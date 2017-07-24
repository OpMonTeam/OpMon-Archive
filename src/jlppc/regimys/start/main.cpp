#include "main.hpp"

#ifndef __cplusplus
#error Mais quel crétin! Il est en C++ ce programme!
#endif

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>

#include "../objects/item/Item.hpp"
#include "../objects/item/itemInclude.hxx"
#include "../playercore/Player.hpp"
#include "../playercore/Equipe.hpp"
#include "../evolution/evolutionInclude.hxx"
#include "../../utils/Class.hpp"
#include "../../utils/File.hpp"
#include "Initializer.hpp"
#include "StringKeys.hpp"
#include "../newGui/MainFrame.hpp"
#include "../save/OptionsSave.hpp"
#include "../save/InternalFiles.hpp"

//#define DEBUG
UNS

ofstream rlog(LOG_PATH + "log.txt");
ofstream rerrLog(LOG_PATH + "errLog.txt");
string optSave(SAVE_PATH + "optSave.oparams");

sf::Clock ticks;

namespace Main {

    ostringstream oss;
    bool connected = false;
    string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Brahim"};
    float version = 0.12;
    int sousVers = 0;
    string versionS;
    Player player;
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
                exit(-1);
            }
        InternalFiles::registerFiles();
        //Chargement des paramètres
        OptionsSave::initParams(optSave);
        if(!OptionsSave::checkParam("lang")) { //Si le paramètre "lang" n'existe pas
                OptionsSave::addParam("lang", "eng");
            }
        rlog << PRINT_TICKS << "Initialisation du log terminée." << endl;
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
    if (MainFrame::init) {

        }
    OptionsSave::saveParams(optSave);//Sauvegarde des paramètres
    rlog << PRINT_TICKS << "Fermeture des ressources." << endl;
    for(Map *map : Initializer::maps) {
            delete(map);
        }
    for(sf::Music *mus : Initializer::townMusics) {
            delete(mus);
        }
    rlog << PRINT_TICKS << "Fermeture du jeu. Return " << returne << endl;
    //Fermeture des log
    rlog.close();
    rerrLog.close();


#ifdef DEBUG//Outdated : Unused
    system("pause");
#endif // DEBUG
    if(Main::reboot) { //reboot si indiqué
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
    ticks.restart();
    //Création de la chaine de caractère de version
    Main::oss << "Alpha " << Main::version << "." << Main::sousVers;
    Main::versionS = Main::oss.str();
    //Traitement des arguments
#ifndef _WIN32
    string str("mkdir -p ");
    system((str + RESSOURCES_PATH).c_str());
    system((str + SAVE_PATH).c_str());
    system((str + LOG_PATH).c_str());
#endif
    if(argc >= 2) {
            FOR_EACH(char *, argv, argc, {)
                     string str = string(*objActuel);
            if(str == "--version") { //Affichage de la version
                cout << "OpMon Regimys version " << Main::versionS << endl;
                exit(0);
                }
            else if(str == "--opt") {//Changement de l'emplacement du fichier de sauvegarde des paramètres
                if(itor + 1 == argc) { //Si pas d'arguments a l'option --opt
                            exit(2);
                        }
                    else {
                            optSave = string(argv[itor + 1]);
                        }
                }
                    }
        }
    return Main::starts();//Lancement du jeu
}
