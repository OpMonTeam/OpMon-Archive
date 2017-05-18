#include "MainMenu.hpp"
#include <SDL/SDL_image.h>
#include "../start/main.hpp"
#include <iostream>
#include "OptionsMenu.hpp"

UNS

namespace MainFrame {
namespace MainMenu {

 sf::Sprite fond;
 sf::Text play;
 sf::Text charge;
 sf::Text options;
 sf::Text exit;
 sf::Sprite cursor;
 sf::Vector2f curPos[4];
 sf::Music fondMusTitle;
 sf::Sound bruitArr;
 sf::Sound bruitPush;
 sf::Sound bruitNope;
int curPosI = 0;

bool continuer = true;

void initVars() {
    sf::Text *textPos[4] = {&play, &charge, &options, &exit};
    for(int i = 0, j = 175; i < 4; i++) {
        curPos[i].x = 10;
        curPos[i].y = j;
        curPos[i].w = 30;
        curPos[i].h = 30;
        textPos[i]->setPosition(sf::Vector2f(60, j));
        j+=85;
    }
#ifdef _WIN32
    fond = IMG_LoadTexture(renderer, "ressources\\backgrounds\\titlescreen.png");
    cursor = IMG_LoadTexture(renderer, "ressources\\sprites\\misc\\arrChoice.png");
    fondMusTitle = Mix_LoadMUS("ressources\\audio\\music\\title.ogg");
    bruitArr = Mix_LoadWAV("ressources\\audio\\sounds\\select.ogg");
    bruitPush = Mix_LoadWAV("ressources\\audio\\sounds\\selectbuttons.ogg");
    bruitNope = Mix_LoadWAV("ressources\\audio\\sounds\\nope.ogg");
#else
    fond = IMG_LoadTexture(renderer, "ressources/backgrounds/titlescreen.png");
    cursor = IMG_LoadTexture(renderer, "ressources/sprites/misc/arrChoice.png");
    fondMusTitle = Mix_LoadMUS("ressources/audio/music/title.ogg");
    bruitArr = Mix_LoadWAV("ressources/audio/sounds/select.ogg");
    bruitPush = Mix_LoadWAV("ressources/audio/sounds/selectbuttons.ogg");
    bruitNope = Mix_LoadWAV("ressources/audio/sounds/nope.ogg");
#endif // _WIN32
    play = renderText(renderer, kget("title.1"), font, blanc, &(textPos[0]));
    charge = renderText(renderer, kget("title.2"), font, blanc, &(textPos[1]));
    options = renderText(renderer, kget("title.3"), font, blanc, &(textPos[2]));
    exit = renderText(renderer, kget("title.4"), font, blanc, &(textPos[3]));
    //Mix_Volume(2, MIX_MAX_VOLUME / 4);
    //Mix_Volume(1, MIX_MAX_VOLUME);
    //Mix_Volume(0, MIX_MAX_VOLUME / 2);
    OptionsMenu::initVars();
}

void verifVars() {
    if(fond == NULL || play == NULL || charge == NULL || options == NULL || exit == NULL || cursor == NULL) {
        rerrLog << "Erreur dans l'initialisation de textures (MainMenu)" << endl;
        gererErreur(SDL_GetError(), false);
    }
    if(fondMusTitle == NULL) {
        rerrLog << "Erreur dans l'ouverture d'une musique (MainMenu) (fondMusTitle)" << endl;
        gererErreur(Mix_GetError(), false);
    }
    if(bruitArr == NULL || bruitPush == NULL || bruitNope == NULL) {
        rerrLog << "Erreur dans l'ouverture d'un son (MainMenu) (bruits)" << endl;
        gererErreur(Mix_GetError(), false);
    }
}

void deleteVars() {
    OptionsMenu::deleteVars();
    SDL_DestroyTexture(fond);
    SDL_DestroyTexture(play);
    SDL_DestroyTexture(charge);
    SDL_DestroyTexture(options);
    SDL_DestroyTexture(exit);
    SDL_DestroyTexture(cursor);
    Mix_FreeMusic(fondMusTitle);
    Mix_FreeChunk(bruitArr);
    Mix_FreeChunk(bruitPush);
    Mix_FreeChunk(bruitNope);
}

int boucle0() {
    while(continuer) {
        SDL_WaitEvent(&events);
        switch(events.type) {
            QUIT

        case SDL_KEYDOWN:
            switch (events.key.keysym.sym) {
            case SDLK_RETURN:

                switch(curPosI) {
                    //Traitement de l'action en fonction de la position du curseur
                case 0:
                    return 0;
                case 3:
                    return -1;
                case 2:
                    if(OptionsMenu::optionsMenu() == -1){
                        return -1;
                    }
                    break;
                case 1:
                    Mix_PlayChannel(0, bruitNope, 0);
                    break;
                }
                break;

            case SDLK_DOWN:
                Mix_PlayChannel(2, bruitArr, 0);
                curPosI++;
                //Si en bas, retourne en haut
                if(curPosI >= 4) {
                    curPosI = 0;
                } else if(curPosI < 0) {
                    curPosI = 3;
                }
                break;

            case SDLK_UP:
                Mix_PlayChannel(2, bruitArr, 0);
                curPosI--;
                //Si en haut, retourne en bas
                if(curPosI >= 4) {
                    curPosI = 0;
                } else if(curPosI < 0) {
                    curPosI = 3;
                }
                break;

                ECHAP
            }
            break;
        }

        //Actualisation des éléments
        SDL_RenderCopy(renderer, fond, NULL, &MainFrame::fond);
        SDL_RenderCopy(renderer, play, NULL, &textPos[0]);
        SDL_RenderCopy(renderer, charge, NULL, &textPos[1]);
        SDL_RenderCopy(renderer, options, NULL, &textPos[2]);
        SDL_RenderCopy(renderer, exit, NULL, &textPos[3]);
        SDL_RenderCopy(renderer, cursor, NULL, &curPos[curPosI]);
        SDL_RenderPresent(renderer);
    }
    return 0;
}

int mainMenu() {

    verifVars();
    //Début de la musique
    Mix_PlayMusic(fondMusTitle, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
    //Lancement de la boucle
    return boucle0();
}

}
}
