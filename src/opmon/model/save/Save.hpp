/*
Save.hpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v30 license
*/
#ifndef SAVE_HPP
#define SAVE_HPP
#include "../sysObjects/Player.hpp"
#define SOUT Save::saveOutput
#include <fstream>

namespace OpMon {
    namespace Model {

        namespace Save {
            int save(Player *toSave, std::string const &fileOut);
            Player *loadPlayer(std::string const &fileIn);
            char intToChar(int toChar);
            int charToInt(char toInt);
            std::string readLine(std::ifstream &in);
            extern std::ostringstream saveOutput;
        } // namespace Save
    }     // namespace Model
} // namespace OpMon

#endif // SAVE_HPP
