#include "Utils.hpp"

int Utils::randU(int limit) {
	srand(time(NULL));
	return rand() % limit;
}

unsigned int Utils::randUI(unsigned int limit) {
	srand(time(NULL));
	unsigned int toReturn = rand() % limit;
	return toReturn;
}

void Utils::wait(int ticks){
    for(int i = 0; i < ticks; i++){}
}
