/*
path.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#pragma once

namespace Utils {
    namespace Path {

        /**
     * Get the root path of resource files.
     */
        const std::string getResourcePath();
        const std::string getSavePath();
        const std::string getLogPath();
    } // namespace Path
} // namespace Utils
