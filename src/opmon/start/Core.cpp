/*
Core.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Core.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/log.hpp"
#include "../../utils/path.hpp"
#include "../model/save/OptionsSave.hpp"
#include "../model/sysObjects/Map.hpp"
#include <map>
#include <ostream>
#include <sstream>

using namespace OpMon::Model;
using Utils::Log::oplog;

namespace OpMon {

    std::string optSave(SAVE_PATH + "optSave.oparams");

    bool debugMode = false;
    bool debugCol = false;

    bool reboot = false;

    //The number of errors handeled in the program.
    int errors = 0;

    void handleError(std::string const &errorName, bool fatal) {
        errors++;
        std::ostringstream osslog;
        osslog << std::string("Error  n°") << errors << (std::string(" : ") + errorName);
        oplog(osslog.str(), true);
        std::cerr << "Error no" << errors << " : " << errorName << std::endl;
        if(errors > 20) { //If the program gets more than 20 errors, it stops.
            std::cerr << "Too many errors. Closing program. Please verify your installation." << std::endl;
            oplog("Too many errors. Closing program. Please verify your installation. If the problems persists, warn us.", true);
            fatal = true;
        }
        if(fatal) {
            std::ostringstream ossslog;
            ossslog << "Fatal error. Total errors : " << errors;
            oplog(ossslog.str(), true);
            std::cerr << "Fatal error." << std::endl;
            oplog("Crash.");
            quit(1);
        }
    }

    int quit(int const &returns) {
        OptionsSave::saveParams(optSave); //Saving parameters
        oplog("Deleting resources in the memory");

        std::ostringstream osslog;
        osslog << "End of the program. Return " << returns;
        oplog(osslog.str());
        if(returns != 0) {
            oplog("There is a problem. Create an issue on github!");
        }
        exit(returns);
    }

    std::string &operator<<(std::string &str, int nbre) {
        std::ostringstream oss;
        oss << str << nbre;
        str = oss.str();
        return str;
    }

    std::string &operator<<(std::string &str, std::string const &thing) {
        std::ostringstream oss;
        oss << str << thing;
        str = oss.str();
        return str;
    }

    std::string &operator<<(std::string &str, char thing[]) {
        std::string strThing(thing);
        std::ostringstream oss;
        oss << str << strThing;
        str = oss.str();
        return str;
    }

    template <typename Base, typename T>
    bool instanceOf(const Base *toTest) {
        return dynamic_cast<const T *>(toTest) != nullptr;
    }
} // namespace OpMon
