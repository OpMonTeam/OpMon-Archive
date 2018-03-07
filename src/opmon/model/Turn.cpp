#include "Turn.hpp"

namespace OpMon{
  namespace Model{
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
      toNew->changedStatsAtk = std::map<Model::Stats, int>();
      toNew->changedStatsDef = std::map<Model::Stats, int>();
      toNew->confusedHurt = false;
      toNew->attackFailed = false;
      toNew->attackMissed = false;
      toNew->attackEnd = false;
      toNew->OHKO = false;
      toNew->attackHurt = 0;
    }

  }
}
