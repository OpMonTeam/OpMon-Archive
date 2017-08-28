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

#endif // INTERNALFILES_HPP
