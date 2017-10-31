#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <SFML/System.hpp>

int Utils::randU(int limit) {
    srand(time(NULL) + rand() * rand());
    return rand() % limit;
}

unsigned int Utils::randUI(unsigned int limit) {
    srand(time(NULL) + rand() * rand());
    unsigned int toReturn = rand() % limit;
    return toReturn;
}

void Utils::wait(int ticks) {
    sf::sleep(sf::milliseconds(ticks));
}

long Utils::hash(std::string str) {
    return 0;
}


/**
 * Make a new directory (if it does not exist yet).
 *
 * @param path file path in the UNIX format
 * @return `true` if the directory exists; `false` in case of error. On windows, always returns true.
 */
bool Utils::mkdir(const std::string &path) {
    // Path in the local system format
    std::string path2 = getPath(path);

#ifndef _WIN32
    const char *cmd = "mkdir -p ";
#else
    const char *cmd = "mkdir ";
#endif

    int result = system((cmd + path2).c_str());
    if (result) {
        cout << "creation of folder \"" << path2 << " failed: errno " << result << endl;
    }
    #ifndef _WIN32
    return !result;
    #else
    return true;//Because mkdir in windows returns false if the directory exists$
    #endif
}
