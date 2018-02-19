
#include "Core.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/log.hpp"
#include "../../utils/path.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/storage/Data.hpp"
#include "../model/sysObjects/Map.hpp"
#include "./Initializer.hpp"
#include <map>
#include <ostream>
#include <sstream>

using namespace OpMon::Model;
using Utils::Log::oplog;

UNS

  namespace OpMon {
    /*
    Logs and save files initialization
  */
    string optSave(SAVE_PATH + "optSave.oparams");

    bool debugMode = false;
    bool debugCol = false;
    bool camUnlock = false;

    bool reboot = false;
    
    //The number of errors handeled in the program.
    int errors = 0;

    void handleError(string const &errorName, bool fatal) {
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
        if(fatal) {
            ostringstream ossslog;
            ossslog << "Fatal error. Total errors : " << errors;
            oplog(ossslog.str(), true);
            cerr << "Fatal error." << endl;
            oplog("Crash.");
            quit(1);
        }
    }

    int quit(int const &returns) {
        OptionsSave::saveParams(optSave); //Saving parameters
        oplog("Deleting resources in the memory");
        for(auto &map : Data::World::maps) {
            delete(map.second);
        }
        for(sf::Music *mus : Data::Ui::townMusics) { //Deleting the maps' music
            delete(mus);
        }

        // TODO: delet the player's OpMons !
        // for(unsigned short i = 0; i < 6; i++){
        //  delete(Main::player.getOp(i));
        // }

        ostringstream osslog;
        osslog << "End of the program. Return " << returns;
        oplog(osslog.str());
        if(returns != 0) {
            oplog("There is a problem. Create an issue on github!");
        }
        exit(returns);
    }

    int *frames;

    int getFrames() {
        return *frames;
    }

    std::string &operator<<(std::string &str, int nbre) {
        ostringstream oss;
        oss << str << nbre;
        str = oss.str();
        return str;
    }

    std::string &operator<<(std::string &str, std::string const &thing) {
        ostringstream oss;
        oss << str << thing;
        str = oss.str();
        return str;
    }

    std::string &operator<<(std::string &str, char thing[]) {
        string strThing(thing);
        ostringstream oss;
        oss << str << strThing;
        str = oss.str();
        return str;
    }

    template <typename Base, typename T>
    bool instanceOf(const Base *toTest) {
        return dynamic_cast<const T *>(toTest) != nullptr;
    }
}
