#include "Elements.hpp"
#include <cstdlib>

Plan::Plan(SDL_Texture *couche1, SDL_Texture *couche2, SDL_Texture *couche3, int w, int h, vector<bool> passTab[]){
    this->couche1 = couche1;
    this->couche2 = couche2;
    //this->events = events;
    this->couche3 = couche3;
    this->w = w;
    this->h = h;
    this->passTab = (vector<bool>*)malloc(h * w * sizeof(vector<bool>));
    for(unsigned int i = 0; i < (w * h); i++){
        this->passTab[i] = passTab[i];
    }
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
