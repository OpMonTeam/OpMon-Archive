/*
misc.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <functional>

namespace Utils {
    namespace Misc {
        int randU(int limit);

        unsigned int randUI(unsigned int limit);

        std::size_t hash(const std::string &str);
    } // namespace Misc
} // namespace Utils

#endif // UTILS_HPP
