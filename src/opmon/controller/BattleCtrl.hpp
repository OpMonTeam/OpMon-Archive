#pragma once

#include "../model/objects/OpMon.hpp"
#include "../view/Battle.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "AGameScreen.hpp"
#include <vector>
#include "../model/objects/Enums.hpp"
#include "../model/objects/Attack.hpp"
#include "../model/objects/Species.hpp"

namespace OpMon{
  namespace Controller{

    class BattleCtrl : public AGameScreen {
    private:
      /*The player's current OpMon*/
      Model::OpMon* atk;
      /*The opposite trainer's current OpMon*/
      Model::OpMon* def;

      Model::OpTeam* playerTeam;
      Model::OpTeam* trainerTeam;
      
      View::Battle view;

      View::Turn* atkTurn;
      View::Turn* defTurn;

      int oldStats[2][5];
      Model::Type oldTypes[2][2];
      const Model::Species* oldSpecies[2];
      std::vector<Model::Attack *> oldAttacks[2];
      
      int trainerOpCount = 0;

      bool turnActivated = false;
      
      /** Counters and triggers for the fight*/
      bool sameAtk = false;
      bool sameDef = false;
      bool atkCanAttack = true;
      bool defCanAttack = true;
      int atkSleepCD = 0;
      bool atkSleep = false;
      int defSleepCD = 0;
      bool defSleep = false;
      int atkConfusedCD = 0;
      bool atkConfued = false;
      int defConfusedCD = 0;
      bool defConfused;
      int atkAttack = 0;
      int defAttack = 0;
      bool captured = false;
      

      bool turn();
      void initBattle(int opId, int opId2);
      View::Turn* turnIA(int level);

      bool canAttack(Model::OpMon* opmon, View::Turn* opTurn);
      
    public:
      BattleCtrl(Model::OpTeam* one, Model::OpTeam *two);
      GameStatus checkEvent(sf::Event const &) override;
      GameStatus update() override;
    };

  }
}
