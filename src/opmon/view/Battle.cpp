#include "Battle.hpp"

namespace OpMon{
  namespace View{

    using namespace Model;
    
    void newTurn(Turn* toNew){
      toNew->opmon = nullptr;
      toNew->attackUsed = nullptr;
      toNew->itemUsed = nullptr;
      toNew->type = TurnType::ATTACK;
      toNew->runSuccessful = false;
      toNew->newOpmon = nullptr;
      toNew->hpLost = 0;
      toNew->toPrintBefore = std::vector<Utils::OpString>();
      toNew->toPrintAfter = std::vector<Utils::OpString>();
      toNew->increasedStats = std::map<Model::Stats, int>();
      toNew->confusedHurt = false;
    }
    
  }
}
