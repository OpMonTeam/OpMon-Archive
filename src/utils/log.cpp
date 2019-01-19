/*
log.cpp
Author : BAKFR
Contributor : Cyrion
File under GNU GPL v3.0
*/
#include "./log.hpp"
#include "./fs.hpp"
#include "./time.hpp"
#include "path.hpp"
#include <fstream>

/**Principal log*/
static std::ostream *rlog = nullptr;
/**Error log*/
static std::ostream *rerrLog = nullptr;

/* location of the log folder */
#define LOG_PATH Path::getLogPath()

namespace Utils {
    namespace Log {

        void init() {
            if(rlog != nullptr)
                return; // Log already initialized

            Fs::mkdir(LOG_PATH);

            rlog = new std::ofstream(std::string(LOG_PATH + "log.txt"));
            rerrLog = new std::ofstream(std::string(LOG_PATH + "errLog.txt"));

            if(!*rlog) {
                rlog = &std::cout;
                std::cerr << "Unable to open the log." << std::endl;
            }
            if(!*rerrLog) {
                rerrLog = &std::cerr;
                std::cerr << "Unable to open the error log" << std::endl;
            }
        }

        void oplog(const std::string &toSay, bool error) {
            init();
            std::ostream *logStream = error ? rerrLog : rlog;
            *logStream << "[T = " << Time::getElapsedMilliseconds() << "] - " << toSay << std::endl;
        }

        void warn(const std::string &toSay) {
            oplog("[WARN] " + toSay);
        }

    } // namespace Log
} // namespace Utils
