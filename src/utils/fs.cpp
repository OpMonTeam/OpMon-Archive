
#include <algorithm>
#include <string>
#include <iostream>
#include "./fs.hpp"


namespace Utils {
  namespace Fs {


    bool mkdir(const std::string &path) {
      // Path in the local system format
      std::string path2 = getPath(path);

#ifndef _WIN32
      const char *cmd = "mkdir -p ";
#else
      const char *cmd = "mkdir ";
#endif

      int result = system((cmd + path2).c_str());
      if (result) {
        std::cout << "creation of folder \"" << path2 << " failed: errno " << result << std::endl;
      }
#ifndef _WIN32
      return !result;
#else
      return true; // mkdir in windows returns false if the directory exists
#endif
    }

    std::string getPath(std::string const &path) {
#ifdef _WIN32
      std::string result(path);
      return std::replace(result.begin(), result.end(), '/', '\\');
#else
      return path;
#endif
    }

  }
}
