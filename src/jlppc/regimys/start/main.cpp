#include "main.hpp"

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
/*
Logs and save files initialization
*/
ofstream rlog(LOG_PATH + "log.txt");
ofstream rerrLog(LOG_PATH + "errLog.txt");
string optSave(SAVE_PATH + "optSave.oparams");

sf::Clock ticks;

namespace Main {
    //Will be used for checking the internet connection
    //bool connected = false;
    /** Trainer names. No longer useful.*/
    //->Useless
string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Brahim"};

    string version = "0.12.1";
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
        cout << "Unable to open the log." << endl;
    }

    if (!rerrLog) {
        cout << "Unable to open the error log" << endl;
    }

    rlog << PRINT_TICKS << "Log opening OK. Welcome in OpMon Lazuli." << endl;
    rlog << PRINT_TICKS << "Version : " << version << endl;
    rlog << PRINT_TICKS << "Date in seconds : " << time(NULL) << endl;
    #ifdef _WIN32
    rlog << PRINT_TICKS << "Plateform : Windows" << endl;
    #else
    rlog << PRINT_TICKS << "Plateform : Unix" << endl;
    #endif
    rlog << PRINT_TICKS << "Loading internal files." << endl;
    InternalFiles::registerFiles();
    rlog << PRINT_TICKS << "Loading options" << endl;
    OptionsSave::initParams(optSave);//Loading parameters
    if(!OptionsSave::checkParam("lang")) { //If the "lang" setting don't exist
        OptionsSave::addParam("lang", "eng");
    }
    rlog << PRINT_TICKS << "Loading the resources." << endl;
    Initializer::init();
    rlog << PRINT_TICKS << "Loading completed! Opening gui." << endl;
    mainframe.open();
    rlog << PRINT_TICKS << "Ending the game normally." << endl;
    return quit(0);
}

}
//The number of errors handeled in the program.
int errors = 0;

void handleError(string const& errorName, bool fatal) {
    errors++;
    rerrLog << "Error  n°" << errors << " : " << errorName << endl;
    cerr << "Error n°" << errors << " : " << errorName << endl;
    if(errors > 20) { //If the program gets more than 20 errors, it stops.
        cerr << "Too many errors. Closing program. Please verify your installation." << endl;
        rerrLog << "Too many errors. Closing program. Please verify your installation. If the problems persists, warn us." << endl;
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
    /*
    if (Main::mainframe.init) {
	//Nothing here anymore, was used for the SDL. I keep it because it may be useful one day.
    }
    */
    OptionsSave::saveParams(optSave);//Saving parameters
    rlog << PRINT_TICKS << "Deleting resources in the memory" << endl;
    for(Map *map : Initializer::maps) {//Deleting the maps
        delete(map);
    }
    for(sf::Music *mus : Initializer::townMusics) {//Deleting the maps' music
        delete(mus);
    }
    rlog << PRINT_TICKS << "End of the program. Return " << returns << endl;
    if(returns != 0){
	rlog << PRINT_TICKS << "There is a problem. Create an issue on github!" << endl;
    }
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
    Main::versionS += string("Alpha ") + Main::version;
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
	cout << "Under GNU GPL 3.0 license" << endl;
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
