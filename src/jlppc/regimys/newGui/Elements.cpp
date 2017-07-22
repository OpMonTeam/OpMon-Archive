#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include "MainFrame.hpp"
#include "../save/InternalFiles.hpp"
#include "Overworld.hpp"
#include "Events.hpp"

UNS

Map::Map(sf::Texture layer1, sf::Texture layer2, sf::Texture layer3, int w, int h, std::string filename, sf::Music* fond, std::vector<std::vector<sf::Texture> > animatedElements, std::vector<sf::Vector2f> elementsPos) {
    this->layer1 = new sf::Texture(layer1);
    this->layer2 = new sf::Texture(layer2);
    this->layer3 = new sf::Texture(layer3);
    this->fond = fond;
    if(!fond->getLoop()){
        fond->setLoop(true);
    }
    this->animatedElements = animatedElements;
    this->elementsPos = elementsPos;

    if(animatedElements.size() != elementsPos.size()){
        gererErreur("Error: Map() - elementsPos size is not equal to animatedElements.", true);
    }

    for(unsigned int i = 0; i < animatedElements.size(); i++){
        elementsCount.push_back(0);
        elementsSprites.push_back(sf::Sprite());
        elementsSprites[i].setTexture(animatedElements[i][0]);
        elementsSprites[i].setPosition(elementsPos[i]);
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
        for(Event* event : events){
            if(event->getPosition().x CASES  == position.x && event->getPosition().y CASES == position.y){
                toReturn.push_back(event);
            }
        }
        FOR_EACH(Event*, events, events.size(), {)

        }
        return toReturn;
}

void Map::updateEvents(Player &player){
    for(Event* event : events){
        event->update(player);
        MainFrame::frame.draw(*(event->getSprite()));
    }
}

void Map::updateElements(sf::RenderTexture &frame){
    for(unsigned int i = 0; i < animatedElements.size(); i++){
        elementsCount[i]++;
        if(elementsCount[i] >= animatedElements[i].size()){
            elementsCount[i] = 0;
        }
        elementsSprites[i].setTexture(animatedElements[i][elementsCount[i]]);
        frame.draw(elementsSprites[i]);
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
