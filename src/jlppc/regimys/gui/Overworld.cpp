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
        SDL_Texture *marche2PP[4] = {};
        SDL_Rect ppPos = {};
        SDL_Rect mapPos = {};
        int moving = -1;//Signale le mouvement a la boucle
        int anim = -1;//Signale l'animation a la boucle
        int ppDir = 0;
        int frames = 0;
        int startFrames = 0;
        SDL_Rect camera = {0, 0, 512, 512};
        int ancienPosX = 0;
        int ancienPosY = 0;

        void down(){
            if(anim == -1){
                startFrames = frames;
                anim = DOS;
                moving = DOS;
                return;
                if((ppPos.y/SQUARE + mapPos.y/SQUARE + 1) < (actuel->getH()*SQUARE)){
                    if(actuel->getPassTab()[(ppPos.y / SQUARE) + 1][ppPos.x / SQUARE] == 0){

                        //Ensuite faudra faire la verif du passages des events
                        moving = DOS;
                        //Faudra ici gerer le déplacement de la map
                    }
                }
            }


        }

        void up(){
            if(anim == -1){
                startFrames = frames;
                anim = FACE;
                moving = FACE;
                return;
                if((ppPos.y/SQUARE + mapPos.y/SQUARE - 1) > 0){
                    if(actuel->getPassTab()[(ppPos.y / SQUARE) - ((ppPos.y/SQUARE <= 0) ? 0 : 1)][ppPos.x / SQUARE] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = FACE;
                        //Faudra ici gerer le déplacement de la map
                    }
                }
            }
        }
        void right(){
            if(anim == -1){
                startFrames = frames;
                anim = DROITE;
                moving = DROITE;
                return;
                if((ppPos.x/SQUARE + mapPos.x/SQUARE + 1) < (actuel->getW()*SQUARE)){
                    if(actuel->getPassTab()[(ppPos.y / SQUARE)][(ppPos.x / SQUARE) + 1] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = DROITE;
                        //Faudra ici gerer le déplacement de la map
                    }
                }
            }

        }

        void left(){
            if(anim == -1){
                startFrames = frames;
                anim = GAUCHE;
                moving = GAUCHE;
                return;
                if((ppPos.x/SQUARE + mapPos.x/SQUARE - 1) > 0){
                    if(actuel->getPassTab()[(ppPos.y / SQUARE)][(ppPos.x / SQUARE) - ((ppPos.x/SQUARE <= 0) ? 0 : 1)] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = GAUCHE;
                        //Faudra ici gerer le déplacement de la map
                    }
                }
            }
        }

        void initVars() {
            actuel = Initializer::faubourgEuvi;
            #ifdef _WIN32
            spritePP[FACE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\pp0.png");
            spritePP[DROITE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\pp1.png");
            spritePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\pp2.png");
            spritePP[DOS] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\pp3.png");
            marchePP[FACE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp0.png");
            marchePP[DROITE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp1.png");
            marchePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp2.png");
            marchePP[DOS] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp3.png");
            marche2PP[FACE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp20.png");
            marche2PP[DROITE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp21.png");
            marche2PP[GAUCHE] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp22.png");
            marche2PP[DOS] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp23.png");
            #else
            spritePP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp0.png");
            spritePP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp1.png");
            spritePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp2.png");
            spritePP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/pp3.png");
            marchePP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp0.png");
            marchePP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp1.png");
            marchePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp2.png");
            marchePP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp3.png");
            marche2PP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp20.png");
            marche2PP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp21.png");
            marche2PP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp22.png");
            marche2PP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp/mpp23.png");
            #endif // _WIN32
            mapPos.x = -(8*SQUARE);
            mapPos.y = -(8*SQUARE);
            mapPos.h = 1024;
            mapPos.w = 1024;
            ppPos.x = mapPos.x + (16*SQUARE) + 16;
            ppPos.y = mapPos.y + (14*SQUARE);
            ppPos.w = 64;
            ppPos.h = 64;

        }
        void verifVars() {
            if(actuel == NULL){
                gererErreur("Map du fauxbourg euvi manquante. Erreur.", true);
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
        int overworld() {
            initVars();
            verifVars();

            return boucle();
        }

        int boucle() {
            bool anims = false;
            int animsCounter = 0;
            while(continuer) {
                while (continuer) {
                    if ((SDL_GetTicks() - ancientTick) >= (FPS_TICKS)) {
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
                                case SDLK_UP:
                                    up();
                                    break;
                                case SDLK_RIGHT:
                                    right();
                                    break;
                                case SDLK_LEFT:
                                    left();
                                    break;
                                case SDLK_m:
                                    return 2;
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
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, actuel->getCouche1(), NULL, &mapPos);
                        SDL_RenderCopy(renderer, actuel->getCouche2(), NULL, &mapPos);

                        if(anim != -1 && !anims){
                            if(anim == DOS){
                                SDL_RenderCopy(renderer, marchePP[FACE], NULL, &ppPos);
                            }else if(anim == FACE){
                                SDL_RenderCopy(renderer, marchePP[DOS], NULL, &ppPos);
                            }else{
                                SDL_RenderCopy(renderer, marchePP[anim], NULL, &ppPos);
                            }
                            animsCounter++;
                            anims = animsCounter > 8;

                        }else if(anim != -1 && anims){
                            if(anim == DOS){
                                SDL_RenderCopy(renderer, marche2PP[FACE], NULL, &ppPos);
                            }else if(anim == FACE){
                                SDL_RenderCopy(renderer, marche2PP[DOS], NULL, &ppPos);
                            }else{
                                SDL_RenderCopy(renderer, marche2PP[anim], NULL, &ppPos);
                            }
                            animsCounter++;
                            if(animsCounter > 16){
                                anims = false;
                                animsCounter = 0;
                            }
                        }
                        else{
                            SDL_RenderCopy(renderer, spritePP[ppDir], NULL, &ppPos);
                        }

                        SDL_RenderCopy(renderer, actuel->getCouche3(), NULL, &mapPos);

                        if(anim == DOS){
                            if(frames - startFrames == 8){
                                anim = -1;
                                //mapPos.y = mapPos.y - 4;
                            }else{
                                if(moving == DOS){
                                    //ppPos.y = ppPos.y + 1;
                                    mapPos.y = mapPos.y - 4;
                                }
                            }
                            ppDir = FACE;
                        }else if(anim == FACE){
                            if(frames - startFrames == 8){
                                anim = -1;
                                //mapPos.y = mapPos.y + 4;
                            }else{
                                if(moving == FACE){
                                    //ppPos.y = ppPos.y - 1;
                                    mapPos.y = mapPos.y + 4;
                                }

                            }

                            ppDir = DOS;
                        }else if(anim == DROITE){
                            if(frames - startFrames == 8){
                                anim = -1;
                               // mapPos.x = mapPos.x - 4;
                            }else{
                                if(moving == DROITE){
                                    //ppPos.x = ppPos.x + 1;
                                    mapPos.x = mapPos.x - 4;
                                }

                            }

                            ppDir = DROITE;
                        }else if(anim == GAUCHE){
                            if(frames - startFrames == 8){
                                anim = -1;
                                //mapPos.x = mapPos.x + 4;
                            }else{
                                if(moving == GAUCHE){
                                    //ppPos.x = ppPos.x - 1;
                                    mapPos.x = mapPos.x + 4;
                                }

                            }
                            ppDir = GAUCHE;
                        }

                        SDL_RenderPresent(renderer);

                    } else {
                        SDL_Delay((FPS_TICKS) - (SDL_GetTicks() - ancientTick));
                    }
                }
            }
        }
    }
}
