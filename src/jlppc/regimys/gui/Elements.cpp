#include "Elements.hpp"

Case::Case(SDL_Texture *texture){
    this->texture = texture;
}

Plan::Plan(Couche couche1, Couche couche2, EventMap events, Couche couche3){
    this->couche1 = couche1;
    this->couche2 = couche2;
    this->events = events;
    this->couche3 = couche3;
}

Plan::~Plan(){
    for(unsigned int i = 0; i < 32; i++){
        for(unsigned int j = 0; j < 32; j++){
            delete(events[i][j]);
        }
    }
}

namespace Elements {

}
