#pragma once

#include "../model/objects/OpMon.hpp"
#include "../model/objects/Attack.hpp"
#include "../model/objects/item/Item.hpp"
#include "../start/Core.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace OpMon{
  namespace View{
    
    enum class TurnType {
      ATTACK, ITEM, RUN, CHANGE
    };

    /* Stay in Battle or go to BattleCtrl? */
    class Turn{
    public:
      const Model::OpMon* opmon;
      const Model::Attack* attackUsed;
      const Model::Item* itemUsed;
      const TurnType type;
      const bool runSuccessful;
      const Model::OpMon* newOpmon;
      const int hpLost;

      Turn(Model::OpMon* opmon, Model::Attack* attackUsed, int hpLost);
      Turn(Model::OpMon* opmon, Model::Item* itemUsed);
      Turn(Model::OpMon* opmon, bool runSuccessful);
      Turn(Model::OpMon* opmon, Model::OpMon* newOpmon);
      
      
    };
    
    class Battle {
    private:
      sf::Sprite atk;
      sf::Sprite def;
    public:
      GameStatus operator()(Turn atk, Turn def);
    };

  }
}
