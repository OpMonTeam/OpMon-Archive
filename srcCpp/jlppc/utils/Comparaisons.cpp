#include "Comparaisons.hpp"

template<typename T> bool multiEgal(T const& object, T const& toCompare[]) const{
    int i = 0;
    for(i = 0; i < toCompare; i++){
        if(object == toCompare[i]){
            return true;
        }
    }
    return false;
}
