#pragma once

#include "UiData.hpp"
#include "../sysObjects/Player.hpp"
#include "../sysObjects/Map.hpp"
#include <map>
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace OpMon {
  namespace Model {

    class OverworldData {
    private:

      std::map<std::string, Map*> maps;
      
      sf::Texture texturePP[4];
      sf::Texture walkingPP[4];
      sf::Texture walkingPP2[4];
            
      UiData* uidata;

      Player* player;

      std::map<std::string, sf::Vector2f> elementsPos;
      std::map<std::string, unsigned int> elementsCounter;
      std::map<std::string, std::vector<sf::Texture>> elementsTextures;

      std::map<std::string, std::vector<sf::Texture>> charaTextures;

      std::map<std::string, std::vector<sf::Texture> > doorsTextures;
      
      OverworldData(OverworldData const&);
      
    public:

      void incrementElementCounter(std::string const& elementId) { elementsCounter[elementId]++; }
      void resetElementCounter(std::string const& id) { elementsCounter[id] = 0; }
      unsigned int getElementCounter(std::string const& id) { return elementsCounter[id]; }
      std::vector<sf::Texture>& getElementTextures(std::string const& id) { return elementsTextures[id]; }
      sf::Vector2f& getElementPos(std::string const& id) { return elementsPos[id]; }
      sf::Texture& getCurrentElementTexture(std::string const& id) { return elementsTextures[id][elementsCounter[id]]; }
      
      
      Map* getMap(std::string map) { return maps[map]; }
      Map* getCurrentMap() { return maps[player->getMapId()]; }
      
      sf::Texture& getTexturePP(unsigned int id) { return texturePP[((id < 4) ? id : 0)]; }
      sf::Texture& getWalkingPP(unsigned int id) { return walkingPP[((id < 4) ? id : 0)]; }
      sf::Texture& getWalkingPP2(unsigned int id) { return walkingPP2[((id < 4) ? id : 0)]; }
      
      UiData* getUiDataPtr() { return uidata; }
      Player* getPlayerPtr() { return player; }
      Player& getPlayer() { return *player; }
      
      OverworldData(UiData* uidata, Player* player);
      ~OverworldData();
      
    };
    
  }
}
