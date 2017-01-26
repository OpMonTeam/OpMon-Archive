#include "Utils.hpp"

int Utils::randU(int limit){
    srand(time(NULL));
    return rand()%limit;
}
