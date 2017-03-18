#include "Utils.hpp"
#include <iostream>

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

long Utils::hash(std::string str){
    int code = 42;//Life and universe!
    int othercode = 56;//Get the reference
    int thirdcode = str[0];
    long hash = 12;
    for(unsigned int i = 0; i < str.size();i++){
        hash += (str[i] * code + (hash/othercode) / str[0]);
    }
    return hash;
}
