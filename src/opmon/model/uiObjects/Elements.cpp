#include "Elements.hpp"
#include <cstdlib>
#include "../../start/Initializer.hpp"
#include "../save/InternalFiles.hpp"
#include "Overworld.hpp"
#include "Events.hpp"

UNS

MapLayer::MapLayer(sf::Vector2i size, const int tilesCodes[]){
  sf::Texture &tileset = Initializer::tileset;
  tiles.setPrimitiveType(sf::Quads);
  tiles.resize(size.x * size.y * 4);

  for(unsigned int i = 0; i < size.y; i++){
    for(unsigned int j = 0; j < size.x; j++){
      
      int tileNumber = tilesCodes[(i * size.x) + j] - 1;

      if(tileNumber == -1){
	tileNumber = 257;//Void tile
      }
      
      int tx = tileNumber % (tileset.getSize().x / 32);
      int ty = tileNumber / (tileset.getSize().x / 32);

      sf::Vertex* quad = &tiles[((i * size.x) + j) * 4];

      quad[0].position = sf::Vector2f(j * 32, i * 32);
      quad[1].position = sf::Vector2f((j+1) * 32, i * 32);
      quad[2].position = sf::Vector2f((j+1) * 32, (i+1) * 32);
      quad[3].position = sf::Vector2f(j * 32, (i+1) * 32);

      
      quad[0].texCoords = sf::Vector2f(tx * 32, ty * 32);
      quad[1].texCoords = sf::Vector2f((tx+1) * 32, ty * 32);
      quad[2].texCoords = sf::Vector2f((tx+1) * 32, (ty+1) * 32);
      quad[3].texCoords = sf::Vector2f(tx * 32, (ty+1) * 32);
      
    }
  }
  
}

void MapLayer::draw(sf::RenderTarget &target, sf::RenderStates states) const{
  states.transform *= getTransform();

  states.texture = &Initializer::tileset;

  target.draw(tiles, states);
}

Map::Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, const char* const* collision, sf::Music *bg, std::vector<std::vector<sf::Texture> > const& animatedElements, std::vector<sf::Vector2f> const& elementsPos) {
  this->layer1 = new MapLayer(sf::Vector2i(w + 16, h + 16), layer1);
    this->layer2 = new MapLayer(sf::Vector2i(w + 16, h + 16), layer2);
    this->layer3 = new MapLayer(sf::Vector2i(w + 16, h + 16), layer3);
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

std::vector<Event *> Map::getEvent(sf::Vector2i position) const {
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
