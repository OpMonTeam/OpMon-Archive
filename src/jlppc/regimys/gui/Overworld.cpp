#include "Overworld.hpp"
#include "../start/Initializer.hpp"
#include "../start/main.hpp"
#include SQUARE 32

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
        bool movePlan = true;//Indique si le plan doit etre déplacé ou si le plan doit être déplacé


        void down(){
            startFrames = frames;
            anim = DOWN;
            if((ppPos.y/SQUARE + 1) < (actuel->h/SQUARE)){
                if(actuel->passTab[(ppPos.y / SQUARE) + 1][ppPos.x / SQUARE] == 0){
                    //Ensuite faudra faire la verif du passages des events
                    moving = DOWN;
                    if(ppPos.y/SQUARE + 9 >= actuel->h/SQUARE){
                        movePlan = false;
                    }else if(ppPos.y/SQUARE - 9 < 0){
                        movePlan = false;
                    }else{
                        movePlan = true;
                    }
                }
            }

        }

        void initVars() {
            actuel = Initializer::faubourgEuvi;
            #ifdef _WIN32

            #else
            spritePP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp0.png");
            spritePP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp1.png");
            spritePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp2.png");
            spritePP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/pp3.png");
            marchePP[FACE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/mpp0.png");
            marchePP[DROITE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/mpp1.png");
            marchePP[GAUCHE] = IMG_LoadTexture(renderer, "ressources/sprites/chara/mpp2.png");
            marchePP[DOS] = IMG_LoadTexture(renderer, "ressources/sprites/chara/mpp3.png");
            #endif // _WIN32

        }
        void verifVars() {
            if(actuel == NULL){
                gererErreur("Map du fauxbourg euvi manquante. Erreur.", true);
            }
        }
        void deleteVars() {}
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
                                break;

                            }
                            break;

                        case SDL_JOYBUTTONDOWN:
                            if (!joypressed) {
                                joypressed = true;
                                switch (events.jbutton.button)
                                    JOYQUIT
                                }
                            }
                            break;

                            /*case SDL_WINDOWEVENT:
                                switch (events.window.event) {
                                    case SDL_WINDOWEVENT_RESIZED:
                                        break;
                                }
                                break;*/

                    } else {
                        SDL_Delay(FPS_TICKS - (SDL_GetTicks() - ancientTick));
                    }
                }
            }
        }
    }
}
