#include "main.hpp"

#ifndef __cplusplus
#error This is a C++ program!
#endif

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>

#include "../objects/item/Item.hpp"
#include "../objects/item/itemInclude.hxx"
#include "../playercore/Player.hpp"
#include "../playercore/OpTeam.hpp"
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
//bool connected = false;
string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Brahim"};
float version = 0.12;
int underVers = 0;
string versionS;
Player player;
/*#ifdef _WIN32
  string sep = "\\";
  #else
  string sep = "/";
  #endif*/
//bool reboot = false;

MainFrame mainframe;

int starts() {
    if (!rlog) {
        cout << "Initialisation error of error log" << endl;
        exit(-1);
    }

    if (!rerrLog) {
        cout << "Error opening of error log" << endl;
        exit(-1);
    }

    InternalFiles::registerFiles();
    OptionsSave::initParams(optSave);
    if(!OptionsSave::checkParam("lang")) { //If the "lang" setting don't exist
        OptionsSave::addParam("lang", "eng");
    }
    rlog << PRINT_TICKS << "Log initialisation completed." << endl;
    Initializer::init();

    mainframe.open();

    return quit(0);
}

}

int errors = 0;

void handleError(string const& errorName, bool fatal) {
    errors++;
    rerrLog << "Error  n°" << errors << " : " << errorName << endl;
    cerr << "Error n°" << errors << " : " << errorName << endl;
    if(errors > 20) { //If the program gets more than 20 errors, it stops.
        cerr << "Too many errors. Closing program. Please verify your installation." << endl;
        rerrLog << "Too many errors. Closing program. Please verify your installation." << endl;
        fatal = true;
    }
    if (fatal) {
        rerrLog << "Fatal error. Total errors : " << errors << endl;
        cerr << "Fatal error." << endl;
        rlog << PRINT_TICKS << "Crash." << endl;
        quit(1);
    }
}

int quit(int const& returns) {
  if (Main::mainframe.init) {

    }
    OptionsSave::saveParams(optSave);//Settings save
    rlog << PRINT_TICKS << "Deletions of the resources" << endl;
    for(Map *map : Initializer::maps) {
        delete(map);
    }
    for(sf::Music *mus : Initializer::townMusics) {
        delete(mus);
    }
    rlog << PRINT_TICKS << "End of the program. Return " << returns << endl;

    exit(returns);
    return returns;
}

std::string& operator<<(std::string &str, int const& nbre) {
    ostringstream oss;
    oss << str << nbre;
    str = oss.str();
    return str;
}

std::string& operator<<(std::string &str, std::string const& thing) {
    ostringstream oss;
    oss << str << thing;
    str = oss.str();
    return str;
}

std::string& operator<<(std::string &str, char thing[]) {
    string strThing(thing);
    ostringstream oss;
    oss << str << strThing;
    str = oss.str();
    return str;
}

#include "../objects/Attacks.hpp"
#include "../save/Save.hpp"
int main(int argc, char *argv[]) {
    ticks.restart();
    Main::versionS << string("Alpha ") << Main::version << string(".") << Main::underVers;
#ifndef _WIN32
    string str("mkdir -p ");
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    system((str + RESSOURCES_PATH).c_str());
    system((str + SAVE_PATH).c_str());
    system((str + LOG_PATH).c_str());
#pragma GCC diagnostic pop
#endif
    if(argc >= 2) {
        FOR_EACH(char *, argv, argc, {)
                 string str = string(*currentObj);
        if(str == "--version") {
        cout << "OpMon Lazuli version " << Main::versionS << endl;
        exit(0);
        } else if(str == "--opt") {
        if(itor + 1 == argc) {
                exit(2);
            } else {
                optSave = string(argv[itor + 1]);
            }
        }
                }
    }
    return Main::starts();
}
