#include "MainFrame.hpp"
#include <iostream>
#include "../start/main.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <cstring>
#include "../start/StringKeys.hpp"
#include "../start/main.hpp"
#include <string>
#include <SDL/SDL_mixer.h>

#define rLog rlog
#define charLineDialog 33
#define kget StringKeys::get

#define QUITF continuer=false;\
    Mix_PauseMusic();\
	SDL_DestroyTexture(textUre);\
	SDL_DestroyTexture(dialogT);\
	SDL_DestroyTexture(profT);\
	SDL_DestroyTexture(fondT);\
	Mix_FreeMusic(fondMus);\
	return;

#define QUIT case SDL_QUIT:\
	QUITF//Un macro compos� de macro. :D

#define ECHAP case SDLK_ESCAPE:\
	QUITF

#define JOYQUIT case 7:\
	QUITF

#define DIALOG_PASS(varname) if (changeDialog == false) {\
		txtEnCours[0] = txtP##varname[dialog];\
		txtEnCours[1] = txtP##varname[dialog + 1];\
		txtEnCours[2] = txtP##varname[dialog + 2];\
		printText(renderer, txtEnCours[0], txtEnCours[1], txtEnCours[2]);\
		changeDialog = true;\
		SDL_Delay(50);\
	} else if (!(dialog + 3 >= sizeOfTxt)) {\
        Mix_PlayChannel(1, dialogPass, 0);\
		line = 0;\
		dialog++;\
		dialog++;\
		dialog++;\
		i = 0;\
		txtEnCours[0] = string(" ");\
		txtEnCours[1] = string(" ");\
		txtEnCours[2] = string(" ");\
		changeDialog = false;\
	}else{\
		phase = 1;\
	}\
	break;

#define ANIM_ARROW 		arrDialP.y = arrDialP.y + 1;\
	if (arrDialP.y - (512 - 30) > 5) {\
		arrDialP.y = arrDialP.y - 6;\
	}\
	SDL_RenderCopy(renderer, arrDial, NULL, &arrDialP);

UNS

namespace MainFrame {
	SDL_Window *frame = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Event events;
	TTF_Font *font = NULL;
	SDL_Rect dialogP = {0, 0, 0, 0};
	SDL_Texture *dialogT = NULL;
	SDL_Rect textPlace = {0, 0, 0, 0};
	SDL_Color noir = {0, 0, 0};
	SDL_Color blanc = {255, 255, 255};
	SDL_Joystick *manette = NULL;
	Mix_Chunk *dialogPass = NULL;
	bool init = false;

	int printText(SDL_Renderer *renderer, string txt, string line2S, string line3S) {
		SDL_Texture *textUre = NULL;
		SDL_Surface *sfce = NULL;
		SDL_Texture *line2 = NULL;
		SDL_Surface *sfce2 = NULL;
		SDL_Texture *line3 = NULL;
		SDL_Surface *sfce3 = NULL;
		SDL_Rect posLineTwo;
		SDL_Rect posLineThree;

        if(txt == "" || line2S == "" || line3S == ""){
            gererErreur("Chaine de caract�re vide (fonction MainFrame::printText)", true);
        }


		sfce = TTF_RenderText_Blended(font, txt.c_str(), noir);
		textPlace.h = sfce->h;
		textPlace.w = sfce->w;
		textUre = SDL_CreateTextureFromSurface(renderer, sfce);


		sfce2 = TTF_RenderText_Blended(font, line2S.c_str(), noir);
		posLineTwo.h = sfce2->h;
		posLineTwo.w = sfce2->w;
		posLineTwo.x = textPlace.x;
		posLineTwo.y = textPlace.y + 32;
		line2 = SDL_CreateTextureFromSurface(renderer, sfce2);

		sfce3 = TTF_RenderText_Blended(font, line3S.c_str(), noir);
		posLineThree.h = sfce3->h;
		posLineThree.w = sfce3->w;
		posLineThree.x = textPlace.x;
		posLineThree.y = textPlace.y + 32 + 32;
		line3 = SDL_CreateTextureFromSurface(renderer, sfce3);

		SDL_RenderCopy(renderer, line3, NULL, &posLineThree);
		SDL_RenderCopy(renderer, line2, NULL, &posLineTwo);
		SDL_RenderCopy(renderer, textUre, NULL, &textPlace);
		SDL_DestroyTexture(line3);
		SDL_DestroyTexture(textUre);
		SDL_DestroyTexture(line2);
		SDL_FreeSurface(sfce);
		SDL_FreeSurface(sfce2);
		SDL_FreeSurface(sfce3);
		return 0;
	}

	void open() {
		//Initialisations
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) == -1) {
			rerrLog << "Erreur d'initialisation de SDL." << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(SDL_GetError(), true);
		}

		if (IMG_Init(IMG_INIT_PNG) < 0) {
			rerrLog << "Erreur d'initialisation de SDL_Image" << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(IMG_GetError(), true);

		}

		if (TTF_Init() == -1) {
			rerrLog << "Erreur d'initialisation de SDL_ttf" << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(TTF_GetError(), true);
		}
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1){
            rerrLog << "Erreur d'initilisation de SDL_Mixer" << endl;
            gererErreur(Mix_GetError(), true);
        }
		//Ouverture de la police
		rlog << PRINT_TICKS << "Initialisation des SDL termin�e" << endl;
#ifdef _WIN32
		font = TTF_OpenFont("ressources\\fonts\\arial.ttf", 28);
#else
		font = TTF_OpenFont("ressources/fonts/arial.ttf", 28);
#endif

		if (font == NULL) {
			rerrLog << "Erreur d'initialisation de la police d'�criture." << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(TTF_GetError(), true);
		}
		rlog << PRINT_TICKS << "Initialisation de la police termin�e" << endl;


		//Annonce que l'initialisation principale est termin�e
		init = true;
		//Ouverture de la fenetre
		frame = SDL_CreateWindow("OpenMon Lazuli", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
		//Cr�ation du renderer.
		renderer = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED);
		if (frame == NULL || renderer == NULL) {
			rerrLog << "Erreur d'ouverture de la fenetre ou du renderer." << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(SDL_GetError(), true);
		}
		rlog << PRINT_TICKS << "Initialisation de la fenetre et du renderer termin�e" << endl;
		//Ouverture de la manette (Je sais pas si ca se dit "ouverture de la manette mais c'est pas grave)
		manette = SDL_JoystickOpen(0);
		if (manette == NULL) {
			gererErreur("Aucune manette d�tect�e", false);
		} else {
			rlog << PRINT_TICKS << "Initialisation du joystick termin�e" << endl;
		}
		Mix_AllocateChannels(3);
		#ifdef _WIN32
		dialogPass = Mix_LoadWAV("ressources\\audio\\sounds\\dialogChange.ogg");
        #else
        dialogPass = Mix_LoadWAV("ressources/audio/sounds/dialogChange.ogg");
        #endif
        if(dialogPass == NULL){
            gererErreur(Mix_GetError(), false);
        }
        Mix_Volume(1, MIX_MAX_VOLUME - 1);
		startScene();

		rlog << PRINT_TICKS << "Fermeture de la fenetre" << endl;

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(frame);
		SDL_JoystickClose(manette);
		TTF_CloseFont(font);
		Mix_FreeChunk(dialogPass);

        Mix_CloseAudio();
		TTF_Quit();
		atexit(IMG_Quit);
		SDL_Quit();
	}

	void startScene() {
		//D�claration des SDL_Rect et des SDL_Texture secondaires, necessaires a cette scene
		SDL_Rect fondP;
		SDL_Rect profP;
		SDL_Texture *fondT;
		SDL_Texture *profT;
		SDL_Texture *arrDial;
		SDL_Rect arrDialP;
		#ifdef _WIN32
		Mix_Music *fondMus = Mix_LoadMUS("ressources\\audio\\music\\intro.ogg");
		#else
        Mix_Music *fond = Mix_LoadMUS("ressources/audio/music/intro.ogg");
		#endif
		if(fondMus == NULL){
            gererErreur(Mix_GetError(), false);
		}
		Mix_PlayMusic(fondMus, -1);
		Mix_VolumeMusic(MIX_MAX_VOLUME / 32);

		//Initialisation des tailles
		rlog << PRINT_TICKS << "Initialisation des SDL_Rect" << endl;
		fondP.h = 512;
		fondP.w = 512;
		fondP.x = 0;
		fondP.y = 0;
		dialogP.h = 150;
		dialogP.w = 512;
		dialogP.x = 0;
		dialogP.y = 362;
		profP.h = (300 / 3) * 2;
		profP.w = (180 / 3) * 2;
		profP.x = (fondP.w / 2) - (profP.w / 2) + 10;
		profP.y = ((fondP.h - dialogP.h) / 2) - (profP.h / 2) + 50;
		textPlace.x = 20;
		textPlace.y = 382;
		arrDialP.x = 512 - 75;
		arrDialP.y = 512 - 30;
		arrDialP.h = 10;
		arrDialP.w = 10;
		noir.r = 0;
		noir.g = 0;
		noir.b = 0;
		//Initialisation des images
		rlog << "[T = " << SDL_GetTicks() << "] - Initialisation des sprites..." << endl;
#ifdef _WIN32
		fondT = IMG_LoadTexture(renderer, "ressources\\backgrounds\\start\\startscene.png");
		profT = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\jlppc\\jlppc.png");
		dialogT = IMG_LoadTexture(renderer, "ressources\\backgrounds\\dialog\\dialog.png");
		arrDial = IMG_LoadTexture(renderer, "ressources\\sprites\\misc\\arrDial.png");
#else
		fondT = IMG_LoadTexture(renderer, "ressources/backgrounds/start/startscene.png");
		profT = IMG_LoadTexture(renderer, "ressources/sprites/chara/jlppc/jlppc.png");
		dialogT = IMG_LoadTexture(renderer, "ressources/backgrounds/dialog/dialog.png");
		arrDial = IMG_LoadTexture(renderer, "ressources/sprites/misc/arrDial.png");
#endif
		//Vesrification des probl�mes possibles
		if (fondT == NULL || profT == NULL || dialogT == NULL) {
			gererErreur(string("Erreur lors de l'initialisation d'une image.") + string(SDL_GetError()), false);
		}

		if (SDL_RenderCopy(renderer, fondT, NULL, &fondP) == -1) {
			rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
			gererErreur(SDL_GetError(), false);
		}
		if (SDL_RenderCopy(renderer, profT, NULL, &profP) == -1) {
			rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
		}
		if (SDL_RenderCopy(renderer, dialogT, NULL, &dialogP) == -1) {
			rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
		}
		//Initialisation des variables utiles pour la boucle
		SDL_RenderPresent(renderer);
		rlog << "[T = " << SDL_GetTicks() << "] - Fin des initialisations" << endl;
		rlog << "[T = " << SDL_GetTicks() << "] - Creation des variables utilitaires" << endl;
		bool continuer = true;
		long ancientTick = 0;
		//Phase 0
		string txtP0[] = {kget("jlppc.dialog.start.1"), kget("jlppc.dialog.start.2"), kget("jlppc.dialog.start.3"), kget("jlppc.dialog.start.4"), kget("jlppc.dialog.start.5"), kget("jlppc.dialog.start.6"), kget("jlppc.dialog.start.7"), kget("jlppc.dialog.start.8"), kget("jlppc.dialog.start.9")};//Deux cases == Deux lignes. 3 cases == Deux lignes + un nouveau dialogue
		//Phase 1
		//TODO
		int sizeOfTxt = 9;
		string txtEnCours[] = {string(" "), string(" "), string(" ")};
		SDL_Texture *textUre = NULL;
		SDL_Surface *sfce = NULL;
		int line = 0, i = 0, dialog = 0;
		bool changeDialog = false;
		int phase = 0;
		bool joypressed = false;

		rlog << "[T = " << SDL_GetTicks() << "] - D�but de la boucle n�0" << endl;
		//Boucle n�1
		while (continuer) {
			if ((SDL_GetTicks() - ancientTick) >= 41) {

				ancientTick = SDL_GetTicks();

				SDL_PollEvent(&events);

				switch (events.type) {

						QUIT

					case SDL_KEYDOWN:
						switch (events.key.keysym.sym) {
							case SDLK_SPACE:
								DIALOG_PASS(0)

								ECHAP
						}
						break;

					case SDL_JOYBUTTONDOWN:
						if (!joypressed) {
							joypressed = true;
							switch (events.jbutton.button) {

								case 0:
									DIALOG_PASS(0)


									JOYQUIT
							}
						}
						break;

						/*case SDL_WINDOWEVENT:
							switch (events.window.event) {
								case SDL_WINDOWEVENT_RESIZED:
									break;
							}
							break;*/
				}


				if (phase == 0) {
					if (SDL_RenderCopy(renderer, fondT, NULL, &fondP) == -1) {
						rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
						gererErreur(SDL_GetError(), false);
					}
					if (SDL_RenderCopy(renderer, profT, NULL, &profP) == -1) {
						rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
						gererErreur(SDL_GetError(), false);
					}
					if (SDL_RenderCopy(renderer, dialogT, NULL, &dialogP) == -1) {
						rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
						gererErreur(SDL_GetError(), false);
					}
					if (!changeDialog) {

						if (!(i >= txtP0[line + dialog].size())) {

							if (txtEnCours[line] == " ") {
								txtEnCours[line] = txtP0[line + dialog].c_str()[i];
							} else {
								txtEnCours[line] += txtP0[line + dialog].c_str()[i];
							}

							i++;
						} else {
							if (line == 2) {
								changeDialog = true;
							} else {
								line++;
								i = 0;
							}
						}





					}
					printText(renderer, txtEnCours[0], txtEnCours[1], txtEnCours[2]);
					ANIM_ARROW
					SDL_RenderPresent(renderer);
				} else {
					break;
				}


			} else {
				SDL_Delay(41 - (SDL_GetTicks() - ancientTick));
			}

		}
		continuer = true;
		SDL_Texture *anim[6];
		SDL_Rect animP;
		animP.h = 512;
		animP.w = 512;
		animP.x = 0;
		animP.y = 0;

		for (int i = 0; i < 6; i++) {
			if ((SDL_GetTicks() - ancientTick) >= 200) {
				SDL_PollEvent(&events);

				switch (events.type) {
						QUIT

					case SDL_KEYDOWN:
						switch (events.key.keysym.sym) {
								ECHAP
						}

						break;

					case SDL_JOYBUTTONDOWN:
						if (!joypressed) {
							joypressed = true;
							switch (events.jbutton.button) {
									JOYQUIT
							}
						}



						break;
					case SDL_JOYBUTTONUP:
						joypressed = false;
						break;
				}

				ostringstream oss;

#ifdef _WIN32
				oss << "ressources\\animations\\winChange\\animWindowFrame" << i + 1 << ".png";
#else
				oss << "ressources/animations/winChange/animWindowFrame" << i + 1 << ".png";
#endif // _WIN32

				anim[i] = IMG_LoadTexture(renderer, oss.str().c_str());
				SDL_RenderCopy(renderer, anim[i], NULL, &animP);
				SDL_RenderPresent(renderer);
				SDL_DestroyTexture(anim[i]);
			} else {
				SDL_Delay(200 - (SDL_GetTicks() - ancientTick));
				i--;
			}
		}
		phase = 1;
		rlog << "[T = " << SDL_GetTicks() << "] - Chargement de la boucle n�1" << endl;
		char pName[16] = "               ";
		int k = 0;
#ifdef _WIN32
		SDL_Texture *fondNE = IMG_LoadTexture(renderer, "ressources\\backgrounds\\start\\nameEntry.png");
#else
		SDL_Texture *fondNE = IMG_LoadTexture(renderer, "ressources/backgrounds/start/nameEntry.png");
#endif
		if (fondNE == NULL) {
			rerrLog << "Erreur lors de l'affichage du fond d'entr�e de nom" << endl;
			gererErreur(IMG_GetError(), false);
		}
		SDL_Rect texteDesc1R, texteDesc2R, texteDesc3R, texteDesc4R;
		SDL_Rect textPos;
		texteDesc1R.x = 85;
		texteDesc1R.y = 25;
		texteDesc2R.x = 155;
		texteDesc2R.y = 200;
		texteDesc3R.x = 95;
		texteDesc3R.y = 375;
		texteDesc4R.x = texteDesc3R.x;
		texteDesc4R.y = texteDesc3R.y + 30;

		textPos.x = 120;
		textPos.y = 300;
		SDL_Texture *texteDescs[4] = {renderText(renderer, kget("nameEntry.med"), font, blanc, &texteDesc2R),
									  renderText(renderer, kget("nameEntry.top"), font, blanc, &texteDesc1R),
									  renderText(renderer, kget("nameEntry.indic.1"), font, blanc, &texteDesc3R),
									  renderText(renderer, kget("nameEntry.indic.2"), font, blanc, &texteDesc4R)
									 };
		SDL_RenderCopy(renderer, fondNE, NULL, &fondP);
		SDL_RenderCopy(renderer, texteDescs[0], NULL, &texteDesc2R);
		SDL_RenderCopy(renderer, texteDescs[1], NULL, &texteDesc1R);
		SDL_RenderCopy(renderer, texteDescs[2], NULL, &texteDesc3R);
		SDL_RenderCopy(renderer, texteDescs[3], NULL, &texteDesc4R);
		SDL_RenderPresent(renderer);
		SDL_Texture *nameT;

		bool shift = false;
		bool caps = false;
		rlog << PRINT_TICKS << "D�but de la boucle n�1" << endl;
		while (continuer) {
			SDL_WaitEvent(&events);

			switch (events.type) {
					QUIT

				case SDL_KEYUP:
					switch (events.key.keysym.sym) {
						case SDLK_RSHIFT:
							shift = false;
							break;
						case SDLK_LSHIFT:
							shift = false;
							break;
					}
					break;

				case SDL_KEYDOWN:
					switch (events.key.keysym.sym) {
							ECHAP

						case SDLK_LSHIFT:
							shift = true;
							break;

						case SDLK_RSHIFT:
							shift = true;
							break;

						case SDLK_CAPSLOCK:
							if (!caps) {
								shift = true;
								caps = true;
							} else {
								shift = false;
								caps = false;
							}


							break;

						case SDLK_BACKSPACE:
							pName[k] = ' ';
							if (k != 0) {
								k--;
							}


							break;

						case SDLK_a:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'A';
							} else {
								pName[k] = 'a';
							}

							break;

						case SDLK_b:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'B';
							} else {
								pName[k] = 'b';
							}

							break;

						case SDLK_c:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'C';
							} else {
								pName[k] = 'c';
							}

							break;

						case SDLK_d:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'D';
							} else {
								pName[k] = 'd';
							}

							break;

						case SDLK_e:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'E';
							} else {
								pName[k] = 'e';
							}

							break;

						case SDLK_f:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'F';
							} else {
								pName[k] = 'f';
							}

							break;

						case SDLK_g:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'G';
							} else {
								pName[k] = 'g';
							}

							break;

						case SDLK_h:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'H';
							} else {
								pName[k] = 'h';
							}

							break;

						case SDLK_i:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'i';
							} else {
								pName[k] = 'i';
							}

							break;

						case SDLK_j:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'J';
							} else {
								pName[k] = 'j';
							}

							break;

						case SDLK_k:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'K';
							} else {
								pName[k] = 'k';
							}

							break;

						case SDLK_l:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'L';
							} else {
								pName[k] = 'l';
							}

							break;

						case SDLK_m:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'M';
							} else {
								pName[k] = 'm';
							}

							break;

						case SDLK_n:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'N';
							} else {
								pName[k] = 'n';
							}

							break;

						case SDLK_o:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'O';
							} else {
								pName[k] = 'o';
							}

							break;

						case SDLK_p:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'P';
							} else {
								pName[k] = 'p';
							}

							break;

						case SDLK_q:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'Q';
							} else {
								pName[k] = 'q';
							}

							break;

						case SDLK_r:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'R';
							} else {
								pName[k] = 'r';
							}

							break;

						case SDLK_s:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'S';
							} else {
								pName[k] = 's';
							}

							break;

						case SDLK_t:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'T';
							} else {
								pName[k] = 't';
							}

							break;

						case SDLK_u:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'U';
							} else {
								pName[k] = 'u';
							}

							break;

						case SDLK_v:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'V';
							} else {
								pName[k] = 'v';
							}

							break;



						case SDLK_w:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'W';
							} else {
								pName[k] = 'w';
							}

							break;

						case SDLK_x:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'X';
							} else {
								pName[k] = 'x';
							}
							break;

						case SDLK_y:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'Y';
							} else {
								pName[k] = 'y';
							}
							break;

						case SDLK_z:
							if (k != 14) {
								k++;
							}
							if (shift) {
								pName[k] = 'Z';
							} else {
								pName[k] = 'z';
							}
							break;

						case SDLK_0:
							if (k != 14) {
								k++;
							}
							pName[k] = '0';
							break;

						case SDLK_1:
							if (k != 14) {
								k++;
							}
							pName[k] = '1';
							break;

						case SDLK_2:
							if (k != 14) {
								k++;
							}
							pName[k] = '2';
							break;

						case SDLK_3:
							if (k != 14) {
								k++;
							}
							pName[k] = '3';
							break;

						case SDLK_4:
							if (k != 14) {
								k++;
							}
							pName[k] = '4';
							break;

						case SDLK_5:
							if (k != 14) {
								k++;
							}
							pName[k] = '5';
							break;

						case SDLK_6:
							if (k != 14) {
								k++;
							}
							pName[k] = '6';
							break;

						case SDLK_7:
							if (k != 14) {
								k++;
							}
							pName[k] = '7';
							break;

						case SDLK_8:
							if (k != 14) {
								k++;
							}
							pName[k] = '8';
							break;

						case SDLK_9:
							if (k != 14) {
								k++;
							}
							pName[k] = '9';
							break;

						case SDLK_KP_0:
							if (k != 14) {
								k++;
							}
							pName[k] = '0';
							break;

						case SDLK_KP_1:
							if (k != 14) {
								k++;
							}
							pName[k] = '1';
							break;

						case SDLK_KP_2:
							if (k != 14) {
								k++;
							}
							pName[k] = '2';
							break;

						case SDLK_KP_3:
							if (k != 14) {
								k++;
							}
							pName[k] = '3';
							break;

						case SDLK_KP_4:
							if (k != 14) {
								k++;
							}
							pName[k] = '4';
							break;

						case SDLK_KP_5:
							if (k != 14) {
								k++;
							}
							pName[k] = '5';
							break;

						case SDLK_KP_6:
							if (k != 14) {
								k++;
							}
							pName[k] = '6';
							break;

						case SDLK_KP_7:
							if (k != 14) {
								k++;
							}
							pName[k] = '7';
							break;

						case SDLK_KP_8:
							if (k != 14) {
								k++;
							}
							pName[k] = '8';
							break;

						case SDLK_KP_9:
							if (k != 14) {
								k++;
							}
							pName[k] = '9';
							break;
                        case SDLK_DELETE:
                            if(k != 14){
                                k++;
                            }
                            pName[k] = ' ';
                            break;
						case SDLK_RETURN:
							bool voided = true;
							int voidNumber = 0;
							int indexEnd;
							for (unsigned int l = 0; l < 15; l++) {
								if (pName[l] != ' ') {
									voided = false;
									voidNumber = 0;
								}else{
								    voidNumber++;
								}
								if(voidNumber == 2){
                                    indexEnd = l - 1;
								}
							}
							if (voided) {
							    pName[0] = ' ';
								pName[0 + 1] = 'R';
								pName[1 + 1] = 'o';
								pName[2 + 1] = 'b';
								pName[3 + 1] = 'e';
								pName[4 + 1] = 'r';
								pName[5 + 1] = 't';
								pName[6 + 1] = '\0';
							}else{
							    pName[indexEnd] = '\0';
							}
							continuer = false;
							break;


					}
					break;
			}

			SDL_RenderCopy(renderer, fondNE, NULL, &fondP);
			SDL_RenderCopy(renderer, texteDescs[0], NULL, &texteDesc2R);
			SDL_RenderCopy(renderer, texteDescs[1], NULL, &texteDesc1R);
			SDL_RenderCopy(renderer, texteDescs[2], NULL, &texteDesc3R);
			SDL_RenderCopy(renderer, texteDescs[3], NULL, &texteDesc4R);
			SDL_DestroyTexture(nameT);
			nameT = renderText(renderer, pName, font, blanc, &textPos);
			SDL_RenderCopy(renderer, nameT, NULL, &textPos);
			SDL_RenderPresent(renderer);


		}
		SDL_DestroyTexture(nameT);
		SDL_DestroyTexture(texteDescs[0]);
		SDL_DestroyTexture(texteDescs[1]);
		SDL_DestroyTexture(texteDescs[2]);
		SDL_DestroyTexture(texteDescs[3]);
		SDL_DestroyTexture(fondNE);
		continuer = true;
		for (int i = 5; i >= 0; i--) {
			if ((SDL_GetTicks() - ancientTick) >= 200) {
				SDL_PollEvent(&events);

				switch (events.type) {
						QUIT

					case SDL_KEYDOWN:
						switch (events.key.keysym.sym) {
								ECHAP
						}

						break;

					case SDL_JOYBUTTONDOWN:
						if (!joypressed) {
							joypressed = true;
							switch (events.jbutton.button) {
									JOYQUIT
							}
						}



						break;
					case SDL_JOYBUTTONUP:
						joypressed = false;
						break;
				}

				ostringstream oss;

#ifdef _WIN32
				oss << "ressources\\animations\\winChange\\animWindowFrame" << i + 1 << ".png";
#else
				oss << "ressources/animations/winChange/animWindowFrame" << i + 1 << ".png";
#endif // _WIN32

				anim[i] = IMG_LoadTexture(renderer, oss.str().c_str());
				SDL_RenderCopy(renderer, anim[i], NULL, &animP);
				SDL_RenderPresent(renderer);
				SDL_DestroyTexture(anim[i]);
			} else {
				SDL_Delay(200 - (SDL_GetTicks() - ancientTick));
				i++;
			}
		}

		phase = 2;
		string txtP1[] = {kget("jlppc.dialog.start.10") + string(pName) + "...", kget("jlppc.dialog.start.11"), kget("jlppc.dialog.start.12"), kget("jlppc.dialog.start.13"), kget("jlppc.dialog.start.14"), kget("jlppc.dialog.start.15"), kget("jlppc.dialog.start.16"), kget("jlppc.dialog.start.17"), kget("jlppc.dialog.start.18"), kget("jlppc.dialog.start.19"), kget("jlppc.dialog.start.20"), kget("jlppc.dialog.start.21"), kget("jlppc.dialog.start.22"), kget("jlppc.dialog.start.23"), kget("jlppc.dialog.start.24")};
		sizeOfTxt = 15;
		i = 0;
		line = 0;
		dialog = 0;
        txtEnCours[0] = string(" ");
		txtEnCours[1] = string(" ");
		txtEnCours[2] = string(" ");
		changeDialog = false;
        rlog << PRINT_TICKS << "D�but de la boucle n�2" << endl;
		while (continuer) {
			if ((SDL_GetTicks() - ancientTick) >= 41) {

				ancientTick = SDL_GetTicks();

				SDL_PollEvent(&events);

				switch (events.type) {

						QUIT

					case SDL_KEYDOWN:
						switch (events.key.keysym.sym) {
							case SDLK_SPACE:
								DIALOG_PASS(1)

								ECHAP
						}
						break;

					case SDL_JOYBUTTONDOWN:
						if (!joypressed) {
							joypressed = true;
							switch (events.jbutton.button) {

								case 0:
									DIALOG_PASS(1)


									JOYQUIT
							}
						}
						break;

						/*case SDL_WINDOWEVENT:
							switch (events.window.event) {
								case SDL_WINDOWEVENT_RESIZED:
									break;
							}
							break;*/
				}


				if (phase == 2) {
					if (SDL_RenderCopy(renderer, fondT, NULL, &fondP) == -1) {
						rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
						gererErreur(SDL_GetError(), false);
					}
					if (SDL_RenderCopy(renderer, profT, NULL, &profP) == -1) {
						rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
						gererErreur(SDL_GetError(), false);
					}
					if (SDL_RenderCopy(renderer, dialogT, NULL, &dialogP) == -1) {
						rerrLog << "Erreur lors de l'affichage d'un �l�ment" << endl;
						gererErreur(SDL_GetError(), false);
					}
					if (!changeDialog) {

						if (!(i >= txtP1[line + dialog].size())) {

							if (txtEnCours[line] == " ") {
								txtEnCours[line] = txtP1[line + dialog].c_str()[i];
							} else {
								txtEnCours[line] += txtP1[line + dialog].c_str()[i];
							}

							i++;
						} else {
							if (line == 2) {
								changeDialog = true;
							} else {
								line++;
								i = 0;
							}
						}





					}
					printText(renderer, txtEnCours[0], txtEnCours[1], txtEnCours[2]);
					ANIM_ARROW
					SDL_RenderPresent(renderer);
				} else {
					break;
				}


			} else {
				SDL_Delay(41 - (SDL_GetTicks() - ancientTick));
			}
		}

		//rlog << "[T = " << SDL_GetTicks << "] - Entr�e dans la boucle n�1" << endl;



	}

	SDL_Texture *renderText(SDL_Renderer *renderer, char text[], TTF_Font *police, SDL_Color color, SDL_Rect *pos) {
		SDL_Surface *sfce = TTF_RenderText_Blended(police, text, color);
		if(sfce == NULL){
            gererErreur(TTF_GetError(), true);
		}
		pos->h = sfce->h;
		pos->w = sfce->w;
		SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
		SDL_FreeSurface(sfce);
		return toReturn;
	}

	SDL_Texture *renderText(SDL_Renderer *renderer, string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos) {
		SDL_Surface *sfce = TTF_RenderText_Blended(police, text.c_str(), color);
		if(sfce == NULL){
            gererErreur(TTF_GetError(), true);
		}
		pos->h = sfce->h;
		pos->w = sfce->w;
		SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
		SDL_FreeSurface(sfce);
		return toReturn;
	}


}
