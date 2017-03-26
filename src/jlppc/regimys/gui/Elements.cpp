#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include <cstdlib>
UNS
//Idée : Enregistrer les collisions dans un fichier temporaire qui sera supprimé juste après
Plan::Plan(SDL_Texture *couche1, SDL_Texture *couche2, SDL_Texture *couche3, int w, int h, string filename){
    this->couche1 = couche1;
    this->couche2 = couche2;
    //this->events = events;
    this->couche3 = couche3;
    this->w = w;
    this->h = h;
    this->passTab = (int**)malloc(h * sizeof(int*));
    for(unsigned int i = 0; i < h; i++){
        this->passTab[i] = (int*)malloc(w * sizeof(int));
    }
    ifstream inTemp(filename.c_str());
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            inTemp >> passTab[i][j];
            rerrLog << "Plan i=" << i << " et j=" << j << " est égal a " << passTab[i][j] << endl;
        }
    }
    #ifdef _WIN32
    system((string("DEL ") + filename).c_str());
    #else
    system((string("rm ") + filename).c_str());
    #endif // _WIN32

}

Plan::~Plan(){
    free(passTab);
}

/*Plan::~Plan(){
    for(unsigned int i = 0; i < 32; i++){
        for(unsigned int j = 0; j < 32; j++){
            delete(events[i][j]);
        }
    }
}*/

namespace Elements {

}
