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
      }else{
	
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

      View::newTurn(atkTurn);
      View::newTurn(defTurn);

      atkTurn->opmon = atk;
      defTurn->opmon = def;
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
	    if(canAttack(atk, atkTurn)){
	      atkTurn->attackUsed->attack(*atk, *def);
	    }
	  }
	  if(!defDone){
	    if(canAttack(def, defTurn)){
	      defTurn->attackUsed->attack(*def, *atk);
	    }
	  }
	}else{
	  if(!defDone){
	    if(canAttack(def, defTurn)){
	      defTurn->attackUsed->attack(*def, *atk);
	    }
	  }
	  if(!atkDone){
	    if(canAttack(atk, atkTurn)){
	      atkTurn->attackUsed->attack(*atk, *def);
	    }
	  }
	}
      }
      
      
      
      return false;
    }

    //TODO : add messages to opTurn->toPrintBefore
    bool BattleCtrl::canAttack(Model::OpMon* opmon, View::Turn* opTurn){
      bool canAttack = true;
      if(opmon->getStatus() == Model::Status::FROZEN){
	if(Utils::rand(5) == 2){
	  opTurn->toPrintBefore.push_back(OpString("battle.status.frozen.out", {opmon->getNickname()}));
	  opmon->setStatus(Model::Status::NOTHING);
	}else{
	  opTurn->toPrintBefore.push_back(OpString("battle.status.frozen.attack", {opmon->getNickname()}));
	  canAttack = false;
	}
      }else if(opmon->getStatus() == Model::Status::SLEEP){
	if(opmon->getSleepingCD() <= 0){
	  opTurn->toPrintBefore.push_back(OpString("battle.status.sleep.out", {opmon->getNickname()}));
	  opmon->setStatus(Status::NOTHING);
	}else{
	  opTurn->toPrintBefore.push_back(OpString("battle.status.sleep.attack", {opmon->getNickname()}));
	  canAttack = false;
	  opmon->passCD(true);
	}
      }else if(opmon->getStatus() == Model::Status::PARALYSED){
	if(Utils::rand(4) == 2){
	  opTurn->toPrintBefore.push_back(OpString("battle.status.paralysed.attack.fail", {opmon->getNickname()}));
	  canAttack = false;
	}else{
	  opTurn->toPrintBefore.push_back(OpString("battle.status.paralysed.attack.success.1", std::vector<sf::String>()));
	  opTurn->toPrintBefore.push_back(OpString("battle.status.paralysed.attack.success.2", {opmon->getNickname()}));
	}
      }
      if(opmon->confused){
	if(opmon->getConfusedCD() <= 0){
	  opmon->confused = false;
	  opTurn->toPrintBefore.push_back(OpString("battle.status.confused.out", {opmon->getNickname()}));
	}else{
	  opmon->passCD(false);
	  if(Utils::rand(2) == 1){
	    opTurn->toPrintBefore.push_back(OpString("battle.status.confused.attack.fail", {opmon->getNickname()}));
	    opmon->attacked(opmon->getStatPV() / 8);
	    opTurn->confusedHurt = true;
	  }else{
	    opTurn->toPrintBefore.push_back(OpString("battle.status.confused.attack.success.1", {opmon->getNickname()}));
	    opTurn->toPrintBefore.push_back(OpString("battle.status.confused.attack.success.2", std::vector<sf::String>()));
	  }
	}
      }
      if(opmon->afraid){
	opTurn->toPrintBefore.push_back(OpString("battle.status.afraid", {opmon->getNickname()}));
	opmon->afraid = false;
	canAttack = false;
      }
      return canAttack;
    }
  }
}
