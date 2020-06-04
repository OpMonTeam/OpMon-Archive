/*
fs.cpp
Author : BAKFR
File under GNU GPL v3.0
*/
#include "./fs.hpp"

#include <cerrno>
#include <iostream>
#include <string>

#ifndef _WIN32
#    include <sys/stat.h>
#else
#    include <direct.h>
#endif

namespace Utils {
    namespace Fs {

        bool mkdir(const std::string &path) {
#ifndef _WIN32 // Linux only
            int result = ::mkdir(path.c_str(), 0711);
#else
            std::string path2(path);
            std::replace(path2.begin(), path2.end(), '/', '\\');
            int result = ::_mkdir(path.c_str());
#endif
            if(result == 0 || errno == EEXIST)
                return true;

            std::cout << "creation of folder \"" << path << "\" failed: errno "
                      << errno << std::endl;
            return false;
        }

    } // namespace Fs
} // namespace Utils
