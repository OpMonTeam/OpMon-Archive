/*
path.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#pragma once

namespace Utils::Path {

    /**
	 * Get the root path of resource files.
	 */
    std::string getResourcePath();
    std::string getSavePath();
    std::string getLogPath();
} // namespace Utils::Path
