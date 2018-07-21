#pragma once


#include "UiData.hpp"
#include "../sysObjects/Player.hpp"
#include <map>
#include <string>
#include <vector>
#include <list>
#include <SFML/Graphics/Texture.hpp>

namespace OpMon {
  namespace Model {

    class BattleData {
    private:

      std::map<std::string, sf::Texture> backgrounds;
      sf::Texture dialog;
      sf::Texture attackDialog;
      sf::Texture cursor;
      //std::vector<sf::Texture> choices;
      std::map<std::string, std::vector<sf::Texture> > charaBattleTextures;
      std::list<sf::Texture> battlePlayerAnim;
      sf::Texture infoboxPlayer;
      sf::Texture infoboxTrainer;
      sf::Texture shadowPlayer;
      sf::Texture shadowTrainer;
      sf::Texture healthbar1;
      sf::Texture healthbar2;
      
      UiData* uidata;
      Player* player;
      
      BattleData(BattleData const&);
      
    public:
      
      Player* getPlayerPtr() { return player; }
      Player& getPlayer() { return *player; }

      UiData* getUiDataPtr() { return uidata; }
      
      BattleData(UiData* data, Player* player);

      sf::Texture& getBackground(std::string id) { return backgrounds[id]; }
      sf::Texture& getDialog() { return dialog; }
      sf::Texture& getAttackDialog() { return attackDialog; }
      sf::Texture& getCursor() { return cursor; }
      std::vector<sf::Texture>& getCharaBattleTextures(std::string id) { return charaBattleTextures[id]; }
      std::list<sf::Texture>::iterator getBattlePlayerAnimBegin() { return battlePlayerAnim.begin(); }
      sf::Texture& getInfoboxPlayer() { return infoboxPlayer; }
      sf::Texture& getInfoboxTrainer() { return infoboxTrainer; }
      sf::Texture& getShadowPlayer() { return shadowPlayer; }
      sf::Texture& getShadowTrainer() { return shadowTrainer; }
      sf::Texture& getHealthbar1() { return healthbar1; }
      sf::Texture& getHealthbar2() { return healthbar2; }
      
    };
    
  }
}
