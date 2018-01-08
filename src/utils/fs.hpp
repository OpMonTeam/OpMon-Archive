
#pragma once

namespace Utils{
  namespace Fs{

    /**
     * Make a new directory (if it does not exist yet).
     *
     * @param path file path in the UNIX format
     * @return `true` if the directory exists; `false` in case of error. On windows, always returns true.
     */
    bool mkdir(const std::string &path);

    /**
     Returns the path depending of the system.
     By default, please use the "/" separator.
     Then, if the os is Windows, this function will change the "/" by "\".
     If you use the "\" separator in the path given,
     nothing will change, on unix systems and on Windows systems.
    */
    std::string getPath(std::string const& path);
  }
}
