#include "Update.hpp"
#include <iostream>
#include "../start/main.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "../gui/Elements.hpp"

UNS

namespace Update{

    extern SDL_Texture *btnFond = NULL;
    extern SDL_Texture *selectSurbr = NULL;

    void openDialog(){
        rlog << PRINT_TICKS << "Ouverture du dialogue de mise a jour..." << endl;
        SDL_Window *dialog = SDL_CreateWindow(kget("update.title").c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 200, SDL_WINDOW_SHOWN);
        SDL_Renderer *dialogRenderer = SDL_CreateRenderer(dialog, -1, SDL_RENDERER_ACCELERATED);
        #ifdef _WIN32
        selectSurbr = IMG_LoadTexture(dialogRenderer, "ressources\\sprites\\misc\\selectBar.png");
        btnFond = IMG_LoadTexture(dialogRenderer, "ressources\\backgrounds\\dialog\\dialog.png");
        #else
        selectSurbr = IMG_LoadTexture(dialogRenderer, "ressources/sprites/misc/selectBar.png");
        btnFond = IMG_LoadTexture(dialogRenderer, "ressources/backgrounds/dialog/dialog.png");
        #endif // _WIN32
        J_Texture *textInfo = NULL;
        textInfo->texture = NULL;
        #ifdef VERS_DEV
        if(Main::devUpdate){
            textInfo = MainFrame::renderText(dialogRenderer, kget("update.dev.info"), MainFrame::fonts[FONT_SIZE_DEFAULT], MainFrame::noir);
        }else{
        #endif
        textInfo = MainFrame::renderText(dialogRenderer, kget("update.info"), MainFrame::fonts[FONT_SIZE_DEFAULT], MainFrame::noir);
        #ifdef VERS_DEV
        }
        #endif // VERS_DEV

        J_Texture *yup;
        yup = MainFrame::renderText(dialogRenderer, kget("yup"), MainFrame::fonts[FONT_SIZE_DEFAULT], MainFrame::noir);
        J_Texture *nope;
        nope = MainFrame::renderText(dialogRenderer, kget("nope"), MainFrame::fonts[FONT_SIZE_DEFAULT], MainFrame::noir);
        SDL_Rect btnPos[2];
        btnPos[0].x = 150;
        btnPos[0].y = 150;
        btnPos[0].h = 40;
        btnPos[0].w = 50;
        btnPos[1].x = 150;
        btnPos[1].y = 300;
        btnPos[1].h = 40;
        btnPos[1].w = 50;
        yup->rect.x = 160;
        yup->rect.y = 160;
        nope->rect.x = 160;
        nope->rect.y = 310;
        textInfo->rect.x = 75;
        textInfo->rect.y = 50;
        bool continuer = true;
        bool doUpdate = true;
        SDL_Event events;
        bool choix = false;
        SDL_RenderCopy(dialogRenderer, btnFond, NULL, &(btnPos[0]));
        SDL_RenderCopy(dialogRenderer, btnFond, NULL, &(btnPos[1]));
        J_RenderCopy(dialogRenderer, yup);
        J_RenderCopy(dialogRenderer, nope);
        SDL_RenderCopy(dialogRenderer, selectSurbr, NULL, &(btnPos[choix]));
        DEBUG_CHECK(Pause problème?);
        DEBUG_CHECK(SDL?) << textInfo->texture << endl;
        J_RenderCopy(dialogRenderer, textInfo);
        DEBUG_CHECK(Ou pas.);
        SDL_RenderPresent(dialogRenderer);
        rlog << PRINT_TICKS << "Fenetre ouverte" << endl;
        while(continuer){
            SDL_WaitEvent(&events);
            switch(events.type){
                case SDL_KEYDOWN:
                    switch(events.key.keysym.sym){
                    case SDLK_LEFT:
                        choix = !choix;
                        break;
                    case SDLK_RIGHT:
                        choix = !choix;
                        break;
                    case SDLK_RETURN:
                        doUpdate = !choix;
                        continuer = false;
                        break;
                    case SDLK_ESCAPE:
                        doUpdate = false;
                        continuer = false;
                        break;
                    }
                break;
                case SDL_QUIT:
                    doUpdate = false;
                    continuer = false;
                break;
            }
            SDL_RenderCopy(dialogRenderer, btnFond, NULL, &(btnPos[0]));
            SDL_RenderCopy(dialogRenderer, btnFond, NULL, &(btnPos[1]));
            J_RenderCopy(dialogRenderer, yup);
            J_RenderCopy(dialogRenderer, nope);
            SDL_RenderCopy(dialogRenderer, selectSurbr, NULL, &(btnPos[*((int*)(&choix))]));
            J_RenderCopy(dialogRenderer, textInfo);

            SDL_RenderPresent(dialogRenderer);

        }
        if(doUpdate){update();}

        rlog << PRINT_TICKS << "Fermeture de la fenetre de dialogue de MAJ" << endl;




    }

    void update(){}
}
