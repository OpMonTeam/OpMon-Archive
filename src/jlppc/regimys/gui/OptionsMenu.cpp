#include "OptionsMenu.hpp"

namespace MainFrame{
namespace MainMenu{
namespace OptionsMenu{
    SDL_Color red = {255, 0, 0};
    SDL_Texture *fond = NULL;
    SDL_Rect curseurOpt;
    SDL_Rect curseurSnd;
    J_Texture *ouinon;
    J_Texture *langFr;
    J_Texture *langEng;
    J_Texture *langEsp;
    J_Texture *txtRetour;
    J_Texture *txtOptions;
    J_Texture *txtOpt1;
    J_Texture *txtOpt2;
    J_Texture *txtOpt3;
    J_Texture *txtOpt4;
    J_Texture *txtOpt5;

    void initVars(){

        #ifdef _WIN32


        #else
        OptionsMenu::fond = IMG_LoadTexture(renderer, "ressources/background/options.png");


        #endif // _WIN32
        ouinon = renderText(renderer, kget("options.ouinon"), fonts[FONT_SIZE_DEFAULT], red);
        langFr = renderText(renderer, "Français", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
        langEng = rendererText(renderer, "English", font[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
        langEsp = renderText(renderer, "Espa\u00F1ol", fond[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
        txtRetour = renderText(renderer, kget("options.retour"), fonts[FONT_SIZE_DEFAULT], blanc);
        txtOptions = renderText(renderer, kget("options.title"), font[FONT_SIZE_DEFAULT], blanc);
        txtOpt1 = renderText(renderer, kget("options.ecran"), font[FONT_SIZE_DEFAULT], red);
        txtOpt2 = renderText(renderer, kget("options.lang"), font[FONT_SIZE_DEFAULT], blanc);
        txtOpt3 = renderText(renderer, kget("options.vol"), font[FONT_SIZE_DEFAULT], red);
        txtOpt4 = renderText(renderer, kget("options.control"), font[FONT_SIZE_DEFAULT], red);
        txtOpt5 = renderText(renderer, kget("options.credit"), font[FONT_SIZE_DEFAULT], red);

    }

    void deleteVars(){

    }
}
}
}
