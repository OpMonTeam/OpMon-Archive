#include "Comparaisons.hpp"

//ATTENTION ! : toCompare doit etre un TABLEAU!!!
template<typename T, typename U> bool Comparaisons::multiEgal(T const& object, U toCompare[], int tabLength){
    int i = 0;
    for(i = 0; i < tabLength; i++){
        if(object == toCompare[i]){
            return true;
        }
    }
    return false;
}
