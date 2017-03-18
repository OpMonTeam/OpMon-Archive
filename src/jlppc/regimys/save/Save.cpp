#include "Save.hpp"
#include <iostream>
#include <fstream>
#include "../start/main.hpp"
#include "../../utils/Utils.hpp"

UNS

namespace Save{
    ostringstream saveOutput;
    int save(Player* toSave, string fileOut){
        ofstream outStream(fileOut.c_str());
        string outStr;
        saveOutput << "OP_SAVE" << endl;
        toSave->save();
        outStr = SOUT.str();
        long hash = Utils::hash(outStr);
        outStream << outStr << hash;
    }

    int charToInt(char toInt) {return toInt;}
    char intToChar(int toChar) {return toChar;}
}
