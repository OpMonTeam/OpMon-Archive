#include "ustring.hpp"

using namespace std;

ustring::ustring(string &otherstring) : string(otherstring){
}

ustring::ustring(char *tab) : string(tab){
}

basic_string& operator+=(char toAdd){
    if(toAdd == 'è'){

    }
}
