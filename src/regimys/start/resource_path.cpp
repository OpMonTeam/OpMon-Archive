
#include <sys/stat.h>
#include <cstdlib>
#include <string>


static bool _isFolder(const std::string &path) {
    struct stat st;
    return (!stat(path.c_str(), &st) && S_ISDIR(st.st_mode));
}


const std::string getResourcePath() {
    if(_isFolder("./data"))
        return "./data/";

    { // search in $XDG_DATA_HOME
        const char *xdg_data_home = std::getenv("XDG_DATA_HOME");
        std::string data_dir = xdg_data_home ? xdg_data_home : "";

        if (data_dir.empty()) {
            const char *home = std::getenv("HOME");
            if (home && home[0] != '\n') {
                data_dir = home;
                data_dir += "/.local/share";
            }
        }
        if (!data_dir.empty() && _isFolder(data_dir + "/OpMon"))
            return data_dir + "/OpMon/";
    }

    { // search in all folders of $XDG_DATA_DIRS
        const char *xdg_data_dirs = std::getenv("XDG_DATA_DIRS");
        std::string data_dir_list = xdg_data_dirs ? xdg_data_dirs : "";

        if (data_dir_list.empty())
            data_dir_list = "/usr/local/share/:/usr/share/";

        size_t next_delimiter = 0;
        while (next_delimiter != std::string::npos) {
            next_delimiter = data_dir_list.find(':');
            std::string data_dir = data_dir_list.substr(0, next_delimiter);
            if (!data_dir.empty() && _isFolder(data_dir + "/OpMon"))
                return data_dir + "/OpMon/";
            data_dir_list.erase(0, next_delimiter + 1);
        }
    }

    return nullptr;
}
