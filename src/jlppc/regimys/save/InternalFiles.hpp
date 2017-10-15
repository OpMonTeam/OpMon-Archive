#ifndef INTERNALFILES_HPP
#define INTERNALFILES_HPP

#include <iostream>
#include <sstream>
#include <vector>

namespace InternalFiles {
extern std::vector<std::string> filesNames;
extern std::vector<std::string> files;
void registerFiles();
std::ostringstream *openFileOut(std::string const& name);
std::istringstream *openFileIn(std::string const& name);
};

namespace Collisions {
extern char feCol[32][32];
extern char ppHomeCol[16][16];
extern char rivalHomeCol[16][16];
extern char ppRoomCol[6][9];
extern char momRoomCol[6][6];
extern char laboCol[16][32];
}

namespace Maps {
  extern int feLayer1[2304];
  extern int feLayer2[2304];
  extern int feLayer3[2304];
  extern int laboLayer1[1536];
  extern int laboLayer2[1536];
  extern int laboLayer3[1536];
  extern int pproomLayer1[550];
  extern int pproomLayer2[550];
  extern int pproomLayer3[550];
  extern int pphomeLayer1[1024];
  extern int pphomeLayer2[1024];
  extern int pphomeLayer3[1024];
  extern int momroomLayer1[484];
  extern int momroomLayer2[484];
  extern int momroomLayer3[484];
  extern int rivalhomeLayer1[1024];
  extern int rivalhomeLayer2[1024];
  extern int rivalhomeLayer3[1024];
}

#endif // INTERNALFILES_HPP
