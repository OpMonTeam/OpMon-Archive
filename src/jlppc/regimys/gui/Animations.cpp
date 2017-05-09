#include "Animations.hpp"
#include "MainFrame.hpp"
UNS

namespace Animations {

bool init = false;
SDL_Event events;
int ancientTick = 0;
bool continuer = false;
bool joypressed = false;

void initAnims() {

    init = true;
}

void deleteAnims() {
    init = false;
}

int animFenOpen(SDL_Renderer *renderer, SDL_Texture *fond) {
    ANIM_CHECK_INIT//Vérification de l'initialisation des animations
    //Déclaration des variables
    SDL_Texture *anim[6] = {NULL};
    SDL_Rect animP;
    animP.h = 512;
    animP.w = 512;
    animP.x = 0;
    animP.y = 0;
    //Frame par frame
    for (int i = 0; i < 6; i++) {
        if ((SDL_GetTicks() - ancientTick) >= 200) {
            SDL_PollEvent(&events);
            rerrLog << events.type << endl;

            switch (events.type) {
                QUIT

            case SDL_KEYDOWN:
                switch (events.key.keysym.sym) {
                    ECHAP
                }

                break;

            case SDL_JOYBUTTONDOWN:
                if (!joypressed) {
                    joypressed = true;
                    switch (events.jbutton.button) {
                        JOYQUIT
                    }
                }



                break;
            case SDL_JOYBUTTONUP:
                joypressed = false;
                break;
            }

            ostringstream oss;
            //Oui je sais c'est pas opti de les init ici mais MERDE. Je fais ce que je veux.
#ifdef _WIN32
            oss << "ressources\\animations\\winChange\\animWindowFrame" << i + 1 << ".png";
#else
            oss << "ressources/animations/winChange/animWindowFrame" << i + 1 << ".png";
#endif // _WIN32

            anim[i] = IMG_LoadTexture(renderer, oss.str().c_str());
            SDL_RenderCopy(renderer, fond, NULL, &animP);
            SDL_RenderCopy(renderer, anim[i], NULL, &animP);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(anim[i]);
        } else {
            SDL_Delay(200 - (SDL_GetTicks() - ancientTick));
            i--;
        }
    }
    return 0;
}

int animFenClose(SDL_Renderer *renderer, SDL_Texture *fond) {
    //Se réferer aux commentaires de la fonction précédente
    ANIM_CHECK_INIT
    SDL_Rect animP;
    SDL_Texture *anim[6] = {NULL};
    animP.h = 512;
    animP.w = 512;
    animP.x = 0;
    animP.y = 0;
    for (int i = 5; i >= 0; i--) {
        if ((SDL_GetTicks() - ancientTick) >= 200) {
            SDL_PollEvent(&events);

            switch (events.type) {
                QUIT

            case SDL_KEYDOWN:
                switch (events.key.keysym.sym) {
                    ECHAP
                }

                break;

            case SDL_JOYBUTTONDOWN:
                if (!joypressed) {
                    joypressed = true;
                    switch (events.jbutton.button) {
                        JOYQUIT
                    }
                }



                break;
            case SDL_JOYBUTTONUP:
                joypressed = false;
                break;
            }
            ostringstream oss;

#ifdef _WIN32
            oss << "ressources\\animations\\winChange\\animWindowFrame" << i + 1 << ".png";
#else
            oss << "ressources/animations/winChange/animWindowFrame" << i + 1 << ".png";
#endif // _WIN32

            anim[i] = IMG_LoadTexture(renderer, oss.str().c_str());
            SDL_RenderCopy(renderer, fond, NULL, &animP);
            SDL_RenderCopy(renderer, anim[i], NULL, &animP);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(anim[i]);
        } else {
            SDL_Delay(200 - (SDL_GetTicks() - ancientTick));
            i++;
        }
    }
    return 0;
}


}
