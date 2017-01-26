#include "File.hpp"

File::File(string path){
    this->path = path;
}

ifstream* File::getIn(){
    return &ifstream(path);
}

ofstream* File::getOut(){
    return &ofstream(path);
}
