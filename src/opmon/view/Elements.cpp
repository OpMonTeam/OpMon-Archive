/*
Elements.cpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Elements.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include <cmath>

namespace OpMon {
    namespace View {

        sf::Texture MapLayer::tileset;

        MapLayer::MapLayer(sf::Vector2i size, const int tilesCodes[]) {
            if(tileset.getSize() == sf::Vector2u(0, 0)) {
                Model::ResourceLoader::load(tileset, "tileset/tileset.png");
            }
            tiles.setPrimitiveType(sf::Quads);
            tiles.resize(size.x * size.y * 4);

            for(int i = 0; i < size.y; i++) {
                for(int j = 0; j < size.x; j++) {

                    //The software we use (Tiled map editor) starts the first tile at 1, and leaves 0 for void. This line substracts one to every square.

                    int tileNumber = tilesCodes[(i * size.x) + j] - 1;

                    //Now that every void (0) became -1, this replaces every -1 by the "official" void tile.
                    if(tileNumber == -1) {
                        tileNumber = 257; //official void tile
                    }

                    int tx = tileNumber % (tileset.getSize().x / 32);
                    int ty = tileNumber / (tileset.getSize().x / 32);

                    sf::Vertex *quad = &tiles[((i * size.x) + j) * 4];

                    quad[0].position = sf::Vector2f(j * 32, i * 32);
                    quad[1].position = sf::Vector2f((j + 1) * 32, i * 32);
                    quad[2].position = sf::Vector2f((j + 1) * 32, (i + 1) * 32);
                    quad[3].position = sf::Vector2f(j * 32, (i + 1) * 32);

                    quad[0].texCoords = sf::Vector2f(tx * 32, ty * 32);
                    quad[1].texCoords = sf::Vector2f((tx + 1) * 32, ty * 32);
                    quad[2].texCoords = sf::Vector2f((tx + 1) * 32, (ty + 1) * 32);
                    quad[3].texCoords = sf::Vector2f(tx * 32, (ty + 1) * 32);
                }
            }
        }

        void MapLayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();

            states.texture = &tileset;

            target.draw(tiles, states);
        }

	Movement::Movement(std::vector<int> const& xformula, std::vector<int> const& yformula, int const& time, bool const& relative, sf::Sprite* sprite)
	    : xformula(xformula)
	    , yformula(yformula)
	    , time(time)
	    , relative(relative)
	    , sprite(sprite){
	    
	}

	sf::Sprite* Movement::attach(sf::Sprite* sprite, bool replace){
	    if(this->sprite != nullptr && !replace){
		return nullptr;
	    }
	    t = 0;
	    sf::Sprite* oldSprite = sprite;
	    this->sprite = sprite;
	    return oldSprite;
	}

	sf::Sprite* Movement::detach(){
	    sf::Sprite* toReturn = sprite;
	    sprite = nullptr;
	    return toReturn;
	}

	bool Movement::empty(){
	    return sprite == nullptr;
	}

	bool Movement::apply(){
	    if(empty() || (t > time && time != 0) ){
		return false;
	    }
	    
	    int coordX = 0;
	    for(unsigned int i = 0; i < xformula.size(); i++){
		coordX += xformula[i] * pow(t, i);
	    }
	    int coordY = 0;
	    for(unsigned int i = 0; i < yformula.size(); i++){
		coordY += yformula[i] * pow(t, i);
	    }

	    sprite->setPosition( (relative ? sprite->getPosition().x : 0) + coordX,
				(relative ? sprite->getPosition().y : 0) + coordY);
	    t++;
	    return true;
	}

    } // namespace View
} // namespace OpMon
