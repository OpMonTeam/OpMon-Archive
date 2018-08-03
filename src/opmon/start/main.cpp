
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
#include "config.hpp"
#include "i18n/Translator.hpp"
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

  namespace OpMon {
    namespace Main {
        //Will be used for checking the internet connection
        //bool connected = false;
        /** Trainer names. No longer useful.*/
        //->Useless
        std::string trainers[] = {"Brice", "Navet", "Mael", "Cyrion", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote",
                             "Giovanni", "Flora", "Silver", "Jules Cesar", "Brahim"};

        std::string version = OPMON_VERSION;

        std::string pre = "0";

        std::string versionS;
        /*
          #ifdef _WIN32
          std::string sep = "\\";
          #else
          std::string sep = "/";
          #endif
        */
        //bool reboot = false;

        int starts() {

            oplog("Log opening OK. Welcome in OpMon Lazuli.");
            oplog("Version : Alpha " + version + ((pre == "0") ? "" : ("-pre_" + pre)));
            std::ostringstream osslog;
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
            OptionsSave::initParams(Utils::Path::getSavePath() + "/optSave.oparams"); //Loading parameters
            if(!OptionsSave::checkParam("lang")) {                                    //If the "lang" setting don't exist
                OptionsSave::addParam("lang", "eng");
            }
            oplog("Resources repertory : " + Utils::Path::getResourcePath());

            //Initializaing keys
            oplog("Loading strings");
            std::string lang = OptionsSave::getParam("lang").getValue();
            auto &tr = ::OpMon::I18n::Translator::getInstance();

            if(!tr.getAvailableLanguages().count(lang)) {
                lang = "en"; // The lang isn't available. Default to english.
            }
            tr.setLang(lang);

            oplog("Loading completed! Opening gui.");
            //bgtask = new std::thread(bgTask);
            do {
                reboot = false;
                oplog("Starting game loop");

                GameLoop gameloop;
                frames = gameloop.getFrames();
                gameloop();

                std::string logEntry;
                logEntry << std::string("Game ended after ") << getFrames() << std::string("frames");

                oplog(logEntry);
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
        std::cout << "Exiting" << std:: endl;
        return -1;
    }

    auto versionS = "Version : Alpha " + OpMon::Main::version + ((OpMon::Main::pre == "0") ? "" : ("-pre_" + OpMon::Main::pre));

    if(!ResourceLoader::checkResourceFolderExists() || !Utils::Fs::mkdir(SAVE_PATH)) {
        std::cout << "Exiting" << std:: endl;
        return -1;
    }

    //Checking parameters
    if(argc >= 2) {
        for(int i = 0; i < argc; i++) {
            std::string str = std::string(argv[i]);
            if(str == "--version") {
                std::cout << "OpMon Lazuli version " << versionS << std:: endl;
                std::cout << "Under GNU GPL v3.0 license" << std:: endl;
                std::cout << "http://opmon-game.ga" << std:: endl;
                return 0;
            } else if(str == "--help") {
                std::cout << "--version : Prints the version and quit." << std:: endl;
                std::cout << "--help : Prints this message and quit." << std:: endl;
                //std::cout << "--opt <path> : Changes the options save file's location." << std:: endl;
                std::cout << "--debug : Starts the game with debug code. Changes when needed." << std:: endl;
                return 0;
            } else if(str == "--debug") {
                std::cout << (int)Side::TO_UP << std:: endl;
                std::cout << (int)Side::TO_DOWN << std:: endl;
                std::cout << (int)Side::TO_LEFT << std:: endl;
                std::cout << (int)Side::TO_RIGHT << std:: endl;
                std::cout << (int)(Side::TO_UP + 4) << std:: endl;
                return 0;
            } else {
                std::cout << "Unknown parameters. Skipping." << std:: endl;
            }
        }
    }
    return OpMon::Main::starts();
}
