#include "Save.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include "../../start/main.hpp"
#include "../../../utils/defines.hpp"
#include "src/utils/misc.hpp"

UNS

namespace OpMon{
  namespace Model{
    namespace Save {
      ostringstream saveOutput;
      int save(Player *toSave, string const& fileOut) {
	//Ouverture du flux de sauvegarde
	ofstream outStream(fileOut.c_str());
	string outStr;
	//Indique que c'est bien une sauvegarde de OpMon
	saveOutput << "OP_SAVE" << endl;
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

      Player *loadPlayer(std::string const& fileIn) {
	//Ouverture des flux de chargement
	ifstream inStream(fileIn.c_str());
	string inStr;
	//char actu = '\0';
	string verif = readLine(inStream);
	if(verif != "OP_SAVE") {//Vérification de la validité du fichier de sauvegarde
	  return nullptr;
	}
	//Lecture des objets
	string pname = readLine(inStream);
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
	  }*///J'ai pas encore mis d'algorithme de hash dans le programme
	return toReturn;

      }

      int charToInt(char toInt) {
	return toInt;
      }
      char intToChar(int toChar) {
	return toChar;
      }

      std::string readLine(std::ifstream &in) {
	string toReturn("");
	char actu = '\0';
	while(true) {//Lit la chaine caractère par caractère
	  actu = in.get();
	  if(actu == '\n') {
            break;
	  }
	  toReturn+=actu;

	}
	return toReturn;
      }

    }
  }
}
