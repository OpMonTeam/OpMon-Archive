
#include "../../utils/defines.hpp"
#include "../../utils/fs.hpp"
#include "../../utils/log.hpp"
#include "../../utils/path.hpp"
#include "../../utils/time.hpp"
#include "../model/objects/Enums.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/InternalFiles.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../view/Window.hpp"
#include "./Core.hpp"
#include "./Gameloop.hpp"
#include "./Initializer.hpp"
#include "config.hpp"
#include <ostream>
#include <string>

using namespace OpMon::Model;
using Utils::Log::oplog;

// MSC uses WinMain() instead of main().
#ifdef _MSC_VER

#include <windows.h>
int main(int argc, char *argv[]);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    int argc;
    char **argv;
    /* BuildArgVector() uses the Win32 function GetCommandLine() to populate argc and argv */
    BuildArgVector(&argc, &argv);
    return main(argc, argv);
}
#endif

//#define DEBUG
UNS

  namespace OpMon {
    namespace Main {
        //Will be used for checking the internet connection
        //bool connected = false;
        /** Trainer names. No longer useful.*/
        //->Useless
        string trainers[] = {"Brice", "Navet", "Mael", "Cyrion", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote",
                             "Giovanni", "Flora", "Silver", "Jules Cesar", "Brahim"};

        string version = OPMON_VERSION;

        string pre = "0";

        string versionS;
        /*
          #ifdef _WIN32
          string sep = "\\";
          #else
          string sep = "/";
          #endif
        */
        //bool reboot = false;

        int starts() {

            oplog("Log opening OK. Welcome in OpMon Lazuli.");
            oplog("Version : Alpha " + version + ((pre == "0") ? "" : ("-pre_" + pre)));
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
            OptionsSave::initParams(optSave);      //Loading parameters
            if(!OptionsSave::checkParam("lang")) { //If the "lang" setting don't exist
                OptionsSave::addParam("lang", "eng");
            }
            oplog("Loading the resources.");
	    oplog("Repertory : " + Utils::Path::getResourcePath());
            Initializer::init();
            oplog("Loading completed! Opening gui.");
            //bgtask = new std::thread(bgTask);
            do {
                reboot = false;
                View::open();
                oplog("Starting game loop");

                auto gameloop = GameLoop();
                frames = gameloop.getFrames();
                gameloop();

                std::string logEntry;
                logEntry << "Game ended after " << getFrames() << "frames";

                oplog(logEntry);
                View::close();
                if(reboot) {
                    oplog("Restarting the game.");
                }
            } while(reboot);
            oplog("Ending the game normally.");
            return quit(0);
        }
    } // namespace Main
}

int main(int argc, char *argv[]) {
    Utils::Time::initClock();
    if(!Utils::Log::init()) {
        cout << "Exiting" << endl;
        return -1;
    }

    auto versionS = "Version : Alpha " + OpMon::Main::version + ((OpMon::Main::pre == "0") ? "" : ("-pre_" + OpMon::Main::pre));

    if(!ResourceLoader::checkResourceFolderExists() || !Utils::Fs::mkdir(SAVE_PATH)) {
        cout << "Exiting" << endl;
        return -1;
    }

    //Checking parameters
    if(argc >= 2) {
        for(int i = 0; i < argc; i++) {
            string str = string(argv[i]);
            if(str == "--version") {
                cout << "OpMon Lazuli version " << versionS << endl;
                cout << "Under GNU GPL v3.0 license" << endl;
                cout << "http://opmon-game.ga" << endl;
                return 0;
            } else if(str == "--opt") {
                if(i + 1 == argc) {
                    return 2;
                } else {
                    OpMon::optSave = string(argv[i + 1]);
                }
            } else if(str == "--help") {
                cout << "--version : Prints the version and quit." << endl;
                cout << "--help : Prints this message and quit." << endl;
                cout << "--opt <path> : Changes the options save file's location." << endl;
                cout << "--debug : Starts the game with debug code. Changes when needed." << endl;
                return 0;
            } else if(str == "--debug") {
                cout << (int)Side::TO_UP << endl;
                cout << (int)Side::TO_DOWN << endl;
                cout << (int)Side::TO_LEFT << endl;
                cout << (int)Side::TO_RIGHT << endl;
                cout << (int)(Side::TO_UP + 4) << endl;
                return 0;
            } else {
                cout << "Unknown parameters. Skipping." << endl;
            }
        }
    }
    return OpMon::Main::starts();
}
