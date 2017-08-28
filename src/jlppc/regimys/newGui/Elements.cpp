#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include "MainFrame.hpp"
#include "../save/InternalFiles.hpp"
#include "Overworld.hpp"
#include "Events.hpp"

UNS

Map::Map(sf::Texture const& layer1, sf::Texture const& layer2, sf::Texture const& layer3, int w, int h, char** collision, sf::Music *bg, std::vector<std::vector<sf::Texture> > const& animatedElements, std::vector<sf::Vector2f> const& elementsPos) {
    this->layer1 = new sf::Texture(layer1);
    this->layer2 = new sf::Texture(layer2);
    this->layer3 = new sf::Texture(layer3);
    this->bg = bg;
    if(!bg->getLoop()) {
        bg->setLoop(true);
    }
    this->animatedElements = animatedElements;
    this->elementsPos = elementsPos;

    if(animatedElements.size() != elementsPos.size()) {
            handleError("Error: Map() - elementsPos size is not equal to animatedElements.", true);
        }

    for(unsigned int i = 0; i < animatedElements.size(); i++) {
            elementsCount.push_back(0);
            elementsSprites.push_back(sf::Sprite());
            elementsSprites[i].setTexture(animatedElements[i][0]);
            elementsSprites[i].setPosition(elementsPos[i]);
    }
    this->w = w;
    this->h = h;
    
    //Définition de la table de la collision
    this->passArr = (char **)malloc(h * sizeof(char *));
    for(int i = 0; i < h; i++) {
            this->passArr[i] = (char *)malloc(w * sizeof(char));
    }
    for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                     passArr[i][j] = collision[i][j];
	    }
    }
}

Map::~Map() {
    for(int i = 0; i < h; i++) {
            free(passArr[i]);
        }
    free(passArr);
    delete(layer1);
    delete(layer2);
    delete(layer3);
    for(Event *event : events) {
            delete(event);
        }
}

std::vector<Event *> Map::getEvent(sf::Vector2i position) {
    std::vector<Event *> toReturn;
    for(Event *event : events) {
            if(event->getPosition().x CASES  == position.x && event->getPosition().y CASES == position.y) {
                    toReturn.push_back(event);
                }
        }
    return toReturn;
}

void Map::updateEvents(Player &player) {
    for(Event *event : events) {
            event->update(player);
            MainFrame::frame.draw(*(event->getSprite()));
        }
}

void Map::updateElements(sf::RenderTexture &frame) {
    for(unsigned int i = 0; i < animatedElements.size(); i++) {
            elementsCount[i]++;
            if(elementsCount[i] >= (int) animatedElements[i].size()) {
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
