#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include "MainFrame.hpp"

UNS

Plan::Plan(sf::Texture couche1, sf::Texture couche2, sf::Texture couche3, int w, int h, std::string filename, std::string fondPath) {
    this->couche1 = new sf::Sprite();
    this->couche2 = new sf::Sprite();
    this->couche3 = new sf::Sprite();
    this->fond = new sf::Music();
    this->couche1->setTexture(couche1);
    this->couche2->setTexture(couche2);
    //this->events = events;
    this->couche3->setTexture(couche3);
    this->fond->openFromFile(fondPath);
    this->musicPath = fondPath;

    this->w = w;
    this->h = h;
    //Définition de la table de la collision
    this->passTab = (int**)malloc(h * sizeof(int*));
    for(int i = 0; i < h; i++) {
        this->passTab[i] = (int*)malloc(w * sizeof(int));
    }
    ifstream inTemp(filename.c_str());
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            inTemp >> passTab[i][j];
        }
    }
    //Suppression du fichier temporaire
    inTemp.close();
#ifdef _WIN32
    system((string("DEL ") + filename).c_str());
#else
    system((string("rm ") + filename).c_str());
#endif // _WIN32

}

Plan::~Plan() {
    free(passTab);
    delete(couche1);
    delete(couche2);
    delete(couche3);
    delete(fond);
}

void Plan::setPos(sf::Vector2f const& vect){
    couche1->setPosition(vect);
    couche2->setPosition(vect);
    couche3->setPosition(vect);
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
