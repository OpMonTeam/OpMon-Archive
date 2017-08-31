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

#endif // INTERNALFILES_HPP
