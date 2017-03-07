#include "StartScene.hpp"
#include "../start/main.hpp"
#include "MainFrame.hpp"

UNS

namespace MainFrame{
    namespace StartScene {
		//D�claration des SDL_Rect et des SDL_Texture secondaires, necessaires a cette scene (a d�truire)
		SDL_Rect fondP;
		SDL_Rect profP;
		SDL_Texture *fondT;
		SDL_Texture *profT;
		SDL_Texture *arrDial;
		SDL_Rect arrDialP;
        SDL_Texture *textUre = NULL;
#ifdef _WIN32
	Mix_Music *fondMus = Mix_LoadMUS("ressources\\audio\\music\\intro.ogg");
#else
	Mix_Music *fond = Mix_LoadMUS("ressources/audio/music/intro.ogg");
#endif
        //D�claration des variables utilitaires (sera supprim� en cours de travail)
        //Part 0
		bool continuer = true;
		long ancientTick = 0;
		string txtP0[9];//Deux cases == Deux lignes. 3 cases == Deux lignes + un nouveau dialogue
		int sizeOfTxt = 9;
		string txtEnCours[] = {string(" "), string(" "), string(" ")};
		SDL_Surface *sfce = NULL;
		int line = 0, i = 0, dialog = 0;
		bool changeDialog = false;
		int phase = 0;
		bool joypressed = false;
		SDL_Texture *anim[6];
        SDL_Rect animP;
        //Part 1
        char pName[16] = "               ";
        int k = 0;
        #ifdef _WIN32
            SDL_Texture *fondNE;//To destroy in part 1
        #else
            SDL_Texture *fondNE;
        #endif
        SDL_Rect texteDesc1R, texteDesc2R, texteDesc3R, texteDesc4R;
        SDL_Rect textPos;
        SDL_Texture *texteDescs[4];//To destroy in part 1
        SDL_Texture *nameT;//To destroy in part 1
        bool shift = false;
        bool caps = false;
        //Part 2
        string txtP1[15];



		void destroyVars(){
		    SDL_DestroyTexture(fondT);
		    SDL_DestroyTexture(profT);
		    SDL_DestroyTexture(arrDial);
		    Mix_FreeMusic(fondMus);
		    SDL_DestroyTexture(textUre);
        }

		/**Initialise les variables*/
		void initVars() {
		    unsigned int it = 0;
		    for(it = 0; it < 9; it++){
                ostringstream oss;
                oss << "jlppc.dialog.start." << it + 1;
                txtP0[it] = kget(oss.str());
		    }
		    int ite = 1;
		    it++;
		    txtP1[0] = "";
            for(it = it; it < 15 + 9; it++){
                ostringstream oss;
                oss << "jlppc.dialog.start." << it + 1;
                txtP1[ite] = kget(oss.str());
                ite++;
            }
			rlog << PRINT_TICKS << "Initialisation des variables de la scene d'intro" << endl;
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
			//Initialisation des images
			rlog << "[T = " << SDL_GetTicks() << "] - Initialisation des sprites..." << endl;
#ifdef _WIN32
			fondT = IMG_LoadTexture(renderer, "ressources\\backgrounds\\start\\startscene.png");
			profT = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\jlppc\\jlppc.png");
			dialogT = IMG_LoadTexture(renderer, "ressources\\backgrounds\\dialog\\dialog.png");
			arrDial = IMG_LoadTexture(renderer, "ressources\\sprites\\misc\\arrDial.png");
			fondNE = IMG_LoadTexture(renderer, "ressources\\backgrounds\\start\\nameEntry.png");
#else
			fondT = IMG_LoadTexture(renderer, "ressources/backgrounds/start/startscene.png");
			profT = IMG_LoadTexture(renderer, "ressources/sprites/chara/jlppc/jlppc.png");
			dialogT = IMG_LoadTexture(renderer, "ressources/backgrounds/dialog/dialog.png");
			arrDial = IMG_LoadTexture(renderer, "ressources/sprites/misc/arrDial.png");
			fondNE = IMG_LoadTexture(renderer, "ressources/backgrounds/start/nameEntry.png");
#endif
			rlog << "[T = " << SDL_GetTicks() << "] - Fin des initialisations" << endl;
			texteDescs[0] = renderText(renderer, kget("nameEntry.med"), font, blanc, &texteDesc2R);
			texteDescs[1] = renderText(renderer, kget("nameEntry.top"), font, blanc, &texteDesc1R);
			texteDescs[2] = renderText(renderer, kget("nameEntry.indic.1"), font, blanc, &texteDesc3R);
			texteDescs[3] = renderText(renderer, kget("nameEntry.indic.2"), font, blanc, &texteDesc4R);
		}

		/**Verifie les erreurs de variables*/
		int verifVars() {
			rlog << PRINT_TICKS << "Verification des variables" << endl;
			if (fondMus == NULL) {
				gererErreur(Mix_GetError(), false);
			}
			if (fondT == NULL || profT == NULL || dialogT == NULL) {
				gererErreur(string("MainFrame : Erreur lors de l'initialisation d'une image.") + string(SDL_GetError()), false);
			}

			if (SDL_RenderCopy(renderer, fondT, NULL, &fondP) == -1) {
				rerrLog << "MainFrame (verifVars) : Erreur lors de l'initialisation d'un �l�ment" << endl;
				gererErreur(SDL_GetError(), false);
			}
			if (SDL_RenderCopy(renderer, profT, NULL, &profP) == -1) {
				rerrLog << "MainFrame (verifVars) : Erreur lors de l'initialisation d'un �l�ment" << endl;
			}
			if (SDL_RenderCopy(renderer, dialogT, NULL, &dialogP) == -1) {
				rerrLog << "MainFrame (verifVars) : Erreur lors de l'initialisation d'un �l�ment" << endl;
			}
			if (fondNE == NULL) {
				rerrLog << "MainFrame (verifVars) : Erreur lors de l'initialisation du fond d'entr�e de nom" << endl;
				gererErreur(IMG_GetError(), false);
			}
			rlog << PRINT_TICKS << "Verifications OK." << endl;
		}

		int boucle0() {
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
									txtEnCours[line] += txtP0[line + dialog].c_str()[i];
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
			return 0;
		}

        int anim0(){
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
        }

		int boucle1(){
		    SDL_RenderCopy(renderer, fondNE, NULL, &fondP);
            SDL_RenderCopy(renderer, texteDescs[0], NULL, &texteDesc2R);
            SDL_RenderCopy(renderer, texteDescs[1], NULL, &texteDesc1R);
            SDL_RenderCopy(renderer, texteDescs[2], NULL, &texteDesc3R);
            SDL_RenderCopy(renderer, texteDescs[3], NULL, &texteDesc4R);
            SDL_RenderPresent(renderer);
		    while (continuer) {
				SDL_WaitEvent(&events);

				switch (events.type) {
						QUIT

                        NAME_ENTRY

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
			return 0;
		}

		int anim1(){
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
		}

		int boucle2(){
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
						//printChoice(kget("jlppc.dialog.start.25"), kget("opmon.choice.1"), kget("opmon.choice.2"), kget("opmon.choice.3")); //Non fini
						break;
					}


				} else {
					SDL_Delay(41 - (SDL_GetTicks() - ancientTick));
				}
			}
			return 0;
		}

		void startScene() {
			initVars();
			verifVars();
			//D�part de la musique
			Mix_PlayMusic(fondMus, -1);
			Mix_VolumeMusic(MIX_MAX_VOLUME / 16);

			//Initialisation des tailles

			//Vesrification des probl�mes possibles

			//Initialisation des variables utiles pour la boucle
			SDL_RenderPresent(renderer);

			if(boucle0() == -1){
                destroyVars();
                return;
			}

			continuer = true;



			phase = 1;
			rlog << "[T = " << SDL_GetTicks() << "] - Chargement de la boucle n�1" << endl;


            anim0();



			SDL_RenderCopy(renderer, fondNE, NULL, &fondP);
			SDL_RenderCopy(renderer, texteDescs[0], NULL, &texteDesc2R);
			SDL_RenderCopy(renderer, texteDescs[1], NULL, &texteDesc1R);
			SDL_RenderCopy(renderer, texteDescs[2], NULL, &texteDesc3R);
			SDL_RenderCopy(renderer, texteDescs[3], NULL, &texteDesc4R);
			SDL_RenderPresent(renderer);



			rlog << PRINT_TICKS << "D�but de la boucle n�1" << endl;

			if(boucle1() == -1){
                destroyVars();
                SDL_DestroyTexture(nameT);
                SDL_DestroyTexture(texteDescs[0]);
                SDL_DestroyTexture(texteDescs[1]);
                SDL_DestroyTexture(texteDescs[2]);
                SDL_DestroyTexture(texteDescs[3]);
                SDL_DestroyTexture(fondNE);
                return;
            }
            SDL_DestroyTexture(nameT);
			SDL_DestroyTexture(texteDescs[0]);
			SDL_DestroyTexture(texteDescs[1]);
			SDL_DestroyTexture(texteDescs[2]);
			SDL_DestroyTexture(texteDescs[3]);
			SDL_DestroyTexture(fondNE);

			continuer = true;

            anim1();

            txtP1[0] = kget("jlppc.dialog.start.10") + string(pName) + "...";

			phase = 2;

			sizeOfTxt = 15;
			i = 0;
			line = 0;
			dialog = 0;
			txtEnCours[0] = string(" ");
			txtEnCours[1] = string(" ");
			txtEnCours[2] = string(" ");
			changeDialog = false;
			rlog << PRINT_TICKS << "D�but de la boucle n�2" << endl;
            if(boucle2() == -1){
                destroyVars();
                return;
            }
			phase++;


			//rlog << "[T = " << SDL_GetTicks << "] - Entr�e dans la boucle n�1" << endl;



		}
	}
}

