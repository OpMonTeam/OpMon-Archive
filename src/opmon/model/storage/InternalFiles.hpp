/*
  InternalFiles.hpp
  Author : Cyriel
  Contributors : Navet56, BAKFR
  File under GNU GPL v3.0 license
*/

#ifndef INTERNALFILES_HPP
#define INTERNALFILES_HPP

#include <iostream>
#include <sstream>
#include <vector>

namespace OpMon {
    namespace Model {

        namespace InternalFiles {
            extern std::vector<std::string> filesNames;
            extern std::vector<std::string> files;
            void registerFiles();
            std::ostringstream *openFileOut(std::string const &name);
            std::istringstream *openFileIn(std::string const &name);
        } // namespace InternalFiles

        namespace Collisions {
            extern int colTile[4096];
        }
    }     // namespace Model
} // namespace OpMon
#endif // INTERNALFILES_HPP
