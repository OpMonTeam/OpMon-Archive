#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "../start/bigDefines.hxx"

namespace MainFrame {
namespace StartScene {
/**Fait se dérouler la scène de début*/
int startScene();

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
