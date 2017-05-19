#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

int Utils::randU(int limit) {
    srand(time(NULL));
    return rand() % limit;
}

unsigned int Utils::randUI(unsigned int limit) {
    srand(time(NULL));
    unsigned int toReturn = rand() % limit;
    return toReturn;
}

void Utils::wait(int ticks) {
    sf::sleep(sf::milliseconds(ticks));
}

long Utils::hash(std::string str) {
    int code = 42;//Life and universe!
    int othercode = 56;//Get the reference
    long hash = 12;
    for(unsigned int i = 0; i < str.size(); i++) {
        hash += (str[i] * code + (hash/othercode));
    }
    return hash;
}
