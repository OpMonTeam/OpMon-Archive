#include "MainFrame.hpp"
#include <iostream>
#include "../start/main.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <cstring>
#include "../start/StringKeys.hpp"
#include "../start/main.hpp"
#include <string>
#include <SDL/SDL_mixer.h>
#include "MainMenu.hpp"
#include "../start/Initializer.hpp"
#include "Overworld.hpp"

#include "StartScene.hpp"


UNS

namespace MainFrame {
SDL_Window *frame = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event events;
SDL_Rect fond = {0, 0, 512, 512};
TTF_Font *font = NULL;
SDL_Rect dialogP = {0, 0, 0, 0};
SDL_Texture *dialogT = NULL;
SDL_Rect textPlace = {0, 0, 0, 0};
SDL_Color noir = {0, 0, 0};
SDL_Color blanc = {255, 255, 255};
SDL_Joystick *manette = NULL;
Mix_Chunk *dialogPass = NULL;
TTF_Font *fonts[72] = {};
bool init = false;

int printChoice(string text, string choice1, string choice2, string choix3) {
    //Non fini
    /*bool triple = true;
    if(choix3 == ""){
        triple = false;
    }
    if(text == "" || choice1 == "" || choice2 == ""){
        gererErreur("MainFrame::printChoice : Chaine de caractère vide.", true);
    }
    SDL_Rect placeChoix[3];
    SDL_Texture *choix[3];
    SDL_Texture *texte;
    SDL_Texture *fondDialogue;
    texte = renderText(renderer, text, font, noir, textPlace);*/
}

int printText(SDL_Renderer *renderer, string txt, string line2S, string line3S) {
    SDL_Texture *textUre = NULL;
    SDL_Surface *sfce = NULL;
    SDL_Texture *line2 = NULL;
    SDL_Surface *sfce2 = NULL;
    SDL_Texture *line3 = NULL;
    SDL_Surface *sfce3 = NULL;
    SDL_Rect posLineTwo;
    SDL_Rect posLineThree;

    if (txt == "" || line2S == "" || line3S == "") {
        gererErreur("Chaine de caractère vide (fonction MainFrame::printText)", true);
    }


    sfce = TTF_RenderUTF8_Blended(font, txt.c_str(), noir);
    textPlace.h = sfce->h;
    textPlace.w = sfce->w;
    textUre = SDL_CreateTextureFromSurface(renderer, sfce);


    sfce2 = TTF_RenderUTF8_Blended(font, line2S.c_str(), noir);
    posLineTwo.h = sfce2->h;
    posLineTwo.w = sfce2->w;
    posLineTwo.x = textPlace.x;
    posLineTwo.y = textPlace.y + 32;
    line2 = SDL_CreateTextureFromSurface(renderer, sfce2);

    sfce3 = TTF_RenderUTF8_Blended(font, line3S.c_str(), noir);
    posLineThree.h = sfce3->h;
    posLineThree.w = sfce3->w;
    posLineThree.x = textPlace.x;
    posLineThree.y = textPlace.y + 32 + 32;
    line3 = SDL_CreateTextureFromSurface(renderer, sfce3);

    SDL_RenderCopy(renderer, line3, NULL, &posLineThree);
    SDL_RenderCopy(renderer, line2, NULL, &posLineTwo);
    SDL_RenderCopy(renderer, textUre, NULL, &textPlace);
    SDL_DestroyTexture(line3);
    SDL_DestroyTexture(textUre);
    SDL_DestroyTexture(line2);
    SDL_FreeSurface(sfce);
    SDL_FreeSurface(sfce2);
    SDL_FreeSurface(sfce3);
    return 0;
}

void open() {
    //Initialisations
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO) == -1) {
        rerrLog << "Erreur d'initialisation de SDL." << endl;
        rlog << "Une erreur fatale s'est produite. Merci de consulter errLog.txt" << endl;
        gererErreur(SDL_GetError(), true);
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        rerrLog << "Erreur d'initialisation de SDL_Image" << endl;
        gererErreur(IMG_GetError(), true);

    }

    if (TTF_Init() == -1) {
        rerrLog << "Erreur d'initialisation de SDL_ttf" << endl;
        gererErreur(TTF_GetError(), true);
    }
    if(Mix_Init(MIX_INIT_OGG) == -1) {
        rerrLog << "Erreur d'initialisation de SDL_mixer ogg" << endl;
        gererErreur(Mix_GetError(), true);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
        rerrLog << "Erreur d'initilisation de SDL_Mixer" << endl;
        gererErreur(Mix_GetError(), true);
    }
    //Ouverture de la police
    rlog << PRINT_TICKS << "Initialisation des SDL terminée" << endl;
#ifdef _WIN32
    font = TTF_OpenFont("ressources\\fonts\\arial.ttf", 28);
#else
    font = TTF_OpenFont("ressources/fonts/arial.ttf", 28);
#endif

    if (font == NULL) {
        rerrLog << "Erreur d'initialisation de la police d'écriture." << endl;
        gererErreur(TTF_GetError(), true);
    }
    for(unsigned int f = 0; f < 72; f++) {
#ifdef _WIN32
        fonts[f] = TTF_OpenFont("ressources\\fonts\\arial.ttf", f + 1);
#else
        fonts[f] = TTF_OpenFont("ressources/fonts/arial.ttf", f + 1);
#endif // _WIN32
        if(fonts[f] == NULL) {
            rerrLog << "Initialisation d'une police échouée : ID : " << f << endl;
            gererErreur(TTF_GetError(), true);
        }
    }
    rlog << PRINT_TICKS << "Initialisation de la police terminée" << endl;


    //Annonce que l'initialisation principale est terminée
    init = true;
    //Ouverture de la fenetre
    frame = SDL_CreateWindow("OpMon Lazuli", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN);
    //Création du renderer.
    renderer = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED);
    if (frame == NULL || renderer == NULL) {
        rerrLog << "Erreur d'ouverture de la fenetre ou du renderer." << endl;
        gererErreur(SDL_GetError(), true);
    }
    rlog << PRINT_TICKS << "Initialisation de la fenetre et du renderer terminée" << endl;
    //Ouverture de la manette (Je sais pas si ca se dit "ouverture de la manette" mais c'est pas grave)
    manette = SDL_JoystickOpen(0);
    if (manette == NULL) {
        gererErreur("Aucune manette détectée", false);
    } else {
        rlog << PRINT_TICKS << "Initialisation du joystick terminée" << endl;
    }
    Mix_AllocateChannels(3);
#ifdef _WIN32
    dialogPass = Mix_LoadWAV("ressources\\audio\\sounds\\dialogChange.ogg");
#else
    dialogPass = Mix_LoadWAV("ressources/audio/sounds/dialogChange.ogg");
#endif
    if (dialogPass == NULL) {
        rerrLog << "Ouverture du son de changement de dialogue échouée." << endl;
        gererErreur(Mix_GetError(), false);
    }
    rlog << PRINT_TICKS << "Chargement des sprites globaux (Initializer)" << endl;
    Initializer::initSprites();
    Mix_Volume(1, MIX_MAX_VOLUME - 1);
    if(MainMenu::mainMenu() != -1) {
        Mix_PlayChannel(1, MainMenu::bruitPush, 0);
        Utils::wait(WAIT_DEFAULT);
        if(StartScene::startScene() != -1){
            while(Overworld::overworld() != -1){
                if(MainMenu::mainMenu() != -1){
                    if(StartScene::startScene() != -1){

                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
        }
    } else {
        Mix_PlayChannel(1, MainMenu::bruitPush, 0);
        Utils::wait(WAIT_DEFAULT);
    }


    rlog << PRINT_TICKS << "Fermeture de la fenetre" << endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(frame);
    SDL_JoystickClose(manette);
    TTF_CloseFont(font);
    Mix_FreeChunk(dialogPass);

    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}



SDL_Texture *renderText(SDL_Renderer *renderer, char text[], TTF_Font *police, SDL_Color color, SDL_Rect *pos) {
    SDL_Surface *sfce = TTF_RenderUTF8_Blended(police, text, color);
    if (sfce == NULL) {
        rerrLog << "MainFrame::renderText() : ";
        gererErreur(TTF_GetError(), true);
    }
    pos->h = sfce->h;
    pos->w = sfce->w;
    SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
    SDL_FreeSurface(sfce);
    return toReturn;
}

SDL_Texture *renderText(SDL_Renderer *renderer, string text, TTF_Font *police, SDL_Color color, SDL_Rect *pos) {
    SDL_Surface *sfce = TTF_RenderUTF8_Blended(police, text.c_str(), color);
    if (sfce == NULL) {
        rerrLog << "MainFrame::renderText() : ";
        gererErreur(TTF_GetError(), true);
    }
    pos->h = sfce->h;
    pos->w = sfce->w;
    SDL_Texture *toReturn = SDL_CreateTextureFromSurface(renderer, sfce);
    SDL_FreeSurface(sfce);
    return toReturn;
}


}
