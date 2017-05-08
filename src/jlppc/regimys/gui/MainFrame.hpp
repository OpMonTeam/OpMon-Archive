/*
Mainframe.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Permet d'ouvrir la fenetre du jeu et de charger les ressources essensielles. Contient aussi des methodes et macros utiles dans l'interface graphique.
 */

#ifndef SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_
#define SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Elements.hpp"
#include "../start/StringKeys.hpp"
#define rLog rlog
#define charLineDialog 33
#define kget StringKeys::get
#define FPS_TICKS 33

#define QUITF continuer=false;\
	return -1;

#define QUIT case SDL_QUIT:\
	QUITF

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
		phase++;\
	}\
	break;

#define ANIM_ARROW 		arrDialP.y = arrDialP.y + 1;\
	if (arrDialP.y - (512 - 30) > 5) {\
		arrDialP.y = arrDialP.y - 6;\
	}\
	SDL_RenderCopy(renderer, arrDial, NULL, &arrDialP);

#define WAIT_DEFAULT 100000000 / 2
#define FONT_SIZE_DEFAULT 28

/**Contient toutes les methodes permettant de gérer et de faire fonctionner l'interface graphique
 * Contient aussi le déroulement des évenements
 */
namespace MainFrame {
/**Contient la fenetre du jeu*/
extern SDL_Window *frame;
/**C'est le renderer de la fenetre*/
extern SDL_Renderer *renderer;
/**Contient la taille du fond de la fenetre*/
extern SDL_Rect fond;
/**C'est la variable qui contiendra les events a récuperer*/
extern SDL_Event events;
/**Contient la police de base des dialogues*/
extern TTF_Font *font;
/**Contient la taille de la boite de dialogue*/
extern SDL_Rect dialogP;
/**Contient le fond de la boite de dialogue*/
extern SDL_Texture *dialogT;
/**Contient la position du texte de dialogue*/
extern SDL_Rect textPlace;
/**Contient la couleur noire*/
extern SDL_Color noir;
/**Contient la couleur blanche*/
extern SDL_Color blanc;
/**Indique si la SDL s'est initialisée*/
extern bool init;
/**Contient la manette, si il y en a une*/
extern SDL_Joystick *manette;
/**Contient le son du changement de dialogue*/
extern Mix_Chunk *dialogPass;

extern SDL_Texture *ppSprite;

extern SDL_Texture *ppAnim;

extern TTF_Font *fonts[72];
/**Ouvre la fenetre, charge les composants de base de la SDL et du jeu*/
void open();
/**Définit le namespace contenant les variables et les methodes utiles a la scene de départ.*/


/**
Affiche un texte dans la boite de dialogue.
Renvoie...un int.
*/
int printText(SDL_Renderer *renderer, std::string text, std::string line2, std::string line3);

/**Permet d'affiche le texte passé en paramètres dans un *SDL_Texture*/
SDL_Texture* renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos);
/**Permet d'affiche le texte passé en paramètres dans un *SDL_Texture*/
SDL_Texture* renderText(SDL_Renderer *renderer, char text[], TTF_Font *police, SDL_Color color, SDL_Rect *pos);
/**Permet d'affiché le texte passé en paramètres dans un *SDL_Texture avec l'encodage donné en paramètres*/
SDL_Texture *renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos, int encodage/*//->WaitEnum->Encoding*/);

J_Texture renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color);

J_Texture renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, int encodage);

void initAll();

void destroyAll();

}

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
