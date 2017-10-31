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
#include "../objects/Species.hpp"
#include "../playercore/OpTeam.hpp"
#include "../enums/Enums.hpp"

//->Enum
namespace FightSignals{
  const int DO_NOTHING = 0;
}

class Fight{
private:
  OpTeam *teamVS;

  int oldStats[2][5];
  Type oldTypes[2][2];
  const Species* oldSpecies[2];
  std::vector<Attack*> oldAttacks[2];

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

  Fight(OpTeam *teamVS);

  void startFight();

};


#endif //FIGHT_INCLUDED
