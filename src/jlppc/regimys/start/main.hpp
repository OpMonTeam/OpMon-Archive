/*
main.hpp
Author : Jlppc
File under licence GNU GPL-3.0
http://opmon-game.ga
*/
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include "../../utils/File.hpp"
#include "../playercore/Player.hpp"
#include <sstream>
#include <SFML/System.hpp>


#define UNS using namespace std;
#define toStr(toStrP) #toStrP

#define FOR_EACH(arrType, arrName, sizeArr, bracket)			\
  for(int itor = 0; itor < (sizeArr); itor++) bracket			\
      arrType* currentObj = NULL;				       	\
      currentObj = &(arrName[itor]);

#define LOCAL_TEST

#define GET_TICKS ticks.getElapsedTime().asMilliseconds()

#ifndef _WIN32

#ifdef LOCAL_TEST

#define RESSOURCES_PATH std::string("resources/")
#define LOG_PATH std::string("logs/")
#define SAVE_PATH std::string("saves/")

#else

#define RESSOURCES_PATH std::string("/usr/share/OpMon/resources/")
#define LOG_PATH std::string("/usr/share/OpMon/logs/")
#define SAVE_PATH std::string("/usr/share/OpMon/saves/")

#endif

#else

#define RESSOURCES_PATH std::string("resources\\")
#define LOG_PATH std::string("logs\\")
#define SAVE_PATH std::string("saves\\")

#endif // _WIN32

#define PRINT_TICKS "[T = " << ticks.getElapsedTime().asMilliseconds() << "] - "

/**Principal log*/
extern std::ofstream rlog;
/**Error log*/
extern std::ofstream rerrLog;
/**Path to the options save file*/
extern std::string optSave;

extern sf::Clock ticks;

//#define TEST

void handleError(std::string const& errorName, bool fatal);

int quit(int const& returns);

class MainFrame;

namespace Main {
void main();
//->Useless
extern long startTime;
//  extern std::string sep;
// extern bool reboot;
extern Player player;

extern MainFrame mainframe;

}



int main(int argc, char *argv[]);

std::string& operator<<(std::string &str, std::string const& thing);
std::string& operator<<(std::string &str, int const& nbre);
std::string& operator<<(std::string &str, char nbre[]);

typedef unsigned int p_int;


#endif // MAIN_HPP
