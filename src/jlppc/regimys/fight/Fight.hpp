/**
Fight.hpp
Author : Jlppc
**/
#ifndef FIGHT_INCLUDED
#define FIGHT_INCLUDED


#include <iostream>
#include "../objects/OpMon.hpp"
#include "../objects/Attack.hpp"
#include <vector>

//->Enum
namespace FightSignals{
  const int DO_NOTHING = 0;
}

class Fight{
private:
  Equipe *teamVS;

  int oldStats[2][5];
  Type oldTypes[2][2];
  Espece* oldSpecies[2];
  Attaque oldAttacks[2][4];

  OpMon *op1 = nullptr;
  OpMon *op2 = nullptr;

  int actionToDo = 0;
  
  int playerOpId = 0, npcId = 0;
  /**
     Fight between two OpMons
  */
  void opFight();
  /**
     Graphic part of the fight
  */
  void fightLoop();
  
public:

  Fight(Equipe *teamVS);

  void startFight();
  
};


#endif //FIGHT_INCLUDED
