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

	Movement::Movement(MovementMode modeX, MovementMode modeY, std::vector<double> xformula, std::vector<double> yformula, int const& time, bool const& relative, sf::Sprite* sprite)
	    : modeX(modeX)
	    , modeY(modeY)
	    , xformula(xformula)
	    , yformula(yformula)
	    , time(time)
	    , relative(relative)
	    , sprite(nullptr){
		if(sprite != nullptr){
			attach(sprite, true);
		}
	}

	Movement::~Movement(){
	    
	}
	
	
	sf::Sprite* Movement::attach(sf::Sprite* sprite, bool replace){
	    if(this->sprite != nullptr && !replace){
	    	return nullptr;
	    }
	    t = 0;
	    sf::Sprite* oldSprite = sprite;
	    this->sprite = sprite;
	    basePos = this->sprite->getPosition();
	    return oldSprite;
	}

	sf::Sprite* Movement::detach(){
	    sf::Sprite* toReturn = sprite;
	    sprite = nullptr;
	    basePos = sf::Vector2f(0, 0);
	    return toReturn;
	}

	bool Movement::empty(){
	    return sprite == nullptr;
	}

	bool Movement::apply(){
	    if(empty() || (t > time && time != 0) ){
		return false;
	    }

	    double coordX = 0.0;
	    double coordY = 0.0;

	    switch(modeX){
	    case MovementMode::POLYNOMIAL:
		for(unsigned int i = 0; i < xformula.size(); i++){
		    coordX += xformula[i] * pow((double)t, (double)i);
		}
		break;

	    case MovementMode::SINUSOIDAL:
		if(xformula.size() % 5 != 0){
		    handleError("Incorrect sinusoidal formula in Movement (xforumla)");
		    return false;
		}
		for(unsigned int i = 0; i < xformula.size(); i+=5){
		    coordX == xformula[i + 1] * round((xformula[i] == 0.0) ? sin(xformula[i + 2] * (double)t + xformula[i + 3]) : sin(xformula[i + 2] * t + xformula[i + 3])) + xformula[i + 4];
		}
		break;
	    }

	    switch(modeY){
	    case MovementMode::POLYNOMIAL:
		for(unsigned int i = 0; i < yformula.size(); i++){
		    coordY += yformula[i] * pow((double)t, (double)i);
		}
		break;

	    case MovementMode::SINUSOIDAL:
		if(yformula.size() % 5 != 0){
		    handleError("Incorrect sinusoidal formula in Movement (yforumla)");
		    return false;
		}

		for(unsigned int i = 0; i < yformula.size(); i+=5){
		    coordX == yformula[i + 1] * round((yformula[i] == 0.0) ? sin(xformula[i + 2] * (double)t + yformula[i + 3]) : sin(xformula[i + 2] * t + yformula[i + 3])) + yformula[i + 4];
		}
		break;
	    }
	    sprite->setPosition( (relative ? basePos.x : 0.0) + coordX,
				(relative ? basePos.y : 0.0) + coordY);
	    t++;
	    return true;
	}

	Movement* Movement::mirror(Movement const& movement){

	    std::vector<double> xformula = movement.xformula;
	    std::vector<double> yformula = movement.yformula;
	    switch(movement.modeX){
	    case MovementMode::POLYNOMIAL:
		for(unsigned int i = 0; i < xformula.size(); i++){
		    xformula[i] = 0.0 - xformula[i];
		}
		break;
		
	    case MovementMode::SINUSOIDAL:
		for(unsigned int i = 0; i < xformula.size(); i++){
		    if(i % 5 != 0){
			xformula[i] = 0.0 - xformula[i];
		    }
		}
		break;
	    }

	    switch(movement.modeY){
	    case MovementMode::POLYNOMIAL:
		for(unsigned int i = 0; i < yformula.size(); i++){
		    yformula[i] = 0.0 - yformula[i];
		}
		break;
		
	    case MovementMode::SINUSOIDAL:
		for(unsigned int i = 0; i < yformula.size(); i++){
		    if(i % 5 != 0){
			yformula[i] = 0.0 - yformula[i];
		    }
		}
		break;
	    }

	    return new Movement(movement.modeX, movement.modeY, xformula, yformula, movement.time, movement.relative, movement.sprite);
	    
	}

    } // namespace View
} // namespace OpMon
