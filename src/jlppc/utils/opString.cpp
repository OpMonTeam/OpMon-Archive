#include "opString.hpp"
#include <sstream>

using namespace std;

opString::opString() : string(""){}

opString::opString(string str) : string(str){}

opString::opString(char *tab) : string(tab){}

opString::opString(char uniqueChar) : string(""){
    this->push_back(uniqueChar);
}

opString::opString(int *intTab, int lenght) : string(""){
    for(unsigned int i = 0; i < lenght; i++){
        char chare = intTab[i];
        this->push_back(chare);
    }
}

opString::opString(int lenght) : string(""){
    for(unsigned int i = 0; i < lenght; i++){
        this->push_back(' ');
    }
}

std::string opString::toString() const{
    return string(this->c_str());
}

opString& operator<<=(opString &str, std::string sstr){
    ostringstream oss;
    oss << str;
    oss << sstr;
    str = oss.str();
    return str;
}

opString& operator<<=(opString &str, char *toAdd){
    return (str <<= opString(toAdd));
}

opString& operator<<=(opString &str, char toAdd){
    return (str <<= opString(toAdd));
}

opString& operator<<=(opString &str, int toAdd){
    int tab[] = {toAdd};
    return (str <<= opString(tab, 1));
}

opString& operator<<=(opString &str, opString toAdd){
    str+=toAdd;
    return str;
}

opString operator<<(opString const& str, std::string sstr){
    ostringstream oss;
    oss << str;
    oss << sstr;
    opString str2 = opString(oss.str());
    return str2;
}

opString operator<<(opString const& str, char *toAdd){
    return (str << opString(toAdd));
}

opString operator<<(opString const& str, char toAdd){
    return (str << opString(toAdd));
}

opString operator<<(opString const& str, int toAdd){
    int tab[] = {toAdd};
    return (str << opString(tab, 1));
}

opString operator<<(opString const& str, opString toAdd){
    opString str2 = str + toAdd;
    return str2;
}

opString opString::operator+(opString const& toAdd) const{
    return opString(this->toString() + toAdd.toString());
}

opString& opString::operator+=(opString const& toAdd){
    string str = toAdd.toString() + toAdd.toString();
    return opString(str);
}



