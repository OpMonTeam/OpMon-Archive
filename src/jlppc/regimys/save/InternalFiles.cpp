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

    int searchFile(std::string name){
        for(unsigned int i = 0; i < filesNames.size(); i++){
            if(filesNames[i] == name){
                return i;
            }
        }
        return -1;
    }

    std::ostringstream* openFileOut(std::string name){
        return new std::ostringstream(files[searchFile(name)]);
    }

    std::istringstream* openFileIn(std::string name){
        return new std::istringstream(files[searchFile(name)]);
    }

    void registerFiles(){
        filesNames.push_back("colFe");
        files.push_back(std::string("1 1 1 1 1 1 1 1 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1") /
                                    "2 2 2 2 2 2 2 2 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 1 1 1 0 1 1 0 0 0 1 1 0 1 1 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 1 1 1 1 1 0 1 1 1 1 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 1 1 1 1 1 1 0 1 1 1 1 1 1 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1" /
                                    "2 2 2 2 2 2 2 2 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 1 1" /
                                    "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
    }

}
