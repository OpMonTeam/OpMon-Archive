/*
  OverworldData.hpp
  Author : Cyriel
  File under GNU GPL v3.0 license
*/
#pragma once

#include "../sysObjects/Map.hpp"
#include "../sysObjects/Player.hpp"
#include "UiData.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <string>
#include <vector>

namespace OpMon {
    namespace Model {

        class OverworldData {
          private:
            sf::Texture alpha = sf::Texture();
            std::vector<sf::Texture> alphaTab = std::vector<sf::Texture>(1);

	    std::map<std::string, OpTeam*> trainers;
	    
            std::map<std::string, Map *> maps;
            std::map<std::string, Map *>::iterator mapsItor;

            sf::Texture texturePP;
            sf::IntRect texturePPRect[4];
            sf::IntRect walkingPPRect[4];
            sf::IntRect walkingPP2Rect[4];

            UiData *uidata;

            Player *player;

            std::map<std::string, sf::Vector2f> elementsPos;
            std::map<std::string, unsigned int> elementsCounter;
            std::map<std::string, std::vector<sf::Texture>> elementsTextures;

            std::map<std::string, std::vector<sf::Texture>> charaTextures;

	    std::map<std::string, std::vector<sf::Texture>> eventsTextures;

            std::map<std::string, std::vector<sf::Texture>> doorsTextures;

	  std::map<std::string, std::unique_ptr<Item> > itemsList;
	  
            OverworldData(OverworldData const &);

          public:
            void incrementElementCounter(std::string const &elementId) { elementsCounter[elementId]++; }
            void resetElementCounter(std::string const &id) { elementsCounter[id] = 0; }
            unsigned int getElementCounter(std::string const &id) { return elementsCounter[id]; }
            std::vector<sf::Texture> &getElementTextures(std::string const &id) { return elementsTextures[id]; }
            sf::Vector2f &getElementPos(std::string const &id) { return elementsPos[id]; }
            sf::Texture &getCurrentElementTexture(std::string const &id) { return elementsTextures[id][elementsCounter[id]]; }

            Map *getMap(std::string map) { return maps[map]; }
            Map *getCurrentMap() { return maps[player->getMapId()]; }
            std::string getCurrentItorMap() { return mapsItor->first; }
            void incrementItorMap() {
                mapsItor++;
                if(mapsItor == maps.end())
                    mapsItor = maps.begin();
            }
            void decrementItorMap() {
                if(mapsItor != maps.begin())
                    mapsItor--;
                else {
                    mapsItor = maps.end();
                    --mapsItor;
                }
            }

            sf::Texture &getTexturePP() { return texturePP; }
            sf::IntRect &getTexturePPRect(unsigned int id) { return texturePPRect[((id < 4) ? id : 0)]; }
            sf::IntRect &getWalkingPPRect(unsigned int id) { return walkingPPRect[((id < 4) ? id : 0)]; }
            sf::IntRect &getWalkingPP2Rect(unsigned int id) { return walkingPP2Rect[((id < 4) ? id : 0)]; }

            UiData *getUiDataPtr() { return uidata; }
            Player *getPlayerPtr() { return player; }
            Player &getPlayer() { return *player; }

	  std::unique_ptr<Item>& getItem(std::string const& str) {return itemsList[str];}

            OverworldData(UiData *uidata, Player *player);
            ~OverworldData();
        };

    } // namespace Model
} // namespace OpMon
