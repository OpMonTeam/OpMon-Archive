/*
path.cpp
Author : BAKFR
Contributors : Cyrielle, jubalh, JonnyPtn
File under GNU GPL v3.0 license
*/
#include "fs.hpp"
#include <cstdlib>
#include <string>
#include <sys/stat.h>

// MSVC doesn't define S_ISDIR.
#if !defined(S_ISDIR) && defined(S_IFMT) && defined(S_IFDIR)
#define S_ISDIR(m) (((m)&S_IFMT) == S_IFDIR)
#endif

// Apple needs special code to get the resource folder within an app bundle
#ifdef __APPLE__
#include "ResourcePath.hpp"
#endif

namespace Utils::Path {
    static bool _isFolder(const std::string &path) {
        struct stat st;
        return (!stat(path.c_str(), &st) && S_ISDIR(st.st_mode));
    }

    static std::string _getConfigFilesPatch(const std::string &section) {
        const char *xdg_config_home = std::getenv("XDG_CONFIG_HOME");
        std::string config_dir = xdg_config_home ? xdg_config_home : "";

        if(config_dir.empty()) {
            const char *home = std::getenv("HOME");
            if(home && home[0] != '\n') {
                config_dir = home;
                config_dir += "/.config";
            }
        }
        if(!config_dir.empty()) {
            Fs::mkdir(config_dir + "/OpMon");
            Fs::mkdir(config_dir + "/OpMon/" + section);
            return config_dir + "/OpMon/" + section + "/";
        }
        return {};
    }

    std::string getSavePath() {
#ifdef _WIN32
        return "./saves/";
#else
        return _getConfigFilesPatch("saves");
#endif
    }

    std::string getLogPath() {
#ifdef _WIN32
        return "./log/";
#else
        return _getConfigFilesPatch("log");
#endif
    }

    std::string getResourcePath() {
        std::string resPath;
#ifdef __APPLE__
        resPath = resourcePath();
#endif
        if(_isFolder(resPath + "./data"))
            return resPath + "./data/";

        { // search in $XDG_DATA_HOME
            const char *xdg_data_home = std::getenv("XDG_DATA_HOME");
            std::string data_dir = xdg_data_home ? xdg_data_home : "";

            /*if(data_dir.empty()) {
		  //const char *home = std::getenv("HOME");
		  //if(home && home[0] != '\n') {
		  //    data_dir = home;
		  data_dir += "/usr/local/share";
			//}
			}*/
            if(!data_dir.empty() && _isFolder(data_dir + "/OpMon"))
                return data_dir + "/OpMon/";
        }

        { // search in all folders of $XDG_DATA_DIRS
            const char *xdg_data_dirs = std::getenv("XDG_DATA_DIRS");
            std::string data_dir_list = xdg_data_dirs ? xdg_data_dirs : "";

            if(data_dir_list.empty())
                data_dir_list = "/usr/local/share/:/usr/share/";

            size_t next_delimiter = 0;
            while(next_delimiter != std::string::npos) {
                next_delimiter = data_dir_list.find(':');
                std::string data_dir = data_dir_list.substr(0, next_delimiter);
                if(!data_dir.empty() && _isFolder(data_dir + "/OpMon")) {
                    return data_dir + "/OpMon/";
                }
                data_dir_list.erase(0, next_delimiter + 1);
            }
            return "/usr/local/share/OpMon/";
        }
    }

} // namespace Utils::Path
