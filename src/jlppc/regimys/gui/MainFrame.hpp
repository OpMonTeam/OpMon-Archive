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
#include "Elements.hpp"


namespace MainFrame {
	extern SDL_Window *frame;
	extern SDL_Renderer *renderer;
	extern SDL_Rect fond;
	extern bool init;
	void open();
	void loop();

}

#endif /* SRC_JLPPC_REGIMYS_GUI_MAINFRAME_HPP_ */
