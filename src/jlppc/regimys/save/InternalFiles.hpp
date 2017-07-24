#ifndef INTERNALFILES_HPP
#define INTERNALFILES_HPP

#include <iostream>
#include <sstream>
#include <vector>

namespace InternalFiles {
    extern std::vector<std::string> filesNames;
    extern std::vector<std::string> files;
    void registerFiles();
    std::ostringstream *openFileOut(std::string name);
    std::istringstream *openFileIn(std::string name);
};

#endif // INTERNALFILES_HPP
