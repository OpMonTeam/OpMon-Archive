#include "Battle.hpp"

namespace OpMon{
  namespace View{

    using namespace Model;
    
    Turn::Turn(OpMon* opmon, Attack* attackUsed, int hpLost) : opmon(opmon), attackUsed(attackUsed), hpLost(hpLost), runSuccessful(false), newOpmon(nullptr), itemUsed(nullptr), type(TurnType::ATTACK) {}
    Turn::Turn(OpMon* opmon, Item* itemUsed) : opmon(opmon), attackUsed(nullptr), hpLost(0), runSuccessful(false), newOpmon(nullptr), itemUsed(itemUsed), type(TurnType::ITEM) {}
    Turn::Turn(OpMon* opmon, bool runSuccessful) : opmon(opmon), runSuccessful(runSuccessful), attackUsed(nullptr), hpLost(0), newOpmon(nullptr), itemUsed(nullptr), type(TurnType::RUN) {}
    Turn::Turn(OpMon* opmon, OpMon* newOpmon) : opmon(opmon), newOpmon(newOpmon), runSuccessful(false), attackUsed(nullptr), hpLost(0), itemUsed(nullptr), type(TurnType::CHANGE) {}

    
  }
}
