/*
fs.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#pragma once

#include <string>

namespace Utils {
    namespace Fs {

        /**
     * Make a new directory (if it does not exist yet).
     *
     * @param path file path in the UNIX format
     * @return `true` if the directory exists; `false` in case of error. On windows, always returns true.
     */
        bool mkdir(const std::string &path);

    } // namespace Fs
} // namespace Utils
