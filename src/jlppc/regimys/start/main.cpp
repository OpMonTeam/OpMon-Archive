#include "main.hpp"

#if !defined(__cplusplus)
#error Mais quel crétin! Il est en C++ ce programme!
#endif

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <ctime>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../objects/item/Item.hpp"
#include "../objects/item/itemInclude.hxx"
#include "../playercore/Player.hpp"
#include "../playercore/Equipe.hpp"
#include "../evolution/evolutionInclude.hxx"
#include "../../utils/Class.hpp"
#include "../../utils/File.hpp"
#include "Initializer.hpp"
#include "StringKeys.hpp"
#include "../gui/MainFrame.hpp"

//#define DEBUG
UNS

#ifdef _WIN32
	ofstream rlog("logs\\log.txt");
	ofstream rerrLog("logs\\errLog.txt");
#else
	#define UNIX
	ofstream rlog("logs/log.txt");
	ofstream rerrLog("logs/errLog.txt");
#endif // WINDOWS


namespace Main {

	ostringstream oss;
	bool connected = false;
	string trainers[] = {"Brice", "Evan", "Mael", "Jlppc", "Red", "Blue", "Nikolai", "N", "Belladonis", "Aristote", "Giovanni", "Flora", "Silver", "Jules Cesar", "Gwendal", "Brahim"};
	float version = 0.07;
	int sousVers = 1;
	string versionS;
	extern Player joueur;
	extern RFile playerSave;
	extern RFile params;
    #ifdef _WIN32
        string sep = "\\";
    #else
        string sep = "/";
    #endif
    long startTime = time(NULL);


	int starts();


	int starts() {

		if (!rlog) {
			cout << "Erreur d'initialisation du log" << endl;

		}
		if (!rerrLog) {
			cout << "Erreur d'ouverture du log d'erreur" << endl;

		}
		if(!rerrLog && !rlog){
            system("mkdir logs");
            exit(-1);
		}
		startTime = time(NULL);
		rlog << "[T = " << time(NULL) - startTime << "] - Initialisation du log terminée." << endl;
		Initializer::init();
		MainFrame::open();

		return quit(0);
	}

}

void gererErreur(string errorName, bool fatal) {
	rerrLog << "Erreur : " << errorName << endl;
	if (fatal) {
		rerrLog << "Erreur fatale." << endl;
		rlog << PRINT_TICKS << "Crash." << endl;
		quit(1);
	}
}

int quit(int returne) {
	if (MainFrame::init) {
        TTF_Quit();
		atexit(IMG_Quit);
		SDL_Quit();
	}
	for (unsigned int i = 0; i < OP_NUMBER; i++) {
        if(Initializer::listeOp[i] != NULL){
            delete(Initializer::listeOp[i]);
        }

	}
	rlog << PRINT_TICKS << "Fermeture du jeu. Return " << returne << endl;
	rlog.close();
	rerrLog.close();


	#ifdef DEBUG
	system("pause");
	#endif // DEBUG
	exit(returne);
	return returne;
}

#include "../objects/Attaques.hpp"
#include "../save/Save.hpp"
int main(int argc, char *argv[])
{

	Main::oss << "Alpha " << Main::version << "." << Main::sousVers;
	Main::versionS = Main::oss.str();
	if (argc >= 2) {
		string str = argv[1];
		if (str == "--version") {
			cout << "OpMon Regimys version " << Main::versionS << endl;
			exit(0);
		} else if(str == "--test"){
            Player py = Player("Nom");
            Initializer::init();
            OpMon op1 = OpMon("Herbefolle", Initializer::listeOp[3], 10, new Charge(), new Acide(), Attaques::newAtk("Damocles"), NULL, Caractere::BIZARRE);
            OpMon op2 = OpMon(Initializer::listeOp[8]->getNom(), Initializer::listeOp[8], 10, Attaques::newAtk("Charge"), Attaques::newAtk("Acide"), Attaques::newAtk("Damocles"), NULL, Caractere::DOCILE);
            OpMon op3 = OpMon("Joker", Initializer::listeOp[10], 10, Attaques::newAtk("Charge"), Attaques::newAtk("Acide"), Attaques::newAtk("Damocles"), NULL, Caractere::SERIEUX);
            py.addOpMonToPC(op1);
            py.addOpToEquipe(op2);
            py.addOpToEquipe(op3);
            py.addItem(6);
            py.addItem(6);
            py.addItem(10);
            py.addItem(10);
            py.addItem(10);
            Save::save(&py, "save.osave");
		}
		else {
			cout << "Arguments ignorés, passage a la suite." << endl;
		}
	}
	return Main::starts();
}
