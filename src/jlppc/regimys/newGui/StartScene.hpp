/*
StartScene.hpp
Auteur : Jlppc
Fichier sous license GPL-3.0
http://opmon-game.ga
Contient le namespace StartScene
*/
#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "../start/bigDefines.hxx"

namespace MainFrame {
/**Fait se dérouler la scène de début*/
namespace StartScene {
int startScene();
void initVars();
void destroyVars();

extern SDL_Rect fondP;
extern SDL_Rect profP;
extern SDL_Texture *fondT;
extern SDL_Texture *profT;
extern SDL_Texture *arrDial;
extern SDL_Rect arrDialP;
extern Mix_Music *fondMus;
}
}


#endif // STARTSCENE_H
