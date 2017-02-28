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
	ofstream rlog = ofstream("logs/log.txt");
	ofstream rerrLog = ofstream("logs/errLog.txt")
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
            #ifdef _WIN32
            system("mkdir logs");
            #else
            system("md logs");
            #endif // _WIN32
            exit(-1);
		}
		startTime = time(NULL);
		rlog << "[T = " << time(NULL) - startTime << "] - Initialisation du log terminée." << endl;
		StringKeys::initialize();
		MainFrame::open();

		return quit(0);
	}

}

void gererErreur(string errorName, bool fatal) {
	rerrLog << "Erreur : " << errorName << endl;
	if (fatal) {
		rerrLog << "Erreur fatale." << endl;
		quit(1);
	}
}

int quit(int returne) {
	if (MainFrame::init) {
        TTF_Quit();
		atexit(IMG_Quit);
		SDL_Quit();
	}
	rlog << "[T = " << SDL_GetTicks() << "] - Fermeture du jeu." << endl;
	rlog.close();
	rerrLog.close();

	/*for (unsigned int i = 0; i < POKE_NUMBER; i++) {
		delete(Initializer::listePoke[i]);
	}*/
	#ifdef DEBUG
	system("pause");
	#endif // DEBUG
	exit(returne);
	return returne;
}


int main(int argc, char *argv[])
{

	Main::oss << "Alpha " << Main::version << "." << Main::sousVers;
	Main::versionS = Main::oss.str();
	if (argc >= 2) {
		string str = argv[1];
		if (str == "--version") {
			cout << "Pokémon Regimys version " << Main::versionS << endl;
			exit(0);
		} else {
			cout << "Arguments ignorés, passage a la suite." << endl;
		}
	}
	return Main::starts();
}
