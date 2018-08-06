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
                //Ouverture du flux de sauvegarde
                std::ofstream outStream(fileOut.c_str());
                std::string outStr;
                //Indique que c'est bien une sauvegarde de OpMon
                saveOutput << "OP_SAVE" << std::endl;
                toSave->save();
                outStr = SOUT.str();
                /*
	  long hash = Utils::hash(outStr);
	  cout << outStr << endl;
	  cout << hash << endl;
	  outStream << outStr << intToChar(hash) << endl;
	  outStream << hash;*/
                //J'ai pas encore mis d'algorithme de hash dans le programme
                //Fermeture du flux
                outStream.close();
                return 0;
            }

            Player *loadPlayer(std::string const &fileIn) {
                //Ouverture des flux de chargement
                std::ifstream inStream(fileIn.c_str());
                std::string inStr;
                //char actu = '\0';
                std::string verif = readLine(inStream);
                if(verif != "OP_SAVE") { //Vérification de la validité du fichier de sauvegarde
                    return nullptr;
                }
                //Lecture des objets
                std::string pname = readLine(inStream);
                Player *toReturn = new Player(inStream, pname);
                //int hash = inStream.get();
                //Fermeture du flux
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
	  return nullptr;
	  }*/
                //J'ai pas encore mis d'algorithme de hash dans le programme
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
                while(true) { //Lit la chaine caractère par caractère
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
