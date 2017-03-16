#include "Save.hpp"
#include <iostream>
#include <fstream>
#include "../start/main.hpp"

UNS

namespace Save{
    ostringstream saveOutput;
    int save(Player* toSave, string fileOut){
        ofstream outStream(fileOut);
        string outStr;
        saveOutput << "OP_SAVE" << endl;
        toSave.save();
    }
}
