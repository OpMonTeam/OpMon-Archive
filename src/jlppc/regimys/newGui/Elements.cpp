#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include "MainFrame.hpp"
#include "../save/InternalFiles.hpp"

UNS

Plan::Plan(sf::Texture couche1, sf::Texture couche2, sf::Texture couche3, int w, int h, std::string filename, sf::Music* fond) {
    this->couche1 = new sf::Texture(couche1);
    this->couche2 = new sf::Texture(couche2);
    this->couche3 = new sf::Texture(couche3);
    this->fond = fond;

    this->w = w;
    this->h = h;
    //Définition de la table de la collision
    this->passTab = (int**)malloc(h * sizeof(int*));
    for(int i = 0; i < h; i++) {
        this->passTab[i] = (int*)malloc(w * sizeof(int));
    }
    istringstream *inTemp = InternalFiles::openFileIn(filename);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            (*inTemp) >> passTab[i][j];
            cout << passTab[i][j];
        }
        cout << endl;
    }

}

Plan::~Plan() {
    free(passTab);
    delete(couche1);
    delete(couche2);
    delete(couche3);
    delete(fond);
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
/*
int J_RenderCopy(SDL_Renderer *renderer, J_Texture *texture) {
    return SDL_RenderCopy(renderer, texture->texture, NULL, &(texture->rect));
}*/
