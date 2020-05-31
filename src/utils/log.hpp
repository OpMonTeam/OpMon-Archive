/*!
 * \file log.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <iostream>
#include <string>

namespace Utils {
    /*!
     * \namespace Utils::Log
     * \brief Contains log-related utilities.
     * \todo Make it a class.
     */
    namespace Log {
        /*!
         * \brief Initialize the log streams.
         *
         * This function must be called before any call to oplog().
         */
        void init(std::string path);

        /*!
         * \brief Write a log message in a log file.
         *
         * \param toSay message to write.
         * \param bool if `true` the log message will be written in the error log file; otherwise, it will be written in the regular log file.
         */
        void oplog(const std::string &toSay, bool error = false);

        /*! \brief Add "[WARN - " to the parameter before calling oplog.
         *
         * \param toSay message to write.
         */
        void warn(const std::string &toSay);
    } // namespace Log
} // namespace Utils
