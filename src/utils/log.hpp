/*
log.cpp
Author : BAKFR
File under GNU GPL v3.0
*/
#pragma once

#include <iostream>

namespace Utils {
    namespace Log {
        /**
     * Initialize the log streams.
     *
     * This function must be called before any call to `oplog()`.
     * @return `true` if everything is OK; `false` if there is an error.
     */
        void init();

        /**
     * Write a log message in a log file.
     *
     * @param toSay message to write.
     * @param bool if `true` the log message will be written in th error log file;
     *   otherwise, it will be written in the regular log file.
     */
        void oplog(const std::string &toSay, bool error = false);

        void warn(const std::string &toSay);
    } // namespace Log
} // namespace Utils
