#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
UNS
Plan::Plan(SDL_Texture *couche1, SDL_Texture *couche2, SDL_Texture *couche3, int w, int h, int tabNbre){
    this->couche1 = couche1;
    this->couche2 = couche2;
    //this->events = events;
    this->couche3 = couche3;
    this->w = w;
    this->h = h;
    rerrLog << "PlanCheck1" << endl;
    this->passTab = (int**)malloc(h * sizeof(int*));
    for(unsigned int i = 0; i < h; i++){
        this->passTab[i] = (int*)malloc(w * sizeof(int));
    }
    rerrLog << "PlanCheck2" << endl;
    for(unsigned int i = 0; i < h; i++){
        rerrLog << "i = " << i << endl;
        for(unsigned int j = 0; j < w; j++){
            rerrLog << "j = " << j << "passTab = " << (Initializer::tabs[tabNbre][i][j]) << endl;
            this->passTab[i][j] = (Initializer::tabs[tabNbre][i][j]);
        }
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
