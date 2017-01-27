#include "Comparaisons.hpp"

template<typename T> bool multiEgal(T object, T toCompare[], int tabLength){
    int i = 0;
    for(i = 0; i < tabLength; i++){
        if(object == toCompare[i]){
            return true;
        }
    }
    return false;
}
