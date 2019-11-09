/*!
 * \file  Save.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 * \warning This file is to be redone completely. Therefore, it is not documented.
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
