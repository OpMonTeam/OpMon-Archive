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

#include "../playercore/Player.hpp"
#include "defines.hpp"

namespace OpMon{

class MainFrame;
/**
   Namespace containing the main contents of the game
*/
namespace Main {
/**
   The game's main
*/
void main();
/**
   Contains the frame, and all the elements
*/
extern MainFrame mainframe;
}
  
}

/**
   Don't you know what this is?
*/
int main(int argc, char *argv[]);

//->Unused (I don't know why.)
typedef unsigned int p_int;


#endif // MAIN_HPP
