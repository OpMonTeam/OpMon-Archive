#include "BattleCtrl.hpp"

namespace OpMon{
  namespace Controller{
    using namespace Model;
    
    BattleCtrl::BattleCtrl(OpTeam *one, OpTeam *two)
      : playerTeam(one), trainerTeam(two), atk(one->getOp(0)), def(two->getOp(0)){
      
    }

    GameStatus BattleCtrl::update() {
      if(turnActivated){
	turn();
      }
      return GameStatus::CONTINUE;//TEMP
    }

    GameStatus BattleCtrl::checkEvent(sf::Event const & event){

      //events check
      //Events stock all the turn data into atkTurn.
      
      return GameStatus::CONTINUE;
    }

    void BattleCtrl::initBattle(int opId, int opId2){
      atk = playerTeam->getOp(opId);
      def = playerTeam->getOp(opId);
      oldStats[0][0] = atk->getStatATK();
      oldStats[0][1] = atk->getStatDEF();
      oldStats[0][2] = atk->getStatATKSPE();
      oldStats[0][3] = atk->getStatDEFSPE();
      oldStats[0][4] = atk->getStatSPE();

      oldStats[1][0] = def->getStatATK();
      oldStats[1][1] = def->getStatDEF();
      oldStats[1][2] = def->getStatATKSPE();
      oldStats[1][3] = def->getStatDEFSPE();
      oldStats[1][4] = def->getStatSPE();

      oldTypes[0][0] = atk->getType1();
      oldTypes[0][1] = atk->getType2();
      oldTypes[1][0] = def->getType1();
      oldTypes[1][1] = def->getType2();

      const Model::Species& atkSpecies = atk->getSpecies();
      const Model::Species& defSpecies = def->getSpecies();
      
      oldSpecies[0] = &atkSpecies;
      oldSpecies[1] = &defSpecies;

      oldAttacks[0] = atk->getAttacks();
      oldAttacks[1] = def->getAttacks();

      atk->setStat(Model::Stats::EVA, 100);
      atk->setStat(Model::Stats::ACC, 100);
      def->setStat(Model::Stats::EVA, 100);
      def->setStat(Model::Stats::ACC, 100);
    }

    View::Turn* BattleCtrl::turnIA(int level){
      
    }
    
    bool BattleCtrl::turn(){
      bool atkDone = false;
      bool defDone = false;

      bool atkFirst = true;
      if(atkTurn->type != View::TurnType::ATTACK){
	//Actions
	atkDone = true;
      }
      if(defTurn->type != View::TurnType::ATTACK){
	//Actions
	defDone = true;
      }
      if(defTurn->type == View::TurnType::ATTACK && atkTurn->type == View::TurnType::ATTACK){
	atkFirst = ((atk->getStatSPE() > def->getStatSPE()) || (atkTurn->attackUsed->getPriority() > defTurn->attackUsed->getPriority()));
      }else{
	atkFirst = !atkDone;
      }
      
      if(!atkDone || !defDone){
	if(atkFirst){
	  if(!atkDone){
	    atkTurnFunc();
	  }
	  if(!defDone){
	    defTurnFunc();
	  }
	}else{
	  if(!defDone){
	    defTurnFunc();
	}
	  if(!atkDone){
	    atkTurnFunc();
	  }
	}
      }
      
      
      
      return false;
      //Modify atkTurn and defTurn, and calculate the turn of each opmon
    }

    void BattleCtrl::atkTurnFunc(){
      
    }

    void BattleCtrl::defTurnFunc(){
      
    }
  }
}
