#include "Save.hpp"
#include <iostream>
#include <fstream>
#include "../start/main.hpp"
#include "../../utils/Utils.hpp"

UNS

namespace Save {
ostringstream saveOutput;
int save(Player* toSave, string fileOut) {
    ofstream outStream(fileOut.c_str());
    string outStr;
    saveOutput << "OP_SAVE" << endl;
    toSave->save();
    outStr = SOUT.str();
    long hash = Utils::hash(outStr);
    outStream << outStr << intToChar(hash) << endl;
    outStream << hash;
    outStream.close();
}

Player *loadPlayer(std::string fileIn) {
    ifstream inStream(fileIn.c_str());
    string inStr;
    string pname = readLine(inStream);
    Player toReturn = Player(pname);
    toReturn.load(inStream);

}

int charToInt(char toInt) {
    return toInt;
}
char intToChar(int toChar) {
    return toChar;
}

std::string readLine(std::ifstream &in){
    string toReturn("");
    char actu = '\0';
    while(true){
        actu = in.get();
        if(actu == '\n'){break;}
        toReturn+=actu;

    }
    return toReturn;
}

}
