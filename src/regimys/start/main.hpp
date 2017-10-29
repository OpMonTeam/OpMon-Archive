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
#include "defines.hpp"

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
