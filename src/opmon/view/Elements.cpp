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

		Transformation::Transformation(sf::Sprite* sprite, unsigned int const& time)
		: time(time)
		, sprite(sprite){
			if(sprite != nullptr){
				attach(sprite, true);
			}
		}

		Transformation::~Transformation(){

		}

		Movement::Movement(FormulaMode modeX, FormulaMode modeY, std::vector<double> xformula, std::vector<double> yformula, int const& time, bool const& relative, sf::Sprite* sprite)
		: Transformation(sprite, time)
		, modeX(modeX)
		, modeY(modeY)
		, xformula(xformula)
		, yformula(yformula)
		, relative(relative){
		}

		Movement::~Movement(){

		}

		Rotation::Rotation(FormulaMode formulaMode, std::vector<double> formula, sf::Vector2f origin, int const& time, sf::Sprite *sprite)
		  : Transformation(sprite, time)
		  , formulaMode(formulaMode)
		  , formula(formula)
		  , origin(origin){

		}

		Rotation::~Rotation(){}


		sf::Sprite* Transformation::attach(sf::Sprite* sprite, bool replace){
			if(this->sprite != nullptr && !replace){
				return nullptr;
			}
			t = 0;
			sf::Sprite* oldSprite = detach();
			this->sprite = sprite;
			return oldSprite;
		}

		sf::Sprite* Transformation::detach(){
			sf::Sprite* toReturn = sprite;
			sprite = nullptr;
			return toReturn;
		}

		double Transformation::calcFormula(std::vector<double> formula, FormulaMode mode, int t){
		  double toReturn = 0.0;
		  switch(mode){
		  case FormulaMode::POLYNOMIAL:
		    for(unsigned int i = 0; i < formula.size(); i++){
			    toReturn += formula[i] * pow((double)t, (double)i);
		    }
		    break;
		  case FormulaMode::MULTIFUNCTIONS:
		    unsigned int i = 0;
		    while(i < formula.size()){//Warning : if an incorrect function is put here, with an incorrect size, it will very likely cause a segmentation fault and the game will crash.
		     switch((int)round(formula[i])){
		     case 0://*1 function : {0, a} -> a
			toReturn += formula[i + 1];
			i += 2;
		       break;
		     case 1://Sinus function : {1, a, b, c} -> a·sin(b·t + c)
			toReturn += (formula[i + 1] * std::sin(formula[i + 2] * (double)t + formula[i + 3]));
			i += 4;
		       break;
		     case 2://Cosinus function : {2, a, b, c} -> a·cos(b·t + c)
		       toReturn += (formula[i + 1] * std::cos(formula[i + 2] * (double)t + formula[i + 3]));
		       i += 4;
		       break;
		     case 3://Absolute value function : {3, a, b, c} -> a·|b·t + c|
		       toReturn += (formula[i + 1] * std::abs(formula[i + 2] * (double)t + formula[i + 3]));
		       i += 4;
		       break;
		     case 4://Power function : {4, a, b, c} -> a·(t + b)^c
		       toReturn += (formula[i + 1] * std::pow((double)t + formula[i + 2], formula[i + 3]));
		       t += 4;
		       break;
		     }
		    }
		    break;
		  }

		  return toReturn;
		}

		sf::Sprite* Movement::attach(sf::Sprite *sprite, bool replace){
		  sf::Sprite *oldSprite = Transformation::attach(sprite, replace);
		  basePos = sprite->getPosition();
		  return oldSprite;
		}

		sf::Sprite* Movement::detach(){
		  sf::Sprite* oldSprite = Transformation::detach();
		  basePos = sf::Vector2f(0, 0);
		  return oldSprite;
		}

		bool Transformation::empty(){
			return sprite == nullptr;
		}

		bool Movement::apply(){
			if(empty() || (t > time && time != 0) ){
				return false;
			}
			sprite->setPosition( (relative ? basePos.x : 0.0) + calcFormula(xformula, modeX, t),
					(relative ? basePos.y : 0.0) + calcFormula(yformula, modeY, t));
			t++;
			return true;
		}

		Movement* Movement::mirror(Movement const& movement){

			std::vector<double> xformula = movement.xformula;
			std::vector<double> yformula = movement.yformula;
			switch(movement.modeX){
			case FormulaMode::POLYNOMIAL:
				for(unsigned int i = 0; i < xformula.size(); i++){
					xformula[i] = 0.0 - xformula[i];
				}
				break;

			case FormulaMode::MULTIFUNCTIONS:
				for(unsigned int i = 0; i < xformula.size(); i++){
					if(i % 5 != 0){
						xformula[i] = 0.0 - xformula[i];
					}
				}
				break;
			}

			switch(movement.modeY){
			case FormulaMode::POLYNOMIAL:
				for(unsigned int i = 0; i < yformula.size(); i++){
					yformula[i] = 0.0 - yformula[i];
				}
				break;

			case FormulaMode::MULTIFUNCTIONS:
				for(unsigned int i = 0; i < yformula.size(); i++){
					if(i % 5 != 0){
						yformula[i] = 0.0 - yformula[i];
					}
				}
				break;
			}

			return new Movement(movement.modeX, movement.modeY, xformula, yformula, movement.time, movement.relative, movement.sprite);

		}

		bool Rotation::apply(){
		  if(empty() || (t > time && time != 0) ){
			  return false;
		  }
		  //std::cout << "Origin1 : " << sprite->getOrigin().x << " ; " << sprite->getOrigin().y << std::endl;
		  baseOrigin = sprite->getOrigin();
		  sprite->setOrigin(sprite->getPosition());
		  //sprite->setOrigin(origin);
		  //std::cout << "Origin2 : " << sprite->getOrigin().x << " ; " << sprite->getOrigin().y << std::endl;
		  sprite->setRotation(calcFormula(formula, formulaMode, t));
		  //sprite->setOrigin(baseOrigin);
		  //std::cout << "Origin3 : " << sprite->getOrigin().x << " ; " << sprite->getOrigin().y << std::endl;
		  t++;
		  return true;
		}

		sf::Vector2f Rotation::spriteCenter(const sf::Sprite &spr){
		  return sf::Vector2f(spr.getTextureRect().width / 2, spr.getTextureRect().height / 2);
		}

	} // namespace View
} // namespace OpMon
