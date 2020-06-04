/*
main.cpp
Author : Cyrielle
Contributors : Stelyus, Navet56
File under GNU GPL v3.0 license
*/
#include <bits/exception.h>
#include <ctime>
#include <iostream>
#include <string>

#include "../../utils/fs.hpp"
#include "../../utils/log.hpp"
#include "../../utils/time.hpp"
#include "Gameloop.hpp"
#include "config.hpp"
#include "path.hpp"
#include "src/utils/ResourceLoader.hpp"
#include "src/opmon/core/GameStatus.hpp"
#include "src/utils/exceptions.hpp"

using Utils::Log::oplog;

// Compilation with Visual Studio
// MSC uses WinMain() instead of main().
#ifdef _MSC_VER

#    include <windows.h>

int main(int argc, char *argv[]);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    return main(__argc, __argv);
}
#endif

//#define DEBUG

namespace OpMon {
    namespace Main {

        std::string version = OPMON_VERSION;

        std::string pre = "1";

        std::string versionS;

        int starts() {
            Utils::Log::init(Path::getLogPath());

            oplog("Log opening OK. Welcome in OpMon Lazuli.");
            oplog("Version: Alpha " + version +
                  ((pre == "0") ? "" : ("-pre_" + pre)));
            std::ostringstream osslog;
            osslog << "Date in seconds: " << time(NULL);
            oplog(osslog.str());
#ifdef _WIN32
            oplog("Plateform: Windows");
#else
            oplog("Plateform: Unix");
#endif
            oplog("Resources repertory: " + Path::getResourcePath());
            Utils::ResourceLoader::setResourcePath(Path::getResourcePath());

            oplog("Checking directories...");

            if(!Utils::ResourceLoader::checkResourceFolderExists() ||
               !Utils::Fs::mkdir(OpMon::Path::getSavePath())) {
                oplog("Problems found with the directories, quitting.");
                return -1;
            }

            oplog("Loading completed! Opening gui.");

            bool reboot = false;
            try {
                do {
                    oplog("Starting game loop");

                    GameLoop gameloop;
                    reboot = gameloop() == GameStatus::REBOOT;

                    std::ostringstream logEntry;
                    logEntry << std::string("Game ended after ")
                             << Utils::Time::getElapsedSeconds()
                             << std::string("seconds");

                    oplog(logEntry.str());
                    if(reboot) {
                        oplog("Restarting the game.");
                    }
                } while(reboot);
                oplog("Ending the game normally.");
                oplog("End of the program. Return 0");
                return 0;

            } catch(Utils::Exception &e) {
                oplog("Uncaught exception reached main: " + e.desc() +
                          " - Status: " + (e.fatal ? "" : "not ") +
                          "fatal. Quitting anyway, can't do otherwise.",
                      true);
                oplog("Uncaught exception reached main, quitting.");
                return e.returnId;
            } catch(std::exception &e) {
                oplog("Unexpected exception occured: " + std::string(e.what()),
                      true);
                oplog("Unexpected exception occured, quitting.");
                return 1;
            }
        }
    } // namespace Main
} // namespace OpMon

int main(int argc, char *argv[]) {
    Utils::Time::initClock();

    auto versionS =
        "Version : Alpha " + OpMon::Main::version +
        ((OpMon::Main::pre == "0") ? "" : ("-pre_" + OpMon::Main::pre));

    // Checking parameters
    if(argc >= 2) {
        for(int i = 0; i < argc; i++) {
            std::string str = std::string(argv[i]);
            if(str == "--version") {
                std::cout << "OpMon Lazuli version " << versionS << std::endl;
                std::cout << "Under GNU GPL v3.0 license" << std::endl;
                std::cout << "http://opmon-game.ga" << std::endl;
                return 0;
            } else if(str == "--help") {
                std::cout << "--version : Prints the version and quit."
                          << std::endl;
                std::cout << "--help : Prints this message and quit."
                          << std::endl;
                return 0;
            }
        }
    }
    return OpMon::Main::starts();
}
