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


namespace MainFrame {
	extern SDL_Window *frame;
	extern SDL_Renderer *renderer;
	extern SDL_Rect fond;
	extern SDL_Event sevents;
	extern TTF_Font *font;
	extern SDL_Rect dialogP;
	extern SDL_Texture *dialogT;
	extern SDL_Rect textPlace;
	extern SDL_Color noir;
	extern bool init;
	extern SDL_Joystick *manette;
	extern Mix_Chunk *dialogPass;
	void open();
	void startScene();
	/**
	Affiche un texte dans la boite de dialogue.
	Renvoie... on verra.
	*/
	int printText(SDL_Renderer *renderer, std::string text, std::string line2, std::string line3);

	SDL_Texture* renderText(SDL_Renderer *renderer, std::string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos);
	SDL_Texture* renderText(SDL_Renderer *renderer, char text[]     , TTF_Font *police, SDL_Color color, SDL_Rect *pos);

}

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
