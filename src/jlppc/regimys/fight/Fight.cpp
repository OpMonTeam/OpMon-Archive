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
  oldStats[0][0] = op1->getStatATK();
  oldStats[0][1] = op1->getStatDEF();
  oldStats[0][2] = op1->getStatATKSPE();
  oldStats[0][3] = op1->getStatDEFSPE();
  oldStats[0][4] = op1->getStatSPE();

  oldStats[1][0] = op2->getStatATK();
  oldStats[1][1] = op2->getStatDEF();
  oldStats[1][2] = op2->getStatATKSPE();
  oldStats[1][3] = op2->getStatDEFSPE();
  oldStats[1][4] = op2->getStatSPE();

  oldTypes[0][0] = op1->getType1();
  oldTypes[0][1] = op1->getType2();
  oldTypes[1][0] = op2->getType1();
  oldTypes[1][1] = op2->getType2();
  oldSpecies[0] = op1->getSpecies();
  oldSpecies[1] = op2->getSpecies();

  oldAttacks[0] = op1->getAttacks();
  oldAttacks[1] = op2->getAttacks();

  op1->setStat("eva", 100);
  op1->setStat("acc", 100);
  op2->setStat("eva", 100);
  op2->setStat("acc", 100);

  bool sameAtk = false;
  bool sameDef = false;

  bool atkCanAttack = true;
  bool defCanAttack = true;

  bool endOfMatch = false;
  
  while(!endOfMatch){
    //Choose atk
  }
  
  
}

void Fight::opFight(){
  
}
