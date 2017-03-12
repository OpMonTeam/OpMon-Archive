#include "MainMenu.hpp"

namespace MainFrame{
    namespace MainMenu{

     SDL_Texture *fond = NULL;
     SDL_Texture *play = NULL;
     SDL_Texture *charge = NULL;
     SDL_Texture *options = NULL;
     SDL_Texture *exit = NULL;
     SDL_Texture *cursor = NULL;
     SDL_Rect curPos[4] = {};
     SDL_Rect textPos[4] = {};

     void initVars(){
        for(int i = 0, j = 175; i < 4, i++){
            curPos[i].x = 50;
            curPos[i].y = j;
            textPos[i].x = 60;
            textPos[i].y = j;
            j+=85;
        }
        #ifdef _WIN32
        fond = IMG_LoadTexture(renderer, "ressources\\backgrounds\\titlescreen.png");
        cursor = IMG_LoadTexture(renderer, "ressources\\sprites\\misc\\arrChoice.png");
        #else
        fond = IMG_LoadTexture(renderer, "ressources/backgrounds/titlescreen.png");
        cursor = IMG_LoadTexture(renderer, "ressources/sprites/misc/arrChoice.png");
        #endif // _WIN32
        play = renderText(renderer, kget("title.1"), font, blanc, &(textPos[0]));
        charge = renderText(renderer, kget("title.2"), font, blanc, &(textPos[1]));
        options = renderText(renderer, kget("title.3"), font, blanc, &(textPos[2]));
        exit = renderText(renderer, kget("title.4"), font, blanc, &(textPos[3]));
     }

     void verifVars(){
        if(fond == NULL || play == NULL || charge == NULL || options == NULL || exit == NULL || cursor == NULL){
            rerrLog << "Erreur dans l'initialisation de textures (MainMenu)" << endl;
            gererErreur(SDL_GetError(), false);
        }
     }

     void deleteVars(){
        SDL_DestroyTexture(fond);
        SDL_DestroyTexture(play);
        SDL_DestroyTexture(charge);
        SDL_DestroyTexture(options);
        SDL_DestroyTexture(exit);
        SDL_DestroyTexture(cursor);
     }

    void mainMenu(){

        initVars();
        verifVars();
    }
}

}
