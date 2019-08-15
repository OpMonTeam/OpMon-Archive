/*
Save.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v30 license
*/
#include "Save.hpp"
#include "../../../utils/defines.hpp"
#include "../../../utils/misc.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

namespace OpMon {
    namespace Model {
        namespace Save {
            std::ostringstream saveOutput;
            int save(Player *toSave, std::string const &fileOut) {
                std::ofstream outStream(fileOut.c_str());
                std::string outStr;
                //Indicate that the file is an OpMon save file
                saveOutput << "OP_SAVE" << std::endl;
                toSave->save();
                outStr = SOUT.str();
                outStream.close();
                return 0;
            }

            Player *loadPlayer(std::string const &fileIn) {
                std::ifstream inStream(fileIn.c_str());
                std::string inStr;
                std::string verif = readLine(inStream);
                if(verif != "OP_SAVE") { //Checks if the file is an OpMon save file
                    return nullptr;
                }
                //Reading objects
                std::string pname = readLine(inStream);
                Player *toReturn = new Player(inStream, pname);
                inStream.close();
                return toReturn;
            }

            int charToInt(char toInt) {
                return toInt;
            }
            char intToChar(int toChar) {
                return toChar;
            }

            std::string readLine(std::ifstream &in) {
                std::string toReturn("");
                char actu = '\0';
                while(true) { //Reads the file character by character
                    actu = in.get();
                    if(actu == '\n') {
                        break;
                    }
                    toReturn += actu;
                }
                return toReturn;
            }

        } // namespace Save
    }     // namespace Model
} // namespace OpMon
