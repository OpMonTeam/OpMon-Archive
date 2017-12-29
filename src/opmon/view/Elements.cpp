#include "Elements.hpp"
#include <cstdlib>
#include "../start/main.hpp"
#include "../start/Initializer.hpp"
#include "MainFrame.hpp"
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




/*Map::~Map(){
    for(unsigned int i = 0; i < 32; i++){
        for(unsigned int j = 0; j < 32; j++){
            delete(events[i][j]);
        }
    }
}*/

namespace Elements {

}
