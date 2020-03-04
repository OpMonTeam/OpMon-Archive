/*
Core.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Core.hpp"

#include <cstdlib>
#include <iostream>

#include "src/utils/defines.hpp"
#include "src/utils/log.hpp"
#include "system/path.hpp"
#include "src/utils/OptionsSave.hpp"

using Utils::Log::oplog;

namespace OpMon {

    std::string optSave(Path::getSavePath() + "optSave.oparams");

    //The number of errors handeled in the program.
    int errors = 0;

    void handleError(std::string const &errorName, bool fatal) {
        errors++;
        std::ostringstream osslog;
        osslog << std::string("Error  n�") << errors << (std::string(" : ") + errorName);
        oplog(osslog.str(), true);
        std::cerr << "Error no" << errors << " : " << errorName << std::endl;
        if(errors > 20) { //If the program gets more than 20 errors, it stops.
            std::cerr << "Too many errors. Closing program. Please check the integrity of your installation." << std::endl;
            oplog("Too many errors. Closing program. Please check the integrity of your installation. If the problems persists, warn us.", true);
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
        Utils::OptionsSave::saveParams(optSave); //Saving parameters

        std::ostringstream osslog;
        osslog << "End of the program. Return " << returns;
        oplog(osslog.str());
        if(returns != 0) {
            Utils::Log::warn("There is a problem. Create an issue on github!");
        }else{
            Utils::Log::warn("Quitting without liberating the resources!");
        }
        exit(returns);
    }

} // namespace OpMon
