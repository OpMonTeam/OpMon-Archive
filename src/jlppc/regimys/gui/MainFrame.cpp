#include "MainFrame.hpp"
#include <iostream>
#include "../start/main.hpp"
#include <SDL/SDL.h>

using namespace std;

namespace MainFrame {
	SDL_Window *frame = NULL;
	SDL_Renderer *renderer = NULL;
	bool init = false;
	void open(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) == -1){
			Main::errLog << "Erreur d'initialisation de SDL." << endl;
			Main::log << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(SDL_GetError(), true);
		}
		init = true;
		frame = SDL_CreateWindow("Pokémon Regimys", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED);
		SDL_Delay(10000);
		SDL_DestroyWindow(frame);

		SDL_Quit();
	}

	void loop(){

	}
}
