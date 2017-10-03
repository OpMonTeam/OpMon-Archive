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
ofstream *rlog = new ofstream(LOG_PATH + "log.txt");
ofstream *rerrLog = new ofstream(LOG_PATH + "errLog.txt");
string optSave(SAVE_PATH + "optSave.oparams");

sf::Clock ticks;

string getPath(string const& path) {
#ifdef _WIN32
    vector<sf::String> splitted = StringKeys::split(path, '/');
    string returned = "";
    for(unsigned int i = 0; i < splitted.size(); i++) {
        returned += splitted[i];
        if(i != splitted.size() - 1) {
            returned += "\\";
        }
    }
    return returned;
#else
    return path;
#endif
}

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
    if (!(*rlog)) {
        cout << "Unable to open the log." << endl;

#ifndef _WIN32
        string str("mkdir -p ");
#else
        string str("mkdir ");
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"//Ignore this warning
        system((str + RESSOURCES_PATH).c_str());
        system((str + SAVE_PATH).c_str());
        system((str + LOG_PATH).c_str());
#pragma GCC diagnostic pop

        cout << "Retry." << endl;
        delete(rlog);
        rlog = new ofstream(LOG_PATH + "log.txt");
        starts();
        return 0;
    }

    if (!(*rerrLog)) {
        cout << "Unable to open the error log" << endl;

#ifndef _WIN32
        string str("mkdir -p ");
#else
        string str("mkdir ");
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
        system((str + RESSOURCES_PATH).c_str());
        system((str + SAVE_PATH).c_str());
        system((str + LOG_PATH).c_str());
#pragma GCC diagnostic pop

        cout << "Retry." << endl;
        delete(rerrLog);
        rerrLog = new ofstream(LOG_PATH + "errLog.txt");
        starts();
        return 0;
    }

    oplog("Log opening OK. Welcome in OpMon Lazuli.");
    oplog("Version : " + version);
    ostringstream osslog;
    osslog << "Date in seconds : " << time(NULL);
    oplog(osslog.str());
#ifdef _WIN32
    oplog("Plateform : Windows");
#else
    oplog("Plateform : Unix");
#endif
    oplog("Loading internal files.");
    InternalFiles::registerFiles();
    oplog("Loading options");
    OptionsSave::initParams(optSave);//Loading parameters
    if(!OptionsSave::checkParam("lang")) { //If the "lang" setting don't exist
        OptionsSave::addParam("lang", "eng");
    }
    oplog("Loading the resources.");
    Initializer::init();
    oplog("Loading completed! Opening gui.");
    mainframe.open();
    oplog("Ending the game normally.");
    return quit(0);
}

}

void oplog(string toSay, bool error) {
    if(error) {
        (*rerrLog) << PRINT_TICKS << toSay << endl;
    } else {
        (*rlog) << PRINT_TICKS << toSay << endl;
    }
}
//The number of errors handeled in the program.
int errors = 0;

void handleError(string const& errorName, bool fatal) {
    errors++;
    ostringstream osslog;
    osslog << string("Error  n°") << errors << (string(" : ") + errorName);
    oplog(osslog.str(), true);
    cerr << "Error n°" << errors << " : " << errorName << endl;
    if(errors > 20) { //If the program gets more than 20 errors, it stops.
        cerr << "Too many errors. Closing program. Please verify your installation." << endl;
        oplog("Too many errors. Closing program. Please verify your installation. If the problems persists, warn us.", true);
        fatal = true;
    }
    if (fatal) {
        ostringstream ossslog;
        ossslog << "Fatal error. Total errors : " << errors;
        oplog(ossslog.str(), true);
        cerr << "Fatal error." << endl;
        oplog("Crash.");
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
    oplog("Deleting resources in the memory");
    for(Map *map : Initializer::maps) {//Deleting the maps
        delete(map);
    }
    for(sf::Music *mus : Initializer::townMusics) {//Deleting the maps' music
        delete(mus);
    }
    ostringstream osslog;
    osslog << "End of the program. Return " << returns;
    oplog(osslog.str());
    if(returns != 0) {
        oplog("There is a problem. Create an issue on github!");
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
#else
    string str("mkdir ");
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
    system((str + RESSOURCES_PATH).c_str());
    system((str + SAVE_PATH).c_str());
    system((str + LOG_PATH).c_str());
#pragma GCC diagnostic pop
    //Checking parameters
    if(argc >= 2) {
        FOR_EACH(char *, argv, argc, {)
                 string str = string(*currentObj);
        if(str == "--version") {
        cout << "OpMon Lazuli version " << Main::versionS << endl;
        cout << "Under GNU GPL 3.0 license" << endl;
        return 0;
    } else if(str == "--opt") {
        if(itor + 1 == argc) {
                return 2;
            } else {
                optSave = string(argv[itor + 1]);
            }
        } else if(str == "--help") {
        cout << "--version : Prints the version and quit." << endl;
        cout << "--help : Prints this message and quit." << endl;
        cout << "--opt <path> : Changes the options save file's location." << endl;
        return 0;
    } else {
        cout << "Unknown parameters. Skipping." << endl;
    }
            }
}
return Main::starts();
}
