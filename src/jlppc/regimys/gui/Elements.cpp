#include "Elements.hpp"

Plan::Plan(SDL_Texture *couche1, SDL_Texture *couche2, SDL_Texture *couche3){
    this->couche1 = couche1;
    this->couche2 = couche2;
    //this->events = events;
    this->couche3 = couche3;
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
