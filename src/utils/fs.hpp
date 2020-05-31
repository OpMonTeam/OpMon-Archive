/*!
 * \file fs.hpp
 * \author BAKFR
 * \copyright GNU GPL v3.0
 * \date 08/01/18
 */
#pragma once

#include <string>

namespace Utils {
    /*!
     * \namespace Utils::Fs
     * \brief Contains file system related utilities.
     */
    namespace Fs {

        /*!
         * \brief Makes a new directory (if it does not exist yet).
         *
         * \param path file path in the UNIX format
         * \return `true` if the directory exists; `false` in case of error. On windows, always returns true.
         */
        bool mkdir(const std::string &path);

    } // namespace Fs
} // namespace Utils
