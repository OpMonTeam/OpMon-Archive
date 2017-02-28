/*
Mainframe.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Permet d'ouvrir la fenetre du jeu.
 */

#ifndef SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_
#define SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Elements.hpp"

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
	/**Indique si la SDL s'est initialisée*/
	extern bool init;
	/**Contient la manette, si il y en a une*/
	extern SDL_Joystick *manette;
	/**Contient le son du changement de dialogue*/
	extern Mix_Chunk *dialogPass;
	/**Ouvre la fenetre, charge les composants de base de la SDL et du jeu*/
	void open();
	/**Fait se dérouler la scène de début*/
	void startScene();
	/**
	Affiche un texte dans la boite de dialogue.
	Renvoie...un int.
	*/
	int printText(SDL_Renderer *renderer, std::string text, std::string line2, std::string line3);

    /**Permet d'affiche le texte passé en paramètres dans un *SDL_Texture*/
	SDL_Texture* renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos);
	/**Permet d'affiche le texte passé en paramètres dans un *SDL_Texture*/
	SDL_Texture* renderText(SDL_Renderer *renderer, char text[]     , TTF_Font *police, SDL_Color color, SDL_Rect *pos);

}

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
