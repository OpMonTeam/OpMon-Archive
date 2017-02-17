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
