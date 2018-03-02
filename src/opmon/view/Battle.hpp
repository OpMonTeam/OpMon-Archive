#pragma once

#include "../model/objects/OpMon.hpp"
#include "../model/objects/Attack.hpp"
#include "../model/objects/item/Item.hpp"
#include "../start/Core.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
#include <map>

namespace OpMon{
  namespace View{
    
    enum class TurnType {
      ATTACK, ITEM, RUN, CHANGE
    };

    /* Stay in Battle or go to BattleCtrl? */
    struct Turn{
      Model::OpMon* opmon;
      Model::Attack* attackUsed;
      Model::Item* itemUsed;
      TurnType type;
      bool runSuccessful;
      Model::OpMon* newOpmon;
      int hpLost;
      std::vector<sf::String> toPrintBefore;
      std::vector<sf::String> toPrintAfter;
      std::map<Model::Stats, int> increasedStats;
    };

    void newTurn(Turn* toNew);
    
    typedef struct Turn Turn;
    
    class Battle {
    private:
      sf::Sprite atk;
      sf::Sprite def;

      bool turnLaunched = false;
    public:
      GameStatus operator()(Turn atk, Turn def);//Sets turnLaunched to true
      GameStatus operator()(Turn* atkTurn);
    };

  }
}
