/*
log.cpp
Author : BAKFR
Contributor : Cyrielle
File under GNU GPL v3.0
*/
#include "log.hpp"

#include <iostream>
#include <fstream>

#include "fs.hpp"
#include "time.hpp"
#include "exceptions.hpp"

/**Principal log*/
std::ostream *rlog = nullptr;
/**Error log*/
std::ostream *rerrLog = nullptr;

namespace Utils {
    namespace Log {

        void init(std::string path) {
            if(rlog != nullptr)
                return; // Log already initialized

            Fs::mkdir(path);

            rlog = new std::ofstream(std::string(path + "log.txt"));
            rerrLog = new std::ofstream(std::string(path + "errLog.txt"));

            if(!*rlog) {
                rlog = &std::cout;
                std::cerr << "Unable to open the log." << std::endl;
            }
            if(!*rerrLog) {
                rerrLog = &std::cerr;
                std::cerr << "Unable to open the error log." << std::endl;
            }
        }

        void oplog(const std::string &toSay, bool error) {
            if(rlog == nullptr || rerrLog == nullptr) {
                throw NullptrException("log stream or error log stream", false);
            }
            std::ostream *logStream = error ? rerrLog : rlog;
            *logStream << "[T = " << Time::getElapsedMilliseconds() << "] - " << toSay << std::endl;
        }

        void warn(const std::string &toSay) {
            oplog("[WARN] " + toSay);
        }

    } // namespace Log
} // namespace Utils
