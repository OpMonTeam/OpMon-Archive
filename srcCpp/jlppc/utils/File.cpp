#include "File.hpp"

File::File(string path){
    this->path = path;
}

File::getIn(){
    return &ifstream(path);
}

File::getOut(){
    return &ofstream(path);
}
