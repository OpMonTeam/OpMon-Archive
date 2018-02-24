#include "BattleCtrl.hpp"

namespace OpMon{
  namespace Controller{
    using namespace Model;
    
    BattleCtrl::BattleCtrl(OpTeam *one, OpTeam *two)
      : playerTeam(one), trainerTeam(two), atk(one->getOp(0)), def(two->getOp(0)){
      
    }

    GameStatus BattleCtrl::update() {
      turn();
      return GameStatus::CONTINUE;//TEMP
    }

    GameStatus BattleCtrl::checkEvent(sf::Event const & event){
      return GameStatus::CONTINUE;
    }
    
    bool BattleCtrl::turn(){
      return false;
      //Modify atkTurn and defTurn, and calculate the turn of each opmon
    }
  }
}
