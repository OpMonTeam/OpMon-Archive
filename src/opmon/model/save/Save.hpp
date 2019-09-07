/*
Save.hpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v30 license
*/
#ifndef SAVE_HPP
#define SAVE_HPP
#include "../sysObjects/Player.hpp"
#define SOUT Save::saveOutput
#include <fstream>

namespace OpMon::Model::Save {
    int save(Player *toSave, std::string const &fileOut);
    Player *loadPlayer(std::string const &fileIn);
    char intToChar(int toChar);
    int charToInt(char toInt);
    std::string readLine(std::ifstream &in);
    extern std::ostringstream saveOutput;
} // namespace OpMon::Model::Save

#endif // SAVE_HPP
