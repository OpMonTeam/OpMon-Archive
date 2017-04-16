#include "OptionsMenu.hpp"
#include "../enums/Enums.hpp"
#include "../start/main.hpp"

UNS

namespace MainFrame {
namespace MainMenu {
namespace OptionsMenu {
//Variables fonctionnelles
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
SDL_Rect curPos[5] = {};
int curPosOpt = 0;

void initVars() {

#ifdef _WIN32
    OptionsMenu::fond = IMG_LoadTexture(renderer, "ressources\\background\\options.png");

#else
    OptionsMenu::fond = IMG_LoadTexture(renderer, "ressources/background/options.png");


#endif // _WIN32
    ouinon = renderText(renderer, kget("options.ouinon"), fonts[FONT_SIZE_DEFAULT], red);
    langFr = renderText(renderer, "Français", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
    langEng = renderText(renderer, "English", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
    langEsp = renderText(renderer, "Espa\u00F1ol", fonts[FONT_SIZE_DEFAULT], blanc, Encoding::UNICODE);
    txtRetour = renderText(renderer, kget("options.retour"), fonts[FONT_SIZE_DEFAULT], blanc);
    txtOptions = renderText(renderer, kget("options.title"), fonts[FONT_SIZE_DEFAULT], blanc);
    txtOpt1 = renderText(renderer, kget("options.ecran"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt2 = renderText(renderer, kget("options.lang"), fonts[FONT_SIZE_DEFAULT], blanc);
    txtOpt3 = renderText(renderer, kget("options.vol"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt4 = renderText(renderer, kget("options.control"), fonts[FONT_SIZE_DEFAULT], red);
    txtOpt5 = renderText(renderer, kget("options.credit"), fonts[FONT_SIZE_DEFAULT], red);


    txtOpt2.rect.x = txtOpt3.rect.x = txtOpt4.rect.x = txtOpt5.rect.x = txtOpt1.rect.x = 120;
    txtOpt1.rect.y = 90;
    txtOpt2.rect.y = 160;
    txtOpt3.rect.y = 230;
    txtOpt4.rect.y = 300;
    txtOpt5.rect.y = 370;

    txtRetour.rect.x = 55;
    txtRetour.rect.y = 30;

    txtRetour.rect.x = 230;
    txtRetour.rect.y = 30;

    /*for(int i = 0, j = 86; i < 5; i++) {
        curPos[i].x = 23;
        curPos[i].y = j;
        curPos[i].w = 30;
        curPos[i].h = 30;
        textPos[i].x = 60;
        textPos[i].y = j;
        j+=69;
    }*/






}

void deleteVars() {
    SDL_DestroyTexture(OptionsMenu::fond);
    SDL_DestroyTexture(ouinon);
    SDL_DestroyTexture(langFr);
    SDL_DestroyTexture(langEng);
    SDL_DestroyTexture(langEsp);
    SDL_DestroyTexture(txtRetour);
    SDL_DestroyTexture(txtOptions);
    SDL_DestroyTexture(txtOpt1);
    SDL_DestroyTexture(txtOpt2);
    SDL_DestroyTexture(txtOpt3);
    SDL_DestroyTexture(txtOpt4);
    SDL_DestroyTexture(txtOpt5);
}

int optionsMenu() {
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

                switch(curPosOpt) {
                case 0:
                    return 0;
                case 3:
                    return -1;
                case 2:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                case 1:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                }
                break;

            case SDLK_DOWN:
                Mix_PlayChannel(2, bruitArr, 0);
                curPosOpt++;
                if(curPosOpt >= 5) {
                    curPosOpt = 0;
                } else if(curPosOpt < 0) {
                    curPosOpt = 4;
                }
                break;

            case SDLK_UP:
                Mix_PlayChannel(2, bruitArr, 0);
                curPosOpt--;
                if(curPosOpt >= 5) {
                    curPosOpt = 0;
                } else if(curPosOpt < 0) {
                    curPosOpt = 4;
                }
                break;

                ECHAP
            }
            break;
        }
        SDL_RenderCopy(renderer, OptionsMenu::fond, NULL, MainFrame::fond);
        J_RenderCopy(renderer, txtOpt1);
        J_RenderCopy(renderer, txtOpt2);
        J_RenderCopy(renderer, txtOpt3);
        J_RenderCopy(renderer, txtOpt4);
        J_RenderCopy(renderer, txtOpt5);
        J_RenderCopy(renderer, txtRetour);
        J_RenderCopy(renderer, txtOptions);
        SDL_RenderCopy(renderer, cursor, NULL, &curPos[curPosOpt]);
        SDL_RenderPresent(renderer);
    }
    return 0;
}
}
}
}
