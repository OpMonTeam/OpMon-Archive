/*
Utils.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Définit le namespace Utils
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

namespace Utils {
    namespace Misc {
        int randU(int limit);

        unsigned int randUI(unsigned int limit);

        long hash(const std::string &str);
    } // namespace Misc
} // namespace Utils

#endif // UTILS_HPP
