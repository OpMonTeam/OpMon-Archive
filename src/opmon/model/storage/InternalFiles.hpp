/*
  InternalFiles.hpp
  Author : Jlppc
  File under the license GPL-3.0
  http://opmon-game.ga
  Contains the InternalFiles, Maps and Collisions namespaces
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

        namespace Maps {
            extern int feLayer1[2304];
            extern int feLayer2[2304];
            extern int feLayer3[2304];
            extern int laboLayer1[512];
            extern int laboLayer2[512];
            extern int laboLayer3[512];
            extern int pproomLayer1[72];
            extern int pproomLayer2[72];
            extern int pproomLayer3[72];
            extern int pphomeLayer1[256];
            extern int pphomeLayer2[256];
            extern int pphomeLayer3[256];
            extern int momroomLayer1[42];
            extern int momroomLayer2[42];
            extern int momroomLayer3[42];
            extern int rivalhomeLayer1[256];
            extern int rivalhomeLayer2[256];
            extern int rivalhomeLayer3[256];
            extern int route14Layer1[5130];
            extern int route14Layer2[5130];
            extern int route14Layer3[5130];
            extern int myciLayer1[1225];
            extern int myciLayer2[1225];
            extern int myciLayer3[1225];
            extern int opcenterLayer1[324];
            extern int opcenterLayer2[324];
            extern int opcenterLayer3[324];
        } // namespace Maps
    }     // namespace Model
} // namespace OpMon
#endif // INTERNALFILES_HPP
