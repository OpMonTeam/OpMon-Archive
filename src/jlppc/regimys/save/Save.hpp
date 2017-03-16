#ifndef SAVE_HPP
#define SAVE_HPP
#include "../playercore/Player.hpp"
#define SOUT Save::saveOutput

namespace Save{
    int save(Player* toSave, std::string fileOut);
    Player *loadPlayer(std::string fileIn);
    char intToChar(int toChar);
    int charToInt(char toInt);
    extern std::ostringstream saveOutput;
}


#endif // SAVE_HPP
