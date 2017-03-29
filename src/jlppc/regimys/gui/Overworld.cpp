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
        bool mapChanged = true;
        Mix_Music *fond;
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
        bool mapMove[] = {true, true, true, true};
        int startFrames = 0;
        SDL_Rect camera = {0, 0, 512, 512};
        int ppPosX = 17;
        int ppPosY = 15;

        void down(){
            if(anim == -1){
                startFrames = frames;
                anim = DOS;
                if(actuel->getPassTab()[(ppPosY + 1) + 1][ppPosX + 1] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = DOS;
                        ppPosY++;
                        //Faudra ici gerer le déplacement de la map
                        rerrLog << "ppPosY = " << ppPosY + 8 << " et actuel->getH() = " << actuel->getH() << endl;
                        if(ppPosY + 8 >= actuel->getH()){
                            mapMove[DOS] = false;
                            mapMove[FACE] = false;
                        }else if(ppPosY >= 8){
                            mapMove[FACE] = true;
                             mapMove[DOS] = true;
                        }
                }
            }


        }

        void up(){
            if(anim == -1){
                startFrames = frames;
                anim = FACE;
                    if(actuel->getPassTab()[(ppPosY + 1) - ((ppPosY + 1 <= 0) ? 0 : 1)][ppPosX + 1] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = FACE;
                        ppPosY--;
                        //Faudra ici gerer le déplacement de la map
                        if(ppPosY - 6 <= 0){
                            mapMove[FACE] = false;
                            mapMove[DOS] = false;
                        }else if(ppPosY <= actuel->getH() - 10){
                            mapMove[DOS] = true;
                            mapMove[FACE] = true;
                        }
                    }
            }
        }
        void right(){
            if(anim == -1){
                startFrames = frames;
                anim = DROITE;
                    if(actuel->getPassTab()[(ppPosY + 1)][(ppPosX + 1) + 1] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = DROITE;
                        ppPosX++;
                        //Faudra ici gerer le déplacement de la map
                        if(ppPosX + 6 >= actuel->getW()){
                            mapMove[DROITE] = false;
                            mapMove[GAUCHE] = false;
                        }else if(ppPosX >= 8){
                            mapMove[DROITE] = true;
                            mapMove[GAUCHE] = true;
                        }
                    }
            }

        }

        void left(){
            if(anim == -1){
                startFrames = frames;
                anim = GAUCHE;
                    if(actuel->getPassTab()[(ppPosY + 1)][(ppPosX + 1) - ((ppPosX + 1 <= 0) ? 0 : 1)] == 0){
                        //Ensuite faudra faire la verif du passages des events
                        moving = GAUCHE;
                        ppPosX--;
                        //Faudra ici gerer le déplacement de la map
                        if(ppPosX - 8 <= 0){
                                mapMove[GAUCHE] = false;
                                mapMove[DROITE] = false;
                        }else if(ppPosX <= actuel->getW() - 8){
                                mapMove[GAUCHE] = true;
                                mapMove[DROITE] = true;
                        }
                    }
            }
        }

        void initVars() {
            rlog << PRINT_TICKS << "Initialisation des variables et des sprites" << endl;
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
            marche2PP[DOS] = IMG_LoadTexture(renderer, "ressources\\sprites\\chara\\pp\\mpp23.png");;
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
            fond = actuel->getFond();
            mapPos.x = -(8*SQUARE);
            mapPos.y = -(8*SQUARE);
            mapPos.h = 1024;
            mapPos.w = 1024;
            ppPos.x = mapPos.x + (ppPosX*SQUARE) + 16;
            ppPos.y = mapPos.y + (ppPosY*SQUARE);
            ppPos.w = 64;
            ppPos.h = 64;

        }
        void verifVars() {
            rlog << PRINT_TICKS << "Vérification des variables" << endl;
            if(actuel == NULL){
                gererErreur("Map du fauxbourg euvi manquante. Erreur.", true);
            }
            for(int i = 0; i < 4; i++){
                if(spritePP[i] == NULL){
                    rerrLog << "Sprite du PP n°"<< i << " manquant." << endl;
                    gererErreur(IMG_GetError(), false);
                }
            }
            for(int i = 0; i < 4; i++){
                if(marchePP[i] == NULL){
                    rerrLog << "Sprite de marche du PP n°"<< i << " manquant." << endl;
                    gererErreur(IMG_GetError(), false);
                }
            }
           for(int i = 0; i < 4; i++){
                if(marche2PP[i] == NULL){
                    rerrLog << "Sprite de marche 2 du PP n°"<< i << " manquant." << endl;
                    gererErreur(IMG_GetError(), false);
                }
            }

        }
        void deleteVars() {
            rlog << PRINT_TICKS << "Suppression des variables de l'overworld..." << endl;
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
            rlog << PRINT_TICKS << "Entrée dans l'overworld..." << endl;
            initVars();
            verifVars();
            Mix_PlayMusic(fond, -1);
            Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
            int returne = boucle();
            deleteVars();
            return returne;
        }

        int boucle() {
            rlog << PRINT_TICKS << "Entrée dans la boucle de l'overworld..." << endl;
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
                        if(actuel->getFond() != fond){
                                Mix_PlayMusic(fond, -1);
                                Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
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
                                moving = -1;
                                //mapPos.y = mapPos.y - 4;
                            }else{
                                if(moving == DOS){
                                    //ppPos.y = ppPos.y + 1;
                                    if(mapMove[DOS]){
                                        mapPos.y = mapPos.y - 4;
                                    }else{
                                        ppPos.y = ppPos.y + 4;
                                    }

                                }
                            }
                            ppDir = FACE;
                        }else if(anim == FACE){
                            if(frames - startFrames == 8){
                                anim = -1;
                                moving = -1;
                                //mapPos.y = mapPos.y + 4;
                            }else{
                                if(moving == FACE){
                                    //ppPos.y = ppPos.y - 1;
                                    if(mapMove[FACE]){
                                        mapPos.y = mapPos.y + 4;
                                    }else{
                                        ppPos.y = ppPos.y - 4;
                                    }
                                }

                            }

                            ppDir = DOS;
                        }else if(anim == DROITE){
                            if(frames - startFrames == 8){
                                anim = -1;
                                moving = -1;
                               // mapPos.x = mapPos.x - 4;
                            }else{
                                if(moving == DROITE){
                                    //ppPos.x = ppPos.x + 1;
                                    if(mapMove[DROITE]){
                                        mapPos.x = mapPos.x - 4;
                                    }else{
                                        ppPos.x = ppPos.x + 4;
                                    }
                                }

                            }

                            ppDir = DROITE;
                        }else if(anim == GAUCHE){
                            if(frames - startFrames == 8){
                                anim = -1;
                                moving = -1;
                                //mapPos.x = mapPos.x + 4;
                            }else{
                                if(moving == GAUCHE){
                                    //ppPos.x = ppPos.x - 1;
                                    if(mapMove[GAUCHE]){
                                        mapPos.x = mapPos.x + 4;
                                    }else{
                                        ppPos.x = ppPos.x - 4;
                                    }
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
