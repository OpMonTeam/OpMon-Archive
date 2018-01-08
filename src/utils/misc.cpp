#include "misc.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <SFML/System.hpp>


namespace Utils {
  namespace Misc {
    int randU(int limit){
      srand(time(NULL) + rand() * rand());
      return rand() % limit;
    }

    unsigned int randUI(unsigned int limit){
      srand(time(NULL) + rand() * rand());
      unsigned int toReturn = rand() % limit;
      return toReturn;
    }


    long hash(const std::string &){
      return 0;
    }

  }
}
