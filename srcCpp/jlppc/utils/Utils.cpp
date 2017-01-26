#include "Utils.hpp"

Utils::limit(int limit){
    srand(time(NULL));
    return rand()%limit;
}
