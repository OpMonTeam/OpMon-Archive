#include "Core.hpp"

/*
Logs and save files initialization
*/
string optSave(SAVE_PATH + "optSave.oparams");

sf::Clock ticks;

string getPath(string const& path) {
#ifdef _WIN32
    vector<sf::String> splitted = StringKeys::split(path, '/');
    string returned = "";
    for(unsigned int i = 0; i < splitted.size(); i++) {
        returned += splitted[i];
        if(i != splitted.size() - 1) {
            returned += "\\";
        }
    }
    return returned;
#else
    return path;
#endif
}


/**
 * Make a new directory (if it does not exist yet).
 *
 * @param path file path in the UNIX format
 * @return `true` if the directory exists; `false` in case of error.
 */
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
        cout << "creation of folder \"" << path2 << " failed: errno " << result << endl;
    }
    #ifndef _WIN32
    return !result;
    #else
    return true;//Because mkdir in windows returns false if the directory exists$
    #endif
}
