#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include "../../utils/File.hpp"
#include "../playercore/Player.hpp"
#include <sstream>

#define WINDOWS


using namespace std;

void gererErreur(string errorName, bool fatal);
    int quit(int retourne);

namespace Main{


}
int main(int argc, char *argv[]);
void initStatic(void);

#endif // MAIN_HPP
