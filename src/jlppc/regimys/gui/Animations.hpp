#ifndef ANIMATIONS_HPP
#define ANIMATIONS_HPP

#include <iostream>
#include "../start/main.hpp"
#include <SDL/SDL.h>

#define ANIM_CHECK_INIT \
    if(!init){\
        gererErreur("Erreur : Animations non initialisées", true);\
    }

namespace Animations {

extern bool init;

void initAnims();
void deleteAnims();

int animFenOpen(SDL_Renderer *renderer, SDL_Texture *fond);
int animFenClose(SDL_Renderer *renderer, SDL_Texture *fond);

}


#endif // ANIMATIONS_HPP
