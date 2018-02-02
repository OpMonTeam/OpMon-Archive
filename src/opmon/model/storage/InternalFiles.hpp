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

namespace OpMon{
  namespace Model{
  
    namespace InternalFiles {
      extern std::vector<std::string> filesNames;
      extern std::vector<std::string> files;
      void registerFiles();
      std::ostringstream *openFileOut(std::string const& name);
      std::istringstream *openFileIn(std::string const& name);
    }

    namespace Collisions {
      extern char feCol[32][32];
      extern char ppHomeCol[16][16];
      extern char rivalHomeCol[16][16];
      extern char ppRoomCol[6][9];
      extern char momRoomCol[6][6];
      extern char laboCol[16][32];
      extern char route14Col[41][74];
      extern char myciCol[19][19];

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
       extern int rivalhomeLayer1[1024];
       extern int rivalhomeLayer2[1024];
       extern int rivalhomeLayer3[1024];
       extern int route14Layer1[5130];
       extern int route14Layer2[5130];
       extern int route14Layer3[5130];
       extern int myciLayer1[1225];
       extern int myciLayer2[1225];
       extern int myciLayer3[1225];
     }  
   }
 }
 #endif // INTERNALFILES_HPP
