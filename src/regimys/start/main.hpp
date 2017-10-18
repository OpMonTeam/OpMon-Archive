/*
main.hpp
Author : Jlppc
File under licence GNU GPL-3.0
http://opmon-game.ga
*/
#ifndef MAIN_HPP
#define MAIN_HPP

#ifndef __cplusplus
#error This is a C++ program!
#endif

#include <iostream>
#include <fstream>
#include "log.hpp"
#include "../../utils/File.hpp"
#include "../playercore/Player.hpp"
#include <sstream>
#include <SFML/System.hpp>

#define OP_DEPRECATED __attribute__ ((deprecated))

/**
Shortcuts
*/
#define UNS using namespace std;
#define toStr(toStrP) #toStrP

/**
Equivalent of for(var : array) but with an iterator and a pointer.
*/
#define FOR_EACH(arrType, arrName, sizeArr, bracket)			\
  for(int itor = 0; itor < (sizeArr); itor++) bracket			\
      arrType* currentObj = nullptr;				       	\
      currentObj = &(arrName[itor]);
/**
Linux only. If defined, the program will search for the resources on the local directory, instead of /usr/share/OpMon
*/
#define LOCAL_TEST
/**
Return how many time in milliseconds the program is open
*/
#define GET_TICKS ticks.getElapsedTime().asMilliseconds()
/*
This code define the location of the logs, saves and resources folders.
*/
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
/**
Use in a stream with the << operator. Prints the number of milliseconds passed since the beginning of the game.
*/

/**Path to the options save file*/
extern std::string optSave;
/**
sf::Clock counting the number of milliseconds passed since the beginning of the program
*/
extern sf::Clock ticks;
/**
Returns the path depending of the system.
By default, please use the "/" separator.
Then, if the os is Windows, this function will change the "/" by "\".
If you use the "\" separator in the path given,
nothing will change, on unix systems and on Windows systems.
*/
std::string getPath(std::string const& path);

//#define TEST
/**
Function that handles errors on the program
*/
void handleError(std::string const& errorName, bool fatal);
/**
Function quitting the game, deleting the resources
*/
int quit(int const& returns);

class MainFrame;
/**
Namespace containing the main contents of the game
*/
namespace Main {
/**
   The game's main
*/
void main();
//->Useless (I should delete this variable, but I need to check some things first)
extern long startTime;
//  extern std::string sep;
// extern bool reboot;
/**
   Contains the player
*/
extern Player player;
/**
   Contains the frame, and all the elements
*/
extern MainFrame mainframe;



}

// Create a directory (if it doesn't exist yet)
bool mkdir(const std::string &path);


/**
Don't you know what this is?
*/
int main(int argc, char *argv[]);

/*
Useful operators for strings
*/
std::string& operator<<(std::string &str, std::string const& thing);
std::string& operator<<(std::string &str, int const& nbre);
std::string& operator<<(std::string &str, char nbre[]);
//->Unused (I don't know why.)
typedef unsigned int p_int;


#endif // MAIN_HPP
