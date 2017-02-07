#include "File.hpp"

RFile::RFile(string path){
    this->path = path;
}

ifstream* File::getIn() const{
    return new ifstream(path.c_str());
}

ofstream* File::getOut() const{
    return new ofstream(path.c_str());
}
