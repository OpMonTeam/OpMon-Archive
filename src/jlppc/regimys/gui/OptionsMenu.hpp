#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include <iostream>
#include "MainFrame.hpp"
#include "MainMenu.hpp"
#include <SDL/SDL.h>
#include "Elements.hpp"

namespace MainFrame{
namespace MainMenu{
namespace OptionsMenu{

    extern SDL_Texture *fondOpt;
    extern SDL_Rect curseurOpt;
    extern SDL_Rect curseurSnd;
    extern J_Texture langFr;
    extern J_Texture langEng;
    extern J_Texture langEsp;
    extern J_Texture txtRetour;
    extern J_Texture txtOptions;
    extern J_Texture txtOpt1;
    extern J_Texture txtOpt2;
    extern J_Texture txtOpt3;
    extern J_Texture txtOpt4;
    extern J_Texture txtOpt5;
    extern SDL_Texture *rectSurb;
    extern SDL_Color red;

    extern J_Texture txtLang;
    extern SDL_Texture *fondLangues;
    extern J_Texture listeLangues[3];
    extern SDL_Rect curPosLang[4];

    int optionsMenu();
    void initVars();
    void verifVars();
    void deleteVars();
    int boucle();
    int boucleLang();

}
}
}

#endif // OPTIONSMENU_HPP
