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

#define rLog rlog
#define charLineDialog 33
#define kget StringKeys::get

#define QUITF continuer=false;\
		SDL_DestroyTexture(textUre);\
		SDL_DestroyTexture(dialogT);\
		SDL_DestroyTexture(profT);\
		SDL_DestroyTexture(fondT);\
        return;

#define QUIT case SDL_QUIT:\
	QUITF//Un macro composé de macro. :D

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
		//Ouverture de la police
		rlog << PRINT_TICKS << "Initialisation des SDL terminée" << endl;
#ifdef _WIN32
		font = TTF_OpenFont("ressources\\fonts\\arial.ttf", 28);
#else
		font = TTF_OpenFont("ressources/fonts/arial.ttf", 28);
#endif

		if (font == NULL) {
			rerrLog << "Erreur d'initialisation de la police d'écriture." << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(TTF_GetError(), true);
		}
		rlog << PRINT_TICKS << "Initialisation de la police terminée" << endl;


		//Annonce que l'initialisation principale est terminée
		init = true;
		//Ouverture de la fenetre
		frame = SDL_CreateWindow("Pokemon Regimys", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
		//Création du renderer.
		renderer = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED);
		if (frame == NULL || renderer == NULL) {
			rerrLog << "Erreur d'ouverture de la fenetre ou du renderer." << endl;
			rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
			gererErreur(SDL_GetError(), true);
		}
		rlog << PRINT_TICKS << "Initialisation de la fenetre et du renderer terminée" << endl;
		//Ouverture de la manette (Je sais pas si ca se dit "ouverture de la manette mais c'est pas grave)
		manette = SDL_JoystickOpen(0);
		if (manette == NULL) {
			gererErreur("Aucune manette détectée", false);
		}else{
		    rlog << PRINT_TICKS << "Initialisation du joystick terminée" << endl;
		}



		loop();

		rlog << PRINT_TICKS << "Fermeture de la fenetre" << endl;

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(frame);
		SDL_JoystickClose(manette);
		TTF_CloseFont(font);

		TTF_Quit();
		atexit(IMG_Quit);
		SDL_Quit();
	}

	void loop() {
		//Déclaration des SDL_Rect et des SDL_Texture secondaires, necessaires a cette scene
		SDL_Rect fondP;
		SDL_Rect profP;
		SDL_Texture *fondT;
		SDL_Texture *profT;
		SDL_Texture *arrDial;
		SDL_Rect arrDialP;

		//Initialisation des tailles
		rlog << "[T = " << SDL_GetTicks() << "] - Initialisation des SDL_Rect" << endl;
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
		//Vesrification des problèmes possibles
		if (fondT == NULL || profT == NULL || dialogT == NULL) {
			gererErreur(string("Erreur lors de l'initialisation d'une image.") + string(SDL_GetError()), false);
		}

		if (SDL_RenderCopy(renderer, fondT, NULL, &fondP) == -1) {
			rerrLog << "Erreur lors de l'affichage d'un élément" << endl;
			gererErreur(SDL_GetError(), false);
		}
		if (SDL_RenderCopy(renderer, profT, NULL, &profP) == -1) {
			rerrLog << "Erreur lors de l'affichage d'un élément" << endl;
		}
		if (SDL_RenderCopy(renderer, dialogT, NULL, &dialogP) == -1) {
			rerrLog << "Erreur lors de l'affichage d'un élément" << endl;
		}
		//Initialisation des variables utiles pour la boucle
		SDL_RenderPresent(renderer);
		rlog << "[T = " << SDL_GetTicks() << "] - Fin des initialisations" << endl;
		rlog << "[T = " << SDL_GetTicks() << "] - Creation des variables utilitaires" << endl;
		bool continuer = true;
		long ancientTick = 0;
		//Phase 0
		string txtP0[] = {kget("jlppc.dialog.start.1"), kget("jlppc.dialog.start.2"), kget("jlppc.dialog.start.3"), kget("jlppc.dialog.start.4"), kget("jlppc.dialog.start.5"), kget("jlppc.dialog.start.6"), kget("jlppc.dialog.start.7"), kget("jlppc.dialog.start.8"), " "};//Deux cases == Deux lignes. 3 cases == Deux lignes + un nouveau dialogue
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

		rlog << "[T = " << SDL_GetTicks() << "] - Début de la boucle n°0" << endl;
		//Boucle n°1
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
                        rerrLog << "Erreur lors de l'affichage d'un élément" << endl;
                        gererErreur(SDL_GetError(), false);
                    }
                    if (SDL_RenderCopy(renderer, profT, NULL, &profP) == -1) {
                        rerrLog << "Erreur lors de l'affichage d'un élément" << endl;
                        gererErreur(SDL_GetError(), false);
                    }
                    if (SDL_RenderCopy(renderer, dialogT, NULL, &dialogP) == -1) {
                        rerrLog << "Erreur lors de l'affichage d'un élément" << endl;
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
        SDL_Texture *anim[6];
        SDL_Rect animP;
        animP.h = 512;
        animP.w = 512;
        animP.x = 0;
        animP.y = 0;

        rlog << "[T = " << SDL_GetTicks() << "] - Début de la boucle n°1" << endl;
        for(int i = 0; i < 6;i++){
            if((SDL_GetTicks() - ancientTick) >= 200) {
                SDL_PollEvent(&events);

                switch(events.type){
                    QUIT

                case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                        ECHAP
                    }

                     break;

                case SDL_JOYBUTTONDOWN:
                    if(!joypressed){
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
            }else{
                SDL_Delay(200 - (SDL_GetTicks() - ancientTick));
                i--;
            }
        }
        phase = 2;
        rlog << "[T = " << SDL_GetTicks() << "] - Début de la boucle n°2" << endl;
        char pName[16] = "               ";
        int k = 0;
        #ifdef _WIN32
        SDL_Texture *fondNE = IMG_LoadTexture(renderer, "ressources\\backgrounds\\start\\nameEntry.png");
        #else
        SDL_Texture *fondNE = IMG_LoadTexture(renderer, "ressources/backgrounds/start/nameEntry.png");
        #endif
        if(fondNE == NULL){
            rerrLog << "Erreur lors de l'affichage du fond d'entrée de nom" << endl;
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

        SDL_Texture *texteDescs[4] = {renderText(renderer,"Entre un nom", font, blanc, &texteDesc2R),
            renderText(renderer, "Quel est son nom", font, blanc, &texteDesc1R),
            renderText(renderer, "Appuie sur Entrée lorsque", font, blanc, &texteDesc3R),
            renderText(renderer, "tu as terminé", font, blanc, &texteDesc4R)};

        SDL_RenderCopy(renderer, fondNE, NULL, &fondP);
        SDL_RenderCopy(renderer, texteDescs[0], NULL, &texteDesc2R);
        SDL_RenderCopy(renderer, texteDescs[1], NULL, &texteDesc1R);
        SDL_RenderCopy(renderer, texteDescs[2], NULL, &texteDesc3R);
        SDL_RenderCopy(renderer, texteDescs[3], NULL, &texteDesc4R);
        SDL_RenderPresent(renderer);

        SDL_Texture *nameT;

        bool shift = false;
        bool caps = false;

        while(continuer){
                SDL_WaitEvent(&events);

                switch(events.type){
                    QUIT

            case SDL_KEYUP:
                switch(events.key.keysym.sym){
                case SDLK_RSHIFT:
                    shift = false;
                    break;
                case SDLK_LSHIFT:
                    shift = false;
                    break;
                }
                break;

            case SDL_KEYDOWN:
                    switch(events.key.keysym.sym){
                        ECHAP

                    case SDLK_LSHIFT:
                        shift = true;
                        break;

                    case SDLK_RSHIFT:
                        shift = true;
                        break;

                    case SDLK_CAPSLOCK:
                        if(!caps){
                            shift = true;
                            caps = true;
                        }else{
                            shift = false;
                            caps = false;
                        }


                        break;

                    case SDLK_BACKSPACE:
                        pName[k] = ' ';
                        if(k != 0){
                            k--;
                        }


                        break;

                    case SDLK_a:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'A';
                        }else{
                            pName[k] = 'a';
                        }

                        break;

                    case SDLK_b:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'B';
                        }else{
                            pName[k] = 'b';
                        }

                        break;

                    case SDLK_c:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'C';
                        }else{
                            pName[k] = 'c';
                        }

                        break;

                    case SDLK_d:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'D';
                        }else{
                            pName[k] = 'd';
                        }

                        break;

                    case SDLK_e:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'E';
                        }else{
                            pName[k] = 'e';
                        }

                        break;

                    case SDLK_f:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'F';
                        }else{
                            pName[k] = 'f';
                        }

                        break;

                    case SDLK_g:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'G';
                        }else{
                            pName[k] = 'g';
                        }

                        break;

                    case SDLK_h:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'H';
                        }else{
                            pName[k] = 'h';
                        }

                        break;

                    case SDLK_i:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'i';
                        }else{
                            pName[k] = 'i';
                        }

                        break;

                    case SDLK_j:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'J';
                        }else{
                            pName[k] = 'j';
                        }

                        break;

                    case SDLK_k:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'K';
                        }else{
                            pName[k] = 'k';
                        }

                        break;

                    case SDLK_l:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'L';
                        }else{
                            pName[k] = 'l';
                        }

                        break;

                    case SDLK_m:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'M';
                        }else{
                            pName[k] = 'm';
                        }

                        break;

                    case SDLK_n:
                        if(k != 14){
                            k++;
                        }
                        if(shift){
                            pName[k] = 'N';
                        }else{
                            pName[k] = 'n';
                        }

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


		//rlog << "[T = " << SDL_GetTicks << "] - Entrée dans la boucle n°1" << endl;



	}

	SDL_Texture* renderText(SDL_Renderer *renderer, char text[], TTF_Font *police, SDL_Color color, SDL_Rect *pos){
        SDL_Surface *sfce = TTF_RenderText_Blended(police, text, color);
        pos->h = sfce->h;
        pos->w = sfce->w;
        SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
        SDL_FreeSurface(sfce);
        return toReturn;
	}

	SDL_Texture* renderText(SDL_Renderer *renderer, string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos){
	    return renderText(renderer, text.c_str(), police, color, pos);
	}


}
