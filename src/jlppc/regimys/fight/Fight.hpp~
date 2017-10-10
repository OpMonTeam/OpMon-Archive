#ifndef FIGHT_INCLUDED
#define FIGHT_INCLUDED


#include <iostream>
#include "../objects/OpMon.hpp"
#include "../objects/Attack.hpp"
#include <vector>


class Fight{
private:
  Equipe *teamVS;

  int oldStats[2][5];
  Type oldTypes[2][2];
  int oldEspece[2];
  Attaque oldAttacks[2][4];

  void pokeFight();

  void fightLoop();
  
public:

  Fight(Equipe *teamVS);

  void startFight();
  
};


#endif //FIGHT_INCLUDED
