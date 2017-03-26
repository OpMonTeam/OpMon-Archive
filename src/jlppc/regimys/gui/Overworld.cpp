#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#define SQUARE 32
UNS
namespace MainFrame {
    namespace Overworld {
        using namespace Side;

        bool continuer = true;
        long ancientTick = 0;
        bool joypressed = false;
        Plan *actuel = NULL;
        SDL_Texture *spritePP[4] = {};
        SDL_Texture *marchePP[4] = {};
        SDL_Rect ppPos = {};
        SDL_Rect mapPos = {};
        int moving = -1;//Signale le mouvement a la boucle
        int anim = -1;//Signale l'animation a la boucle
        int frames = 0;
        int startFrames = 0;
        SDL_Rect camera = {0, 0, 512, 512};
        int ancienPosX = 0;
        int ancienPosY = 0;

        void down(){
            if(anim == -1){
                startFrames = frames;
                anim = DOS;
                if((ppPos.y/SQUARE + 1) < (actuel->getH()/SQUARE)){
                    if(actuel->getPassTab()[(ppPos.y / SQUARE) + 1][ppPos.x / SQUARE] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = DOS;
                    }
                }
            }


        }

        void initVars() {
            actuel = Initializer::faubourgEuvi;
            #ifdef _WIN32

            #else
            spritePP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp0.png");
            spritePP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp1.png");
            spritePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp2.png");
            spritePP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp3.png");
            marchePP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp0.png");
            marchePP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp1.png");
            marchePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp2.png");
            marchePP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp3.png");
            #endif // _WIN32
            mapPos.x = -8*32;
            mapPos.y = -8*32;
            ppPos.x = mapPos.x + (16*32);
            ppPos.y = mapPos.y + (16*32);
            ppPos.w = 64;
            ppPos.h = 64;

        }
        void verifVars() {
            if(actuel == NULL){
                gererErreur("Map du fauxbourg euvi manquante. Erreur.", true);
            }
            for(int i = 0; i < 8; i++){
                if(i < 4){
                    if(spritePP[i] == NULL){
                        rerrLog << "Sprite du personage principal manquant" << endl;
                        gererErreur(IMG_GetError(), false);
                    }
                }else{
                    if(marchePP[i - 4] == NULL){
                        rerrLog << "Sprite du personage principal manquant" << endl;
                        gererErreur(IMG_GetError(), false);
                    }
                }
            }
        }
        void deleteVars() {
            for(int i = 0; i < 8; i++){
                if(i < 4){
                    if(spritePP[i] != NULL){
                        SDL_DestroyTexture(spritePP[i]);
                    }
                }else{
                    if(marchePP[i - 4] != NULL){
                        SDL_DestroyTexture(marchePP[i - 4]);
                    }
                }
            }
        }
        void overworld() {
            initVars();
            verifVars();

            boucle();
        }

        int boucle() {

            while(continuer) {
                while (continuer) {
                    if ((SDL_GetTicks() - ancientTick) >= FPS_TICKS) {
                        frames++;

                        ancientTick = SDL_GetTicks();

                        SDL_PollEvent(&events);

                        switch (events.type) {
                            QUIT
                        case SDL_KEYDOWN:
                            switch (events.key.keysym.sym) {
                                ECHAP

                                case SDLK_DOWN:
                                    down();
                                break;

                            }
                            break;

                        case SDL_JOYBUTTONDOWN:
                            if (!joypressed) {
                                joypressed = true;
                                switch (events.jbutton.button){
                                    JOYQUIT
                                }
                            }

                            /*case SDL_WINDOWEVENT:
                                switch (events.window.event) {
                                    case SDL_WINDOWEVENT_RESIZED:
                                        break;
                                }
                                break;*/
                        }

                        if(anim == DOS){
                            if(frames - startFrames == 32){
                                anim = -1;
                            }
                            ppPos.y = ppPos.y + 1;
                            mapPos.y = mapPos.y - 1;
                        }
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, actuel->getCouche1(), NULL, &mapPos);
                        SDL_RenderCopy(renderer, actuel->getCouche2(), NULL, &mapPos);
                        SDL_RenderCopy(renderer, spritePP[0], NULL, &ppPos);
                        SDL_RenderCopy(renderer, actuel->getCouche3(), NULL, &mapPos);
                        SDL_RenderPresent(renderer);


                    } else {
                        SDL_Delay(FPS_TICKS - (SDL_GetTicks() - ancientTick));
                    }
                }
            }
        }
    }
}
