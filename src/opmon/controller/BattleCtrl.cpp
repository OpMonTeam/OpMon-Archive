#include "BattleCtrl.hpp"
#include "../../utils/OpString.hpp"
#include <iostream>

namespace OpMon{
  namespace Controller{
    using namespace Model;

    
    BattleCtrl::BattleCtrl(OpTeam *one, OpTeam *two)
      : playerTeam(one),
	trainerTeam(two),
	atk(one->getOp(0)),
	def(two->getOp(0)),
	view(one, two, "cyrion", "grass"){
      initBattle(0, 0);
    }

    GameStatus BattleCtrl::update() {
      GameStatus returned = view(atkTurn, defTurn, &turnActivated);
      if(turnActivated){
	if(atk->getHP() <= 0 || def->getHP() <= 0){
	  /*if(playerTeam->isKo() || trainerTeam->isKo()){
	    return GameStatus::PREVIOUS;
	    }*/
	  returned =  GameStatus::PREVIOUS;
	}
      }
      return returned;
    }

    GameStatus BattleCtrl::checkEvent(sf::Event const & event){

      switch(event.type){
      case sf::Event::KeyPressed:
	switch(event.key.code){
	case sf::Keyboard::Left:
	  view.moveCur(Model::Side::TO_LEFT);
	  break;
	case sf::Keyboard::Right:
	  view.moveCur(Model::Side::TO_RIGHT);
	  break;
	case sf::Keyboard::Up:
	  view.moveCur(Model::Side::TO_UP);
	  break;
	case sf::Keyboard::Down:
	  view.moveCur(Model::Side::TO_DOWN);
	  break;
	case sf::Keyboard::Return:
	  if(!view.isAttackChoice()){
	    switch(view.getCurPos()){
	    case 0:
	      view.toggleAttackChoice();
	      break;
	    default:
	      break;
	    }
	  }else{
	    atkTurn.attackUsed = atk->getAttacks()[view.getCurPos()];
	    atkTurn.type = Model::TurnType::ATTACK;
	    turn();
	    view.toggleAttackChoice();
	    turnActivated = true;
	  }
	  break;
	case sf::Keyboard::BackSpace:
	  if(view.isAttackChoice()){
	    view.toggleAttackChoice();
	  }
	  break;
	}
      }
      
      return GameStatus::CONTINUE;
    }

    void BattleCtrl::initBattle(int opId, int opId2){
      atk = playerTeam->getOp(opId);
      def = trainerTeam->getOp(opId2);
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
      //Clear the turns
      Model::newTurn(&atkTurn);
      Model::newTurn(&defTurn);
      //Register the opmons' addresses in the Turns
      atkTurn.opmon = atk;
      defTurn.opmon = def;
    }

    Model::Turn* BattleCtrl::turnIA(int level){
      defTurn.attackUsed = def->getAttacks()[0];
      defTurn.type = TurnType::ATTACK;
      return &defTurn;
    }
    
    bool BattleCtrl::turn(){
      bool atkDone = false;
      bool defDone = false;

      turnIA(0);
      
      bool atkFirst = true;
      if(atkTurn.type != TurnType::ATTACK){
	//Actions
	atkDone = true;
      }
      if(defTurn.type != TurnType::ATTACK){
	//Actions
	defDone = true;
      }
      //If the two of them will attack, then the priority must be calculated. Else, the only attacking OpMon will attack, obviously.
      if(defTurn.type == TurnType::ATTACK && atkTurn.type == TurnType::ATTACK){
	atkFirst = ((atk->getStatSPE() > def->getStatSPE()) || (atkTurn.attackUsed->getPriority() > defTurn.attackUsed->getPriority()));
      }else{
	atkFirst = !atkDone;
      }
      
      if(!atkDone || !defDone){
	if(atkFirst){
	  if(!atkDone){
	    if(canAttack(atk, &atkTurn)){
	      atkTurn.attackUsed->attack(*atk, *def, atkTurn);
	    }
	  }
	  if(!defDone){
	    if(canAttack(def, &defTurn)){
	      defTurn.attackUsed->attack(*def, *atk, defTurn);
	    }
	  }
	}else{
	  if(!defDone){
	    if(canAttack(def, &defTurn)){
	      defTurn.attackUsed->attack(*def, *atk, defTurn);
	    }
	  }
	  if(!atkDone){
	    if(canAttack(atk, &atkTurn)){
	      atkTurn.attackUsed->attack(*atk, *def, atkTurn);
	    }
	  }
	}
      }
      
      
      
      return false;
    }

    //TODO : add messages to opTurn->toPrintBefore
    bool BattleCtrl::canAttack(Model::OpMon* opmon, Model::Turn* opTurn){
      bool canAttack = true;
      std::vector<std::string*> opName(1);
      opName[0] = new std::string(opmon->getNickname());
      //Checks if frozen
      if(opmon->getStatus() == Model::Status::FROZEN){
	//The OpMon have one chance out of 5 to be able to move again.
	if(Utils::Misc::randU(5) == 2){
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.frozen.out", opName));
	  opmon->setStatus(Model::Status::NOTHING);
	}else{
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.frozen.attack", opName));
	  canAttack = false;
	}
	//Checks if sleeping
      }else if(opmon->getStatus() == Model::Status::SLEEPING){
	//Checks the sleep counter.
	if(opmon->getSleepingCD() <= 0){
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.sleep.out", opName));
	  opmon->setStatus(Status::NOTHING);
	}else{
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.sleep.attack", opName));
	  canAttack = false;
	  opmon->passCD(true);
	}
	//Checks if paralysed
      }else if(opmon->getStatus() == Model::Status::PARALYSED){
	//The opmon have one chance out of three to can't attack when paralysed
	if(Utils::Misc::randU(4) == 2){
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.paralysed.attack.fail", opName));
	  canAttack = false;
	}else{
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.paralysed.attack.success.1", std::vector<std::string*>()));
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.paralysed.attack.success.2", opName));
	}
      }
      //Checks if confused
      if(opmon->confused){
	//Checks the confused counter
	if(opmon->getConfusedCD() <= 0){
	  opmon->confused = false;
	  opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.confused.out", opName));
	}else{
	  opmon->passCD(false);
	  //The OpMon have one chance out of two of failing their attack.
	  if(Utils::Misc::randU(2) == 1){
	    opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.confused.attack.fail", opName));
	    opmon->attacked(opmon->getStatHP() / 8);
	    opTurn->confusedHurt = true;
	  }else{
	    opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.confused.attack.success.1", opName));
	    opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.confused.attack.success.2", std::vector<std::string*>()));
	  }
	}
      }
      //Checks if afraid
      if(opmon->afraid){
	opTurn->toPrintBefore.push_back(Utils::OpString("battle.status.afraid", opName));
	opmon->afraid = false;
	canAttack = false;
      }
      return canAttack;
    }
  }
}
