#ifndef SAVE_HPP
#define SAVE_HPP
#include "../playercore/Player.hpp"

namespace Save{
    int save(Player* toSave, std::string fileOut);
    Player *loadPlayer(std::string fileIn);
    char intToChar(int toChar) {return toChar;}
    int charToInt(char toInt) {return toInt;}
    extern std::ostringstream saveOutput;
}


#endif // SAVE_HPP
