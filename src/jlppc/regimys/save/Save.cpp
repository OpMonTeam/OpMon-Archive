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
    cout << outStr << endl;
    cout << hash << endl;
    outStream << outStr << intToChar(hash) << endl;
    outStream << hash;
    outStream.close();
}

Player *loadPlayer(std::string fileIn) {
    ifstream inStream(fileIn.c_str());
    string inStr;
    char actu = '\0';
    string verif = readLine(inStream);
    if(verif != "OP_SAVE"){
        return NULL;
    }
    string pname = readLine(inStream);
    Player *toReturn = new Player(pname);
    toReturn->load(inStream);
    int hash = inStream.get();
    inStream.close();
    /*inStream.open(fileIn.c_str());
    int i = 0;
    while(true){
        i++;
        actu = inStream.get();
        if(charToInt(actu) == hash){break;}
        //cout << actu;
        inStr+=actu;
        if(i >= 1000000){break;}
    }
    if(Utils::hash(inStr) != hash){//Sauvegarde modifiée
        cout << "NOPE!" << endl;
        cout << Utils::hash(inStr) << " != " << hash << endl;
        return NULL;
    }*///Protection par hash a revoir.
    return toReturn;

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
