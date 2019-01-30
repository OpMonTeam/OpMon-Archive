/*
misc.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <functional>
#include <iostream>

namespace Utils {
    namespace Misc {
        int randU(int limit);

        unsigned int randUI(unsigned int limit);

        std::size_t hash(const std::string &str);

        template <typename T>
        T *vectorToArray(std::vector<T> const &vect);
    } // namespace Misc
} // namespace Utils

#endif // UTILS_HPP
