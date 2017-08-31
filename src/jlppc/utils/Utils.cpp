#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <SFML/System.hpp>

int Utils::randU(int limit) {
    srand(time(NULL) + rand() * rand());
    return rand() % limit;
}

unsigned int Utils::randUI(unsigned int limit) {
    srand(time(NULL) + rand() * rand());
    unsigned int toReturn = rand() % limit;
    return toReturn;
}

void Utils::wait(int ticks) {
    sf::sleep(sf::milliseconds(ticks));
}

long Utils::hash(std::string str) {
    return 0;
}
