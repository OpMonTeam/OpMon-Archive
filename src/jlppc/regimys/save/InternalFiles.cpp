#include "InternalFiles.hpp"

std::string operator/(const char str1[], std::string const& str2){
    return std::string(str1) + "\n" + str2;
}

std::string operator/(std::string const& str1, const char str2[]){
    return str1 + "\n" + std::string(str2);
}

std::string operator/(std::string const& str1, std::string const& str2){
    return str1 + "\n" + str2;
}

namespace InternalFiles{
    std::vector<std::string> filesNames;
    std::vector<std::string> files;

    void registerFiles(){
        filesNames.push_back("colFe");
        files.push_back(std::string("1 1 1 1 1 1 1 1 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1") /
                        "2 2 2 2 2 2 2 2 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1" /
                        "");
    }

}
