#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"

UNS

namespace MainFrame{
namespace MainMenu{
namespace OptionsMenu{
    SDL_Color red = {255, 0, 0};
    SDL_Texture *fond = NULL;
    SDL_Rect curseurOpt;
    SDL_Rect curseurSnd;
    J_Texture ouinon;
    J_Texture langFr;
    J_Texture langEng;
    J_Texture langEsp;
    J_Texture txtRetour;
    J_Texture txtOptions;
    J_Texture txtOpt1;
    J_Texture txtOpt2;
    J_Texture txtOpt3;
    J_Texture txtOpt4;
    J_Texture txtOpt5;

    void initVars(){

        #ifdef _WIN32


        #else
        OptionsMenu::fond = IMG_LoadTexture(renderer, "ressources/background/options.png");


        #endif // _WIN32
        string str = kget("options.ouinon");

        rerrLog << "Check1" << endl;
        rerrLog << str << endl;
        ouinon = renderText(renderer, str, fonts[FONT_SIZE_DEFAULT], red);
        langFr = renderText(renderer, "Français", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
        langEng = renderText(renderer, "English", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
        langEsp = renderText(renderer, "Espa\u00F1ol", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
        rerrLog << "Check2" << endl;
        txtRetour = renderText(renderer, kget("options.retour"), fonts[FONT_SIZE_DEFAULT], blanc);
        rerrLog << "Check3" << endl;
        txtOptions = renderText(renderer, kget("options.title"), fonts[FONT_SIZE_DEFAULT], blanc);
        rerrLog << "Check4" << endl;
        txtOpt1 = renderText(renderer, kget("options.ecran"), fonts[FONT_SIZE_DEFAULT], red);
        rerrLog << "Check5" << endl;
        txtOpt2 = renderText(renderer, kget("options.lang"), fonts[FONT_SIZE_DEFAULT], blanc);
        rerrLog << "Check6" << endl;
        txtOpt3 = renderText(renderer, kget("options.vol"), fonts[FONT_SIZE_DEFAULT], red);
        rerrLog << "Check7" << endl;
        txtOpt4 = renderText(renderer, kget("options.control"), fonts[FONT_SIZE_DEFAULT], red);
        rerrLog << "Check8" << endl;
        txtOpt5 = renderText(renderer, kget("options.credit"), fonts[FONT_SIZE_DEFAULT], red);
        rerrLog << "Check9" << endl;

    }

    void deleteVars(){

    }

    int optionsMenu(){

    }
}
}
}
