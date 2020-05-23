/*!
 * \file path.hpp
 * \author BAKFR
 * \copyright GNU GPL v3.0
 * \date 13/01/18
*/
#pragma once

#include <string>

namespace OpMon {
    /*!
     * \brief Contains path-related utilites.
     */
    namespace Path {

        /*!
         * \returns The root path of resource files.
         */
        const std::string getResourcePath();
        /*!
         * \returns The root path of save files.
         */
        const std::string getSavePath();
        /*!
         * \returns The root path of log files.
         */
        const std::string getLogPath();
    } // namespace Path
} // namespace OpMon
