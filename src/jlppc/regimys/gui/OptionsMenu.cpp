#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"

UNS

namespace MainFrame {
namespace MainMenu {
namespace OptionsMenu {
//Variables fonctionnelles
SDL_Color red = {255, 0, 0};
SDL_Texture *fondOpt = NULL;
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
SDL_Texture *rectSurb = NULL;
SDL_Rect curPosOpt[6] = {};
int optionSelect = -1;
int curPosOptI = 0;

SDL_Texture *fondLangues = NULL;
J_Texture listeLangues[3] = {};
SDL_Rect curPosLang[4] = {};

void initVars() {

#ifdef _WIN32
    OptionsMenu::fondOpt = IMG_LoadTexture(renderer, "ressources\\backgrounds\\options.png");
    rectSurb = IMG_LoadTexture(renderer, "ressources\\sprites\\misc\\selectBar.png");
    fondLangues = IMG_LoadTexture(renderer, "ressources\\backgrounds\\lang.png");

#else
    OptionsMenu::fondOpt = IMG_LoadTexture(renderer, "ressources/backgrounds/options.png");
    rectSurb = IMG_LoadTexture(renderer, "ressources/sprites/misc/selectBar.png");
    fondLangues = IMG_LoadTexture(renderer, "ressources/backgrounds/lang.png");


#endif // _WIN32
    ouinon = renderText(renderer, kget("options.ouinon"), fonts[FONT_SIZE_DEFAULT], red);
    langFr = renderText(renderer, "Français", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
    langEng = renderText(renderer, "English", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
    langEsp = renderText(renderer, "Espa\u00F1ol", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
    txtRetour = renderText(renderer, kget("options.retour"), fonts[FONT_SIZE_DEFAULT], blanc);
    txtOptions = renderText(renderer, kget("options.title"), fonts[FONT_SIZE_DEFAULT], blanc);
    txtOpt1 = renderText(renderer, kget("options.ecran"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt2 = renderText(renderer, kget("options.lang"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt3 = renderText(renderer, kget("options.vol"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt4 = renderText(renderer, kget("options.control"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt5 = renderText(renderer, kget("options.credit"), fonts[FONT_SIZE_DEFAULT], red);


    txtOpt2.rect.x = txtOpt3.rect.x = txtOpt4.rect.x = txtOpt5.rect.x = txtOpt1.rect.x = 120;
    txtOpt1.rect.y = 100;
    txtOpt2.rect.y = 170;
    txtOpt3.rect.y = 240;
    txtOpt4.rect.y = 310;
    txtOpt5.rect.y = 380;

    txtRetour.rect.x = 55;
    txtRetour.rect.y = 25;

    txtOptions.rect.x = 230;
    txtOptions.rect.y = 25;

    curPosOpt[0].x = 23;
    curPosOpt[0].y = 17;
    curPosOpt[0].w = 134;
    curPosOpt[0].h = 49;

    for(int i = 1, j = 86; i < 6; i++) {
        curPosOpt[i].x = 23;
        curPosOpt[i].y = j;
        curPosOpt[i].w = 464;
        curPosOpt[i].h = 57;
        j+=69;
    }






}

void verifVars() {
    if(OptionsMenu::fondOpt == NULL) {
        rerrLog << "Erreur dans l'initialisation de l'image de fond des options" << endl;
        gererErreur(IMG_GetError(), false);
    }
}

void deleteVars() {
    SDL_DestroyTexture(OptionsMenu::fondOpt);
    SDL_DestroyTexture(ouinon.texture);
    SDL_DestroyTexture(langFr.texture);
    SDL_DestroyTexture(langEng.texture);
    SDL_DestroyTexture(langEsp.texture);
    SDL_DestroyTexture(txtRetour.texture);
    SDL_DestroyTexture(txtOptions.texture);
    SDL_DestroyTexture(txtOpt1.texture);
    SDL_DestroyTexture(txtOpt2.texture);
    SDL_DestroyTexture(txtOpt3.texture);
    SDL_DestroyTexture(txtOpt4.texture);
    SDL_DestroyTexture(txtOpt5.texture);
    SDL_DestroyTexture(rectSurb);
}

int optionsMenu() {
    verifVars();
    int returned = boucle();
    return returned;
}

int boucle() {
    while(continuer) {
        SDL_WaitEvent(&events);
        switch(events.type) {
            QUIT

        case SDL_KEYDOWN:
            switch (events.key.keysym.sym) {
            case SDLK_RETURN:

                switch(curPosOptI) {
                case 0:
                    return 0;
                case 1:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                case 2:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                case 3:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                case 4:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                case 5:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                }
                break;

            case SDLK_DOWN:
                Mix_PlayChannel(2, bruitArr, 0);
                curPosOptI++;
                if(curPosOptI >= 6) {
                    curPosOptI = 0;
                } else if(curPosOptI < 0) {
                    curPosOptI = 5;
                }
                break;

            case SDLK_UP:
                Mix_PlayChannel(2, bruitArr, 0);
                curPosOptI--;
                if(curPosOptI >= 6) {
                    curPosOptI = 0;
                } else if(curPosOptI < 0) {
                    curPosOptI = 5;
                }
                break;

            case SDLK_BACKSPACE:
                return 0;


                ECHAP
            }
            break;
        }

        if(SDL_RenderCopy(renderer, OptionsMenu::fondOpt, NULL, &MainFrame::fond) == -1) {
            gererErreur(SDL_GetError(), false);
        }
        J_RenderCopy(renderer, &txtOpt1);
        J_RenderCopy(renderer, &txtOpt2);
        J_RenderCopy(renderer, &txtOpt3);
        J_RenderCopy(renderer, &txtOpt4);
        J_RenderCopy(renderer, &txtOpt5);
        J_RenderCopy(renderer, &txtRetour);
        J_RenderCopy(renderer, &txtOptions);
        SDL_RenderCopy(renderer, rectSurb, NULL, &curPosOpt[curPosOptI]);
        SDL_RenderPresent(renderer);

    }

    return 0;

}

}
}
}
