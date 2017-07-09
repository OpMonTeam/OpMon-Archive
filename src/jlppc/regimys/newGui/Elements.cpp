#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include "MainFrame.hpp"
#include "../save/InternalFiles.hpp"
#include "Overworld.hpp"
#include "Events.hpp"

UNS

Map::Map(sf::Texture layer1, sf::Texture layer2, sf::Texture layer3, int w, int h, std::string filename, sf::Music* fond) {
    this->layer1 = new sf::Texture(layer1);
    this->layer2 = new sf::Texture(layer2);
    this->layer3 = new sf::Texture(layer3);
    this->fond = fond;
    if(!fond->getLoop()){
        fond->setLoop(true);
    }
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
        }
    }
    delete(inTemp);

}

Map::~Map() {
    for(int i = 0; i < h; i++){
        free(passTab[i]);
    }
    free(passTab);
    delete(layer1);
    delete(layer2);
    delete(layer3);
    for(Event* event : events){
        delete(event);
    }
}

std::vector<Event*> Map::getEvent(sf::Vector2i position){
        std::vector<Event*> toReturn;
        FOR_EACH(Event*, events, events.size(), {)
            if((*objActuel)->getPosition().x CASES  == position.x && (*objActuel)->getPosition().y CASES == position.y){
                toReturn.push_back(*objActuel);
            }
        }
        return toReturn;
}

void Map::updateEvents(Player &player){
    for(Event* event : events){
        event->update(player);
        MainFrame::frame.draw(*(event->getSprite()));
    }
}


/*Map::~Map(){
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
