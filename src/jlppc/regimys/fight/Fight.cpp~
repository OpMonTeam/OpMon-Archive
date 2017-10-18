#include "Fight.hpp"

Fight::Fight(Equipe *teamVS){
  this->teamVS = teamVS;
}

void Fight::startFight(){
  while(!(Main::player.isKo() || teamVS->isKo())){
    op1 = Main::player.getOp(playerOpId);
    op2 = teamVS->getOp(npcId);
    pokeFight();
  }
}

void Fight::fightLoop(){
  
}

void Fight::opFight(){
  
}
