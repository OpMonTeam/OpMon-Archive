/*
Save.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contient le namespace Save
*/
#ifndef SAVE_HPP
#define SAVE_HPP
#include "../playercore/Player.hpp"
#define SOUT Save::saveOutput
#include <fstream>

/**
Namespace contenant le nécessaire pour sauvegarder la partie
*/
namespace Save {
int save(Player *toSave, std::string const& fileOut);
Player *loadPlayer(std::string const& fileIn);
char intToChar(int toChar);
int charToInt(char toInt);
std::string readLine(std::ifstream &in);
extern std::ostringstream saveOutput;
}


#endif // SAVE_HPP
