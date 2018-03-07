#pragma once

#include "../model/objects/OpMon.hpp"
#include "../model/objects/Attack.hpp"
#include "../model/objects/item/Item.hpp"

namespace OpMon{
  namespace Model{

    enum class TurnType {
      ATTACK, ITEM, RUN, CHANGE
    };   

    
     struct Turn{
      Model::OpMon* opmon;
      Model::Attack* attackUsed;
      Model::Item* itemUsed;
      TurnType type;
      bool runSuccessful;
      Model::OpMon* newOpmon;
      int hpLost;
      std::vector<Utils::OpString> toPrintBefore;
      std::vector<Utils::OpString> toPrintAfter;
      std::map<Model::Stats, int> changedStatsAtk; //If number > 6 : Stat too high. If number < -6 : Stat too low
      std::map<Model::Stats, int> changedStatsDef; //If number > 6 : Stat too high. If number < -6 : Stat too low
      bool confusedHurt;
      bool attackMissed;
      bool attackFailed;
      bool atkEnd;
      bool0 OHKO;
      int attackHurt;
    };

    typedef struct Turn Turn;
    
    void newTurn(Turn* toNew);
  }
}
