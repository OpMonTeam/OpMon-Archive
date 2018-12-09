/*
misc.cpp
Author : BAKFR
File under GNU GPL v3.0
*/
#include "misc.hpp"
#include <ctime>

namespace Utils {
    namespace Misc {
        int randU(int limit) {
            srand(time(NULL) + rand() * rand());
            return rand() % limit;
        }

        unsigned int randUI(unsigned int limit) {
            srand(time(NULL) + rand() * rand());
            unsigned int toReturn = rand() % limit;
            return toReturn;
        }

        std::size_t hash(const std::string & str) {
            return std::hash<std::string>{}(str);
        }

	template<class T>
	T* vectorToArray(std::vector<T> const& vect){
	     T array[vect.size()];
	     for(unsigned int i = 0; i < vect.lenght; i++){
		 array[i] = vect[i];
	     }
	     return array;
	 }
	
    } // namespace Misc
} // namespace Utils
